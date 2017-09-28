import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class Klient {
	public static void main(String[] args) {
		int PORT = Integer.parseInt(args[0].trim());

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String wyslijSerwerowi;
		PrintWriter out;

		try {
			Socket socket = new Socket("localhost", PORT);
			System.out.println("Po³¹czenie nawi¹zane: "+ socket.getOutputStream());

			System.out.print("Wpisz komunikat do wys³ania: ");
			wyslijSerwerowi = in.readLine();
			out = new PrintWriter(socket.getOutputStream());
			out.println(wyslijSerwerowi);
			out.flush();

			while (socket.isConnected()) {
				System.out.print("Wpisz komunikat do wys³ania: ");

				wyslijSerwerowi = in.readLine();
				out = new PrintWriter(socket.getOutputStream());
				out.println(wyslijSerwerowi);
				out.flush();
			}
			System.out.print("Serwer zerwa³ po³¹czenie.");
			socket.close();

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
