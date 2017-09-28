package pl.dmcs.header;
import java.io.IOException;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.List;
import java.util.Map;
import java.util.Set;

/**
 * The Class ShowRequestHeaders.
 */
public class ShowRequestHeaders {

	/**
	 * Gets the headers from website.
	 *
	 * @param www the www
	 * @return the headers
	 * @throws IOException Signals that an I/O exception has occurred.
	 */
	public void getHeaders(String www) throws IOException {
		URL url = new URL(www);
	 HttpURLConnection httpCon = (HttpURLConnection) url.openConnection();

	    Map> hdrs = httpCon.getHeaderFields();
	    Set hdrKeys = hdrs.keySet();

	    for (String k : hdrKeys)
	      System.out.println("Key: " + k + "  Value: " + hdrs.get(k));
  }
}