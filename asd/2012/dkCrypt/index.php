<?php
	ob_start();
	require_once 'php/dkCrypt.php';

	if(isset($_POST['encryptInputSubmit'])) {
		$encryption = new dkCrypt();
		$error = false;
		$performedOperation = 'Input encryption';

		if(empty($_POST['encryptInput'])) {
			$cryptResult = 'Input text empty.';
			$error = true;
		}

		$password = $encryption->check_plain($_POST['encryptInputPassword']);
		if(!$error && (($password !== $_POST['encryptInputPassword']) || empty($password))) {
			$cryptResult = 'Something\'s wrong with password.';
			$error = true;
		}

		if(!$error && !($result = $encryption->encrypt($_POST['encryptInput'], $password))) {
			$cryptResult = 'Encryption failed.';
			$error = true;
		}

		if(!$error) {

			if(isset($_POST['encryptInputEncode'])) {
				$cryptResult = $encryption->encode($result);
			}
			else {
				$cryptResult = &$result;
			}

			if(isset($_POST['encryptInputDownload'])) {
				$encryption->saveFile($cryptResult);
			}
		}
	}

	if(isset($_POST['decryptInputSubmit'])) {
		$decryption = new dkCrypt();
		$error = false;
		$performedOperation = 'Input decryption';


		if(empty($_POST['decryptInput'])) {
			$cryptResult = 'Input text empty.';
			$error = true;
		}

		$password = $decryption->check_plain($_POST['decryptInputPassword']);
		if(!$error && (($password !== $_POST['decryptInputPassword']) || empty($password))) {
			$cryptResult = 'Something\'s wrong with password.';
			$error = true;
		}

		if(!$error && isset($_POST['decryptInputEncoded'])) {
			$input = $decryption->decode($_POST['decryptInput']);
		}
		else {
			$input = $_POST['decryptInput'];
		}

		if(!$error && !($result = $decryption->decrypt($input, $password))) {
			$cryptResult = 'Decryption failed. Maybe you entered wrong password?';
			$error = true;
		}

		if(!$error) {
			if(isset($_POST['decryptInputDownload'])) {
				$decryption->saveFile($result, 'decrypted.txt');
			}
			else {
				$cryptResult = &$result;
			}
		}
	}

	if(isset($_POST['encryptUploadSubmit'])) {
		$encryption = new dkCrypt();
		$error = false;
		$performedOperation = 'File upload encryption';

		switch($_FILES['encryptUploadFile']['error']) {
			case UPLOAD_ERR_OK: break;
			case UPLOAD_ERR_INI_SIZE:
			case UPLOAD_ERR_FORM_SIZE:
				$cryptResult = 'File not uploaded. It is too big.';
				$error = true;
				break;
			case UPLOAD_ERR_NO_FILE:
				$cryptResult = 'File not uploaded. File not present.';
				$error = true;
				break;
			default:
				$cryptResult = 'File uploading error.';
				$error = true;
		};

		$password = $encryption->check_plain($_POST['encryptUploadPassword']);
		if(!$error && (($password !== $_POST['encryptUploadPassword']) || empty($password))) {
			$cryptResult = 'Something\'s wrong with password.';
			$error = true;
		}

		if(!$error && !($result = $encryption->openFile($_FILES['encryptUploadFile']['tmp_name']))) {
			$cryptResult = 'File opening error.';
			$error = true;
		}

		if(!$error && !($result = $encryption->encrypt($result, $password))) {
			$cryptResult = 'Encryption failed.';
			$error = true;
		}

		if(!$error) {
			if(isset($_POST['encryptUploadEncode'])) {
				$cryptResult = $encryption->encode($result);
			}
			else {
				$cryptResult = &$result;
			}

			if(isset($_POST['encryptUploadDownload'])) {
				$encryption->saveFile($cryptResult, $_FILES['encryptUploadFile']['name'].'.dkcrypt');
			}
		}
	}


	if(isset($_POST['decryptUploadSubmit'])) {
 		$decryption = new dkCrypt();
		$error = false;
		$performedOperation = 'File upload decryption';

		switch($_FILES['decryptUploadFile']['error']) {
			case UPLOAD_ERR_OK: break;
			case UPLOAD_ERR_INI_SIZE:
			case UPLOAD_ERR_FORM_SIZE:
				$cryptResult = 'File not uploaded. It is too big.';
				$error = true;
				break;
			case UPLOAD_ERR_NO_FILE:
				$cryptResult = 'File not uploaded. File not present.';
				$error = true;
				break;
			default:
				$cryptResult = 'File uploading error.';
				$error = true;
		};

		$password = $decryption->check_plain($_POST['decryptUploadPassword']);
		if(!$error && (($password !== $_POST['decryptUploadPassword']) || empty($password))) {
			$cryptResult = 'Something\'s wrong with password.';
			$error = true;
		}
		

		if(!$error && !($result = $decryption->openFile($_FILES['decryptUploadFile']['tmp_name']))) {
			$cryptResult = 'File opening error.';
			$error = true;
		}

		if(!$error && isset($_POST['decryptUploadEncoded'])) {
			$result = $decryption->decode($result);
		}


		if(!$error && !($result = $decryption->decrypt($result, $password))) {
			$cryptResult = 'Decryption failed. Maybe you entered wrong password?';
			$error = true;
		}


		if(!$error) {
			if(isset($_POST['decryptUploadDownload'])) {
				$decryption->saveFile($result, 'decrypted');
			}
			else {
				$cryptResult = &$result;
			}
		}
	}

