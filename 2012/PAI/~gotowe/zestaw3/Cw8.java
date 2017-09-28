import java.io.*;
import java.net.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/*
 * Napisz program laczacy sie ze strona podana jako argument wywolania programu 
 * i wypisujacy wszystkie znalezione na niej linki i adresy email wykorzystujac 
 * w tym celu wyrazenia regularne (pakiet java.util.regex). Oprocz tego program 
 * ma zapisac do pliku wszystkie parametry polaczenia, adres IP komputera 
 * na ktorym znajduje sie strona oraz naglowek strony (zawartosc sekcji <head>). 
 */

public class Cw8 {
	public static void main(String[] args) throws Exception {
		String uri = args[0].replaceAll("http://", "");
		String address = "";

		try {
			address = InetAddress.getByName(uri).getHostAddress();
		} catch (UnknownHostException e) {
			address = "Could not find " + uri;
		}

		URL myURL = new URL("http://" + uri);
		URLConnection myURLConnection = myURL.openConnection();
		myURLConnection.connect();

		BufferedReader in = new BufferedReader(new InputStreamReader(myURLConnection.getInputStream()));
		
		String inputLine;
		String pageBody = new String();

		while ((inputLine = in.readLine()) != null) {
			pageBody += inputLine;
		}
		in.close();

		Pattern URLpattern = Pattern.compile("((mailto\\:|(news|(ht|f)tp(s?))\\://){1}\\S+)\"");
		Matcher URLmatch = URLpattern.matcher(pageBody);
		
		while (URLmatch.find()) {
			System.out.println(URLmatch.group(1));
		}

		String output = "";
		
		output += uri + " IP: "+ address;

		output += "\n\n" + myURLConnection.getHeaderFields().toString().replaceAll(", ", ",\n");

		Pattern HEADpattern = Pattern.compile("<head>(.*?)</head>");
		Matcher HEADmatch = HEADpattern.matcher(pageBody);

		if (HEADmatch.find()) {
			output += "\n\n<head>\n" + HEADmatch.group(1).replaceAll(">", ">\n") + "\n";
		}

		fileWriteIO(output);
	}


	public static void fileWriteIO(String val) {
		try {
			FileWriter fstream = new FileWriter("out.txt");
			BufferedWriter out = new BufferedWriter(fstream);
			out.write(val);
			out.close();
		} catch (Exception e) {// Catch exception if any
			System.err.println("Error: " + e.getMessage());
		}

	}
}
