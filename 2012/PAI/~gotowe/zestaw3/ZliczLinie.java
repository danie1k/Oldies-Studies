import java.io.*;

public class ZliczLinie extends Thread  {
	private String plik;

	
	public ZliczLinie(String filePath) {
		this.plik = filePath;
	}

	public void run() {
		BufferedReader reader;
		try {
			reader = new BufferedReader(new FileReader(this.plik));
			int lines = 0;
			while (reader.readLine() != null) lines++;
			reader.close();
			System.out.println("Zliczono " + lines + " linii w pliku: " + this.plik);
			
			//sleep(1000);

		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
