import java.net.InetAddress;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;
import java.net.UnknownHostException;
import java.io.*;


public class Main {

	
	public static void main(String[] args) {
		Reader r = new Reader();
		URL strona=null;
		BufferedReader in = null;
		if(args.length>0){
			try {
				strona = new URL(args[0]);
			} catch (MalformedURLException e) {
				System.out.println("Problem z protokolem");
				e.printStackTrace();
				System.exit(0);
			}
			URLConnection con=null;
			try {
				con = strona.openConnection();
			} catch (IOException e) {
				System.out.println("Problem z otworzeniem polaczenia");
				e.printStackTrace();
			}
			
			try {
				in = new BufferedReader(new InputStreamReader(con.getInputStream()));
			} catch (IOException e) {
				System.out.println("Problem z otwarciem strony");
				e.printStackTrace();
				System.exit(0);
			}
			
			String input="";
			for(int i=0;;i++){
				
				String name = con.getHeaderFieldKey(i);
	            String value = con.getHeaderField(i);

	            if (name == null && value == null) break;

	            if (name == null)
	            {
	              r.zapisz("Server HTTP version, Response code:");
	              r.zapisz(value);
	              r.zapisz("");
	            }
	            else
	            {
	              r.zapisz(name + "=" + value);
	            }
				
			}
			r.zapisz("");
			try {
				
				InetAddress ipaddress = InetAddress.getByName(strona.getHost());
				r.zapisz("Adres IP: "+ipaddress.getHostAddress());
			} catch (UnknownHostException e1) {
				e1.printStackTrace();
				System.exit(0);
			}
			r.zapisz("");
			r.zapisz("Header:");
			try {
				boolean hasHead=false;
				while((input=in.readLine())!=null){
					if(input.matches("</head>")) hasHead=false;
					if(hasHead) r.zapisz(input);
					else r.czytaj(input);
					if(input.matches("<head>")) hasHead=true;
				}
				r.zapiszLinki();
			} catch (IOException e) {
				System.out.println("Problem z odczytem");
				e.printStackTrace();
			}finally{
				try {
					in.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
		
	}

}
