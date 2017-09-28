<?php
class dkCrypt {

	private $defaultSalt = 'dkCryptSalt';

	/**
	 * Constructor
	 */
	function dkCrypt() {
		if(!extension_loaded('mcrypt')) {
			exit("MCrypt libary not present. Exiting.");
			return false;
		}

		$mcryptAlgorithms = mcrypt_list_algorithms();
		if(!in_array('rijndael-256', $mcryptAlgorithms) || !in_array('tripledes', $mcryptAlgorithms)) {
			exit("MCrypt required algorithms not present. Exiting.");
			return false;
		}
	}

	/**
	 * @param $input String
	 * @param $pass  String
	 * @param $type  String
	 * 
	 * @return String
	 * @return false   On error
	 */
	public function encrypt(&$input, $pass, $type = 'text') {
		if(empty($pass)) return false;
		if(gettype($input) != 'string') return false;

		$input = @serialize($input);

		if(!($tdInner = mcrypt_module_open('rijndael-256', '', 'cbc', ''))) return false;
		if(!($tdOuter = mcrypt_module_open('tripledes', '', 'cbc', '')))    return false;

		if(!($ivInner = mcrypt_create_iv(32, MCRYPT_RAND))) return false;
		if(!($ivOuter = mcrypt_create_iv(8, MCRYPT_RAND)))  return false;

		$keyInner = base64_encode($pass);
		$keyOuter = $this->hashPassword($pass, $this->defaultSalt, 24);

		$mgi = mcrypt_generic_init($tdInner, $keyInner, $ivInner);
		if( ($mgi < 0) || ($mgi === false)) return false;

		$mgi = mcrypt_generic_init($tdOuter, $keyOuter, $ivOuter);
		if( ($mgi < 0) || ($mgi === false)) return false;

		// Inner encryption
		if(!($input  = mcrypt_generic($tdInner, $input))) return false;

		$sticky = $this->hashPassword($input, $pass, 32);
		$input  = $ivInner.$input.$sticky;
		// Outer encryption
		if(!($input  = mcrypt_generic($tdOuter, $input))) return false;

		if(!(mcrypt_generic_deinit($tdInner))) return false;
		if(!(mcrypt_generic_deinit($tdOuter))) return false;
		if(!(mcrypt_module_close($tdInner)))   return false;
		if(!(mcrypt_module_close($tdOuter)))   return false;

		return $ivOuter.$input;
	}

	/**
	 * @param $input String
	 * @param $pass  String
	 * @param $type  String
	 *
	 * @return String
	 * @return false   On error
	 */
	public function decrypt(&$input, $pass) {
		if(empty($pass)) return false;
		if(gettype($input) != 'string') return false;

		if(!($tdInner = mcrypt_module_open('rijndael-256', '', 'cbc', ''))) return false;
		if(!($tdOuter = mcrypt_module_open('tripledes', '', 'cbc', '')))    return false;

		$keyInner = base64_encode($pass);
		$keyOuter = $this->hashPassword($pass, $this->defaultSalt, 24);

		$ivOuter  = substr($input, 0, 8);
		$output   = substr($input, 8);

		$mgi = mcrypt_generic_init($tdOuter, $keyOuter, $ivOuter);
		if( ($mgi < 0) || ($mgi === false)) return false;

		// Outer decryption
		if(!($output = mdecrypt_generic($tdOuter, $output))) return false;

		$ivInner  = substr($output, 0, 32);

		$mgi = mcrypt_generic_init($tdInner, $keyInner, $ivInner);
		if( ($mgi < 0) || ($mgi === false)) return false;


		$checksum = substr($output, strlen($output)-32);
		$output   = substr($output, 32, strlen($output)-64);
		$sticky   = $this->hashPassword($output, $pass, 32);

		if($checksum !== $sticky) return false;

		// Inner decryption
		if(!($output = mdecrypt_generic($tdInner, $output))) return false;

		if(!(mcrypt_generic_deinit($tdInner))) return false;
		if(!(mcrypt_generic_deinit($tdOuter))) return false;
		if(!(mcrypt_module_close($tdInner)))   return false;
		if(!(mcrypt_module_close($tdOuter)))   return false;

		return unserialize($output);
	}

