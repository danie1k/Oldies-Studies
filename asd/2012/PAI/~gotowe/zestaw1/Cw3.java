import java.util.Scanner;

/*
 * Napisz program losujacy liczbe z zakresu 0-100. 
 * Nastepnie program pyta sie uzytkownika, co to za liczba. 
 * Jezeli uzytkownik nie zgadl, dowiaduje sie czy wylosowana 
 * liczba jest wieksza czy mniejsza od podanej. Jezeli zgadl,
 * dowiaduje sie ile wykonal prob i jest pytany o ochote do dalszej gry.
 */

public class Cw3 {

	public static void main(String[] args) {

		int min = 0, max = 100, counter = 0, shot = 0;
		boolean hit = false, game = true, question = true;
		String play;

		Scanner in = new Scanner(System.in);
		int rand = 0;

		while (game) {
			counter = 0;
			shot = 0;
			hit = false;
			question = true;

			rand = min + (int) (Math.random() * ((max - min) + 1));

			/*
			 * DEBUG
			 */
			System.out.println("DEBUG: " + rand);

			while (!hit) {
				System.out.print("[Próba " + (counter + 1)
						+ "] Zgadnij wylosowan¹ liczbê: ");

				try {
					shot = Integer.parseInt(in.nextLine());
					if (shot > 100)
						throw new IllegalArgumentException(
								"Podana liczba jest za du¿a, maksymalna mo¿liwa to 100");
					if (shot < 0)
						throw new IllegalArgumentException(
								"Podana liczba jest za ma³a, minimalna mo¿liwa to 0");

				} catch (NullPointerException n) {
					System.out.println("Musisz podaæ liczbê!");
					continue;
				} catch (NumberFormatException n) {
					System.out.println("Musisz podaæ prawid³ow¹ liczbê!");
					continue;
				} catch (IllegalArgumentException i) {
					System.out.println(i.getMessage());
					continue;
				}

				counter++;
				if (shot > rand) {
					System.out.println("Za du¿o!");
					continue;
				} else if (shot < rand) {
					System.out.println("Za ma³o!");
					continue;
				} else if (shot == rand)
					hit = true;
			}

			System.out.println("Zgad³eœ za " + counter
					+ " razem! Poszukiwana liczba to: " + rand + ".");

			while (question) {
				System.out.print("Czy chcesz graæ dalej (T - tak, N - nie)? ");
				try {
					play = in.nextLine();
					if (!play.contentEquals("T") && !play.contentEquals("t")
							&& !play.contentEquals("N")
							&& !play.contentEquals("n"))
						throw new IllegalArgumentException(
								"Odpowiedz prawid³ow¹ liter¹: T/N");
				} catch (IllegalArgumentException i) {
					System.out.println(i.getMessage());
					continue;
				}
				if (play.contentEquals("N") || play.contentEquals("n")) {
					game = false;
				}
				question = false;
			}
		}
		in.close();
	}
}