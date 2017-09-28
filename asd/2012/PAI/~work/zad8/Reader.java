import java.util.List;
import java.util.ArrayList;
import java.util.regex.*;
import java.io.*;

public class Reader {
	
	private FileOutputStream out;
	private Pattern href, mail;
	private Matcher m;
	private PrintStream p;
	private List<String> links,mails;
	
	public Reader(){
		this.href = Pattern.compile("href=\"(http|https)://[^>@]*\"");
		
		this.mail = Pattern.compile("href=\"mailto:[_A-Za-z0-9-]+(\\.[_A-Za-z0-9-]+)" +
				"*@[A-Za-z0-9]+(\\.[A-Za-z0-9]+)*(\\.[A-Za-z]{2,})\"");
		this.links=new ArrayList<String>();
		this.links.add("Linki:");
		this.mails=new ArrayList<String>();
		this.mails.add("Maile:");
		try {
			this.out = new FileOutputStream("zapis.txt");
			this.p = new PrintStream(this.out);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	
	public void czytaj(String line){
				this.m = this.href.matcher(line);
				while(this.m.find()){
					String sub;
					sub = line.substring(this.m.start(), this.m.end());
					this.links.add(this.findLink(sub));
				}
				this.m = this.mail.matcher(line);
				while(this.m.find()){
					String sub;
					sub = line.substring(this.m.start(), this.m.end());
					this.mails.add(this.findLink(sub).substring(7));
				}

	}
	
	private String findLink(String skad){
		
		return skad.substring(skad.indexOf('\"')+1, skad.lastIndexOf('\"'));
		
		

	}
	
	public void zapiszLinki(){
		for(int i =0;i<this.links.size();i++)this.zapisz(this.links.get(i));
		this.zapisz("");
		for(int i =0;i<this.mails.size();i++)this.zapisz(this.mails.get(i));
	}
	
	public void zapisz(String cos){
		
		this.p.println(cos);
		
		
        
	}
	
}