	/**
	 * @param $fileUploadedPath String
	 *
	 * @return String
	 * @return false   On error
	 */
	public function openFile($fileUploadedPath){
		$ret = @file_get_contents($fileUploadedPath);
		return strlen($ret) ? $ret : false;
 	}

	/**
	 * @param $fileInput String
	 * @param $fileNam   String
	 */
	public function saveFile(&$fileInput, $fileName = 'dkcrypt'){
		header('Pragma: public');
		header('Expires: 0');
		header('Cache-Control: must-revalidate, post-check=0, pre-check=0');
		header('Content-Type: application/force-download; charset=utf-8');
		header('Content-Type: application/octet-stream; charset=utf-8');
		header('Content-Type: application/download; charset=utf-8');
		header('Content-Disposition: attachment; filename="'.$fileName.'";');
		header('Content-Transfer-Encoding: binary');
		echo $fileInput;
		exit;
	}

	/**
	 * @param  $text String
	 * @return String
	 */
	public function check_plain($text){
	  return htmlspecialchars($text, ENT_QUOTES, 'UTF-8');
	}

	/**
	 * @param  $input String Input data to encode
	 * @return String base64 encoded string
	 */
	public function encode(&$input){
		return base64_encode($input);
	}

	/**
	 * @param  $input String Input string to encode
	 * @return String base64 decoded data
	 */
	public function decode(&$input){
		return base64_decode($input);
	}

	/**
	 * @param $password   String
	 * @param $salt       String
	 * @param $key_length Integer
	 * @param $count      Integer
	 * @param $algorithm  String
	 *
	 * @return String
	 */
	public function hashPassword($password, $salt, $key_length, $count = 1000, $algorithm = 'sha256'){
		return $this->pbkdf2($algorithm, $password, $salt, $count, $key_length);
	}

	 /* SOURCE: https://defuse.ca/php-pbkdf2.htm
	  * 
     * PBKDF2 key derivation function as defined by RSA's PKCS #5: https://www.ietf.org/rfc/rfc2898.txt
     * $algorithm - The hash algorithm to use. Recommended: SHA256
     * $password - The password.
     * $salt - A salt that is unique to the password.
     * $count - Iteration count. Higher is better, but slower. Recommended: At least 1024.
     * $key_length - The length of the derived key in BYTES.
     * Returns: A $key_length-byte key derived from the password and salt (in binary).
     *
     * Test vectors can be found here: https://www.ietf.org/rfc/rfc6070.txt
     */
    private function pbkdf2($algorithm, $password, $salt, $count, $key_length)
    {
        $algorithm = strtolower($algorithm);
        if(!in_array($algorithm, hash_algos(), true))
            die('PBKDF2 ERROR: Invalid hash algorithm.');
        if($count <= 0 || $key_length <= 0)
            die('PBKDF2 ERROR: Invalid parameters.');

        // number of blocks = ceil(key length / hash length)
        $hash_length = strlen(hash($algorithm, "", true));
        $block_count = $key_length / $hash_length;
        if($key_length % $hash_length != 0)
            $block_count += 1;

        $output = "";
        for($i = 1; $i <= $block_count; $i++)
        {
            $output .= $this->pbkdf2_f($password, $salt, $count, $i, $algorithm, $hash_length);
        }

        return substr($output, 0, $key_length);
    }

    /*
     * The pseudorandom function used by PBKDF2.
     * Definition: https://www.ietf.org/rfc/rfc2898.txt
     */
    private function pbkdf2_f($password, $salt, $count, $i, $algorithm, $hash_length)
    {
        //$i encoded as 4 bytes, big endian.
        $last = $salt . chr(($i >> 24) % 256) . chr(($i >> 16) % 256) . chr(($i >> 8) % 256) . chr($i % 256);
        $xorsum = "";
        for($r = 0; $r < $count; $r++)
        {
            $u = hash_hmac($algorithm, $last, $password, true);
            $last = $u;
            if(empty($xorsum))
                $xorsum = $u;
            else
            {
                for($c = 0; $c < $hash_length; $c++)
                {
                    $xorsum[$c] = chr(ord(substr($xorsum, $c, 1)) ^ ord(substr($u, $c, 1)));
                }
            }
        }
        return $xorsum;
    }
}

?>
