import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

public class ObslugaKlienta extends Thread {
	Socket socket;
	int id;

	public ObslugaKlienta(Socket s, int numerKlienta) {
		this.socket = s;
		this.id = numerKlienta;
	}

	public void run() {
		try {
			BufferedReader in = new BufferedReader(new InputStreamReader(
					socket.getInputStream()));

			while (true) {
				try { socket.isConnected(); }
				catch (Exception e) { System.out.println("<Klient "+ id +"> Od³¹czony od serwera."); }

				String str = in.readLine();
				// out.println(echo);
				System.out.println("<Klient "+ id +"> " + str);
			}

		} catch (Exception e) {
			System.out.println("<Klient "+ id +"> Od³¹czony od serwera.");
		}
	}
}
