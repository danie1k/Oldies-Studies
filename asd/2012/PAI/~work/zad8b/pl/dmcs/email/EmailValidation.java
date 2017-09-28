package pl.dmcs.email;

import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.Serializable;
import java.net.URL;
import java.net.URLConnection;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * The Class EmailValidation.
 */
public class EmailValidation  implements Serializable{

	public EmailValidation() {
	}
	/**
	 * The main method. Get URL and searching for email
	 *
	 * @param args
	 *            the arguments
	 * @throws Exception
	 *             the exception
	 */
	public  void mail() throws Exception {
		int count = 0;
		URL yahoo = new URL("http://www.suebob.net/Terr2.html");
		URLConnection yc = yahoo.openConnection();
		BufferedReader in = new BufferedReader(new InputStreamReader(
				yc.getInputStream()));
		String input;
		while ((input = in.readLine()) != null) {// System.out.println(input);

			// String input = "www@sun.com";
			// Checks for email addresses starting with
			// inappropriate symbols like dots or @ signs.
			Pattern p = Pattern
					.compile("[a-zA-Z]*[0-9]*@[a-zA-Z]*\\.[a-zA-Z]*");
			Matcher m = p.matcher(input);

			if (m.find()) {
				count++;
				System.out.println(m.group());

				// System.out.println("mam ");
			} else {
				// System.err.println("Email addresses don't start");

			}
			StringBuffer sb = new StringBuffer();
			boolean result = m.find();
			boolean deletedIllegalChars = false;

			while (result) {
				deletedIllegalChars = true;
				m.appendReplacement(sb, "");
				result = m.find();
			}

			// Add the last segment of input to the new String
			m.appendTail(sb);

			input = sb.toString();

		}
		in.close();
		System.out.println("I found " + count + " emails");
	}
}