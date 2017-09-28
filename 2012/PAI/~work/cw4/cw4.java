package cw4;

import java.io.*;
import java.nio.*;
import java.nio.channels.FileChannel;
import java.nio.charset.Charset;

/* 
 * Napisz program losujacy 1000 znakow i zapisz je do pliku, 
 * a nastepnie odczytaj pliku i wypisz na ekran. Utworz dwie rozne pary 
 * procedur zapisujaco/odczytujacych, raz korzystajac z pakietu java.io 
 * a drugi raz z pakietu java.nio. Porownaj szybkosc zapisu i odczytu, 
 * wynik wypisz na ekranie.
 */

public class cw4 {

	public static void main(String[] args) {
		int min = 33, max = 126, i = 0;
		int rand = 0;
		String znaki = "";

		for(i = 0; i < 1000; i++){
			rand = min + (int) (Math.random() * ((max - min) + 1));
			znaki += (char)rand;
		}
		System.out.println("DEBUG: "+znaki);
		fileWriteIO(znaki);
		System.out.println("FREAD: "+fileReadIO());
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

	public static String fileReadIO() {
		String out = "";
		try {
			FileInputStream fstream = new FileInputStream("out.txt");
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			String strLine;
			while ((strLine = br.readLine()) != null) {
				out += strLine+"\r\n";
			}
			in.close();
		} catch (Exception e) {// Catch exception if any
			System.err.println("Error: " + e.getMessage());
		}
		return out;
	}

	public static void fileWriteNIO(String val) {
		FileOutputStream fout = null;
		try {
			fout = new FileOutputStream("out2.txt");
			FileChannel fc = fout.getChannel();
			ByteBuffer buffer = ByteBuffer.allocate(1024);

			for (int i = 0; i < val.length(); ++i) {
				buffer.put(val.getBytes());
			}
			buffer.flip();
			fc.write(buffer);
			fc.close();
		} catch (FileNotFoundException e) {
			System.err.println("Error: " + e.getMessage());
		} catch (IOException i) {
			System.err.println("Error: " + i.getMessage());
		}

	}

	public void fileReadNIO(){
		Charset charset = Charset.forName("US-ASCII");
		try (BufferedReader reader = Files.newBufferedReader(file, charset)) {
		    String line = null;
		    while ((line = reader.readLine()) != null) {
		        System.out.println(line);
		    }
		} catch (IOException x) {
		    System.err.format("IOException: %s%n", x);
		}
		
	}
	
}
