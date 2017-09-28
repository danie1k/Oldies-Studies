package pl.dmcs.main;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.net.InetAddress;

import pl.dmcs.email.EmailValidation;
import pl.dmcs.header.ShowRequestHeaders;
import pl.dmcs.link.LinkGetter;

/**
 * The Class CoreMain. Use to run project.
 */
public class CoreMain {

	/**
	 * The main method.
	 *
	 * @param args the arguments
	 * @throws Exception the exception
	 */
	public static void main(String[] args) throws Exception {

		String url = "www.yahoo.com";
		String emailFile = "emails.txt";
		String linksFile = "links.txt";
		String headerFile = "headerInfo.txt";

		EmailValidation email = new EmailValidation();
		PrintStream orgStream = null;
		PrintStream fileStream = null;
		try {
			// Saving the orginal stream
			orgStream = System.out;
			fileStream = new PrintStream(new FileOutputStream(emailFile,
					true));
			// Redirecting console output to file
			System.setOut(fileStream);
			email.mail();

		} catch (FileNotFoundException fnfEx) {
			System.out.println("Error in IO Redirection");
			fnfEx.printStackTrace();
		} catch (Exception ex) {
			// Gets printed in the file
			System.out.println("Some errors generated in emails");
			ex.printStackTrace();
		} finally {
			// Restoring back to console
			System.setOut(orgStream);
			// Gets printed in the console
			System.out.println("Redirecting emails to file: " + emailFile);

		}

		try {

			fileStream = new PrintStream(
					new FileOutputStream(linksFile, true));
			// Redirecting console output to file
			System.setOut(fileStream);

			LinkGetter linkGetter = new LinkGetter("LINKS GETTER");
			linkGetter.getLinks("http://" + url);

		} catch (FileNotFoundException fnfEx) {
			System.out.println("Error in IO Redirection");
			fnfEx.printStackTrace();
		} catch (Exception ex) {
			// Gets printed in the file
			System.out.println("some error occure in linkGetter");
			ex.printStackTrace();
		} finally {
			// Restoring back to console
			System.setOut(orgStream);
			// Gets printed in the console
			System.out.println("Redirecting links to file: " + linksFile);

		}

		try {

			fileStream = new PrintStream(new FileOutputStream(
					headerFile, true));
			// Redirecting console output to file
			System.setOut(fileStream);
			InetAddress address = InetAddress.getByName(url);
			System.out.println("Name: " + address.getHostName());
			System.out.println("Addr: " + address.getHostAddress());
			ShowRequestHeaders headerInfo = new ShowRequestHeaders();
			headerInfo.getHeaders("http://" + url);

		} catch (FileNotFoundException fnfEx) {
			System.out.println("Error in IO Redirection");
			fnfEx.printStackTrace();
		} catch (Exception ex) {
			// Gets printed in the file
			System.out.println("Error in headers");
			ex.printStackTrace();
		} finally {
			// Restoring back to console
			System.setOut(orgStream);
			// Gets printed in the console
			System.out.println("Redirecting headers to file: " +headerFile);

		}

	}
}