?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" 
	"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd"> 
<html xmlns="http://www.w3.org/1999/xhtml" dir="ltr" lang="pl" xml:lang="pl">
<head>
	<title>PHP + MCrypt Project</title>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
	<style type="text/css" media="screen">
	@import 'css/style.css' ;
	@import 'css/hot-sneaks.css';
	</style>
	<script type="text/javascript" src="js/jquery-1.7.2.min.js"></script>
	<script type="text/javascript" src="js/jquery-ui-1.8.20.js"></script>
	<script type="text/javascript" src="js/script.js"></script>
</head>
<body>

<h1>PHP + MCrypt Project</h1>

<div id="main">
	<ul>
		<?php if(!empty($cryptResult)): ?><li><a href="#results">RESULTS</a></li><?php endif; ?>
		<li><a href="#encrypt-from-input">Encrypt from input</a></li>
		<li><a href="#encrypt-from-upload">Encrypt from upload</a></li>
		<li><a href="#decrypt-from-input">Decrypt from input</a></li>
		<li><a href="#decrypt-from-upload">Decrypt from upload</a></li>
		<li><a href="#about">About</a></li>
	</ul>

	<?php if(!empty($cryptResult)): ?><div id="results" class="tabBody">
		<h3><?php echo $performedOperation; ?> results:</h3>
		<?php if($error): ?>
		<div class="ui-widget">
			<div class="ui-state-error ui-corner-all" style="padding: 0 .7em;">
				<p><span class="ui-icon ui-icon-alert" style="float: left; margin-right: .3em;"></span>
				<strong>Error:</strong> <?php echo $cryptResult; ?> Try again.</p>
			</div>
		</div>
		<?php else: ?>
		<p class="formRow last">
			<label for="encryptInput">Your encrypted data:</label>
			<textarea cols="70" rows="10" wrap="off" readonly="readonly"><?php echo $cryptResult; ?></textarea>
		</p>
		<p class="formSubmit">
			<input type="button" onclick="window.location='<?php echo $_SERVER['PHP_SELF']; ?>';" class="button" value="&laquo; Go back" />
		</p>
		<?php endif; ?>
	</div><?php endif; ?>
	<div id="encrypt-from-input" class="tabBody">
		<form id="encryptInput" action="<?php echo $_SERVER['PHP_SELF'].'#results'; ?>" method="POST">
		<h3>Encrypt from input</h3>
		<p class="formRow last">
			<label for="encryptInput">Enter text to encrypt:</label>
			<textarea cols="70" rows="10" wrap="off" name="encryptInput" id="encryptInput"></textarea>
		</p>
		<h3>Options:</h3>
		<p class="formRow">
			<label for="encryptInputPassword">Password:</label>
			<input type="password" name="encryptInputPassword" id="encryptInputPassword" size="70" maxlength="100" />
			<em><input type="checkbox" name="unhidePassword_encryptInputPassword" id="unhidePassword[encryptInputPassword]" /><label for="unhidePassword[encryptInputPassword]">Unhide password</label></em>
		</p>
		<p class="formRow">
			<label for="encryptInputDownload">Download result:</label>
			<input type="checkbox" name="encryptInputDownload" id="encryptInputDownload" value="1" />
		</p>
		<p class="formRow last">
			<label for="encryptInputEncode">Encode result:</label>
			<input type="checkbox" name="encryptInputEncode" id="encryptInputEncode" value="1" />
		</p>
		<p class="formSubmit">
			<input type="submit" name="encryptInputSubmit" class="button" value="Encrypt!" /> <input type="reset" class="button" value="Reset form" />
		</p>
		</form>
	</div>
	<div id="encrypt-from-upload" class="tabBody">
		<form id="encryptUpload" action="<?php echo $_SERVER['PHP_SELF'].'#results'; ?>" method="POST" enctype="multipart/form-data">
		<h3>Encrypt from upload</h3>
		<p class="formRow">
			<label for="encryptUploadFile">File:</label>
				<input type="file" name="encryptUploadFile" id="encryptUploadFile" />
				<em>Max size of file upload is <?php echo ini_get('upload_max_filesize'); ?></em>
		</p>
		<p class="formRow">
			<label for="encryptUploadPassword">Password:</label>
			<input type="password" name="encryptUploadPassword" id="encryptUploadPassword" size="70" maxlength="100" />
			<em><input type="checkbox" name="unhidePassword_encryptUploadPassword" id="unhidePassword[encryptUploadPassword]" /><label for="unhidePassword[encryptUploadPassword]">Unhide password</label></em>
		</p>
		<p class="formRow">
			<label for="encryptUploadDownload">Download result:</label>
			<input type="checkbox" name="encryptUploadDownload" id="encryptUploadDownload" value="1" checked="checked" />
		</p>
		<p class="formRow last">
			<label for="encryptUploadEncode">Encode result:</label>
			<input type="checkbox" name="encryptUploadEncode" id="encryptUploadEncode" />
		</p>
		<p class="formSubmit">
			<input type="submit" name="encryptUploadSubmit" class="button" value="Encrypt!" /> <input type="reset" class="button" value="Reset form" />
		</p>
		</form>
	</div>
	<div id="decrypt-from-input" class="tabBody">
		<form id="decryptInput" action="<?php echo $_SERVER['PHP_SELF'].'#results'; ?>" method="POST">
		<h3>Decrypt from input</h3>
		<p class="formRow last">
			<label for="decryptInput">Enter text to decrypt:</label>
			<textarea cols="70" rows="10" wrap="off" name="decryptInput" id="decryptInput"></textarea>
		</p>
		<h3>Options:</h3>
		<p class="formRow">
			<label for="decryptInputPassword">Password:</label>
			<input type="password" name="decryptInputPassword" id="decryptInputPassword" size="70" maxlength="100" />
			<em><input type="checkbox" name="unhidePassword_decryptInputPassword" id="unhidePassword[decryptInputPassword]" /><label for="unhidePassword[decryptInputPassword]">Unhide password</label></em>
		</p>
		<p class="formRow last">
			<label for="decryptInputDownload">Download result:</label>
			<input type="checkbox" name="decryptInputDownload" id="decryptInputDownload" />
		</p>
		<p class="formRow">
			<label for="decryptInputEncoded">Is input encoded?:</label>
			<input type="checkbox" name="decryptInputEncoded" id="decryptInputEncoded" />
		</p>
		<p class="formSubmit">
			<input type="submit" name="decryptInputSubmit" class="button" value="Decrypt!" /> <input type="reset" class="button" value="Reset form" />
		</p>
		</form>
	</div>
	<div id="decrypt-from-upload" class="tabBody">
		<form id="decryptUpload" action="<?php echo $_SERVER['PHP_SELF'].'#results'; ?>" method="POST" enctype="multipart/form-data">
		<h3>Decrypt from upload</h3>
		<p class="formRow">
			<label for="decryptUploadFile ">File:</label>
				<input type="file" name="decryptUploadFile" id="decryptUploadFile" />
				<em>Max size of file upload is <?php echo ini_get('upload_max_filesize'); ?></em>
		</p>
		<p class="formRow">
			<label for="decryptUploadPassword">Password:</label>
			<input type="password" name="decryptUploadPassword" id="decryptUploadPassword" size="70" maxlength="100" />
			<em><input type="checkbox" name="unhidePassword_decryptUploadPassword" id="unhidePassword[decryptUploadPassword]" /><label for="unhidePassword[decryptUploadPassword]">Unhide password</label></em>
		</p>
		<p class="formRow last">
			<label for="decryptUploadDownload">Download result:</label>
			<input type="checkbox" name="decryptUploadDownload" id="decryptUploadDownload" value="1" checked="checked" />
		</p>
		<p class="formRow">
			<label for="decryptUploadEncoded">Is file encoded?:</label>
			<input type="checkbox" name="decryptUploadEncoded" id="decryptUploadEncoded" />
		</p>
		<p class="formSubmit">
			<input type="submit" name="decryptUploadSubmit" class="button" value="Decrypt!" /> <input type="reset" class="button" value="Reset form" />
		</p>
		</form>
	</div>
	<div id="about" class="tabBody">
		<h3>O projekcie</h3>
		<p>
			<strong>Autor:</strong>
			<blockquote>
				Daniel Kuruc,<br />
				Politechnika Łódzka<br />
				Wydział Elektrotechniki, Elektroniki, Informatyki i Automatyki<br /><br />
				Kierunek: Informatka<br />
				Tryb niestacjonarny<br />
				Semestr VI
			</blockquote>
		</p>
		<p>
			<strong>Opis: </strong>
			<blockquote>
				Projekt zrealizowany w ramach przedmiotu &quot;Podstawy krypotografii&quot;.<br />
				Prezentuje możliwości biblioteki MCrypt i jej przykładową implementację.
			</blockquote>
		</p>
		<p>
			<strong>Prawa autorskie: </strong>
			<blockquote>
				Projekt wykorzystuje bibliotekę MCrypt &lt;<a href="http://mcrypt.sourceforge.net/">mcrypt.sourceforge.net</a>&gt; dostępną na licencji <a href="http://www.gnu.org">GNU</a> <a href="http://www.gnu.org/copyleft/gpl.html">General Public License</a>;<br />
				bibliotekę jQuery &lt;<a href="http://jquery.com/">jquery.com</a>&gt; udostępnianą na licencjach <a href="http://github.com/jquery/jquery/blob/master/MIT-LICENSE.txt">MITe</a> oraz <a href="http://github.com/jquery/jquery/blob/master/GPL-LICENSE.txt">GPL</a>
				i bibliotekę jQuery UI &lt;<a href="http://jqueryui.com/">jqueryui.com</a>&gt; również dostępną na licencjach <a href="http://github.com/jquery/jquery/blob/master/MIT-LICENSE.txt">MITe</a> oraz <a href="http://github.com/jquery/jquery/blob/master/GPL-LICENSE.txt">GPL</a>.<br /><br />
				Pozostały kod PHP, CSS i JavaScript został stworzny całkowicie od podstaw przeze mnie.
			</blockquote>
		</p>
	</div>
</div>
<div class="footer">Copyright &copy;2012 <a href="mailto:daniel@kuruc.pl">Daniel Kuruc</a></div>

</body>
</html><?php ob_end_flush(); ?>