import java.net.ServerSocket;
import java.net.Socket;

public class Monitor extends Thread {
	private int PORT;
	private int zlicz = 0;

	public Monitor(String port) {
		this.PORT = Integer.parseInt(port.trim());
	}

	public void run() {

		System.out.println("Serwer uruchmiony na porcie "+ this.PORT +". Czeka na po³¹czenia...");
		while (true) {
			try {
				ServerSocket server = new ServerSocket(this.PORT);
				Socket client = server.accept();

				System.out.println("<klient "+ zlicz+ "> Pod³¹czony!");
				new ObslugaKlienta(client, zlicz++).start();

			} catch (Exception e) {
			}
		}
	}
}
