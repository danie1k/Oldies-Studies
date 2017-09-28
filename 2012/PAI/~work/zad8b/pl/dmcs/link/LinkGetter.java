package pl.dmcs.link;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * The Class LinkGetter.
 */
public class LinkGetter  {

	/** The htmltag. */
	private Pattern htmltag;

	/** The link. */
	private Pattern link;

	/** The root. */
	private final String root;

	/**
	 * Instantiates a new link getter.
	 *
	 * @param root the root
	 */
	public LinkGetter(String root) {
		this.root = root;
		htmltag = Pattern.compile("]*href=\"[^>]*>(.*?)");
		link = Pattern.compile("href=\"[^>]*\">");
	}

	/**
	 * Gets the links.
	 *
	 * @param url the url
	 * @return the links
	 */
	public List getLinks(String url) {
		List<String> links = new ArrayList<String>();
		try {
			BufferedReader bufferedReader = new BufferedReader(
					new InputStreamReader(new URL(url).openStream()));
			String s;
			StringBuilder builder = new StringBuilder();
			while ((s = bufferedReader.readLine()) != null) {
				builder.append(s);
			}

			Matcher tagmatch = htmltag.matcher(builder.toString());
			while (tagmatch.find()) {
				Matcher matcher = link.matcher(tagmatch.group());
				matcher.find();
				String link = matcher.group().replaceFirst("href=\"", "").replaceAll("\">", "");
				if (valid(link)) {
					System.out.println(link);
					links.add(makeAbsolute(url, link));
				}
			}
		} catch (MalformedURLException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return links;
	}

	/**
	 * Valid.
	 *
	 * @param s the s
	 * @return true, if successful
	 */
	private boolean valid(String s) {
		if (s.matches("javascript:.*|mailto:.*")) {
			return false;
		}
		return true;
	}

	/**
	 * Make absolute.
	 *
	 * @param url the url
	 * @param link the link
	 * @return the string
	 */
	private String makeAbsolute(String url, String link) {
		if (link.matches("http://.*")) {
			return link;
		}
		if (link.matches("/.*") && url.matches(".*$[^/]")) {
			return url + "/" + link;
		}
		if (link.matches("[^/].*") && url.matches(".*[^/]")) {
			return url + "/" + link;
		}
		if (link.matches("/.*") && url.matches(".*[/]")) {
			return url + link;
		}
		if (link.matches("/.*") && url.matches(".*[^/]")) {
			return url + link;
		}
		throw new RuntimeException("Cannot make the link absolute. Url: " + url
				+ " Link " + link);
	}
}
