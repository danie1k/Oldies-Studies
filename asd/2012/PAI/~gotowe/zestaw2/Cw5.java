import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

/*
 * Napisz program proszacy o podanie 2 wektorow. 
 * Koniec wektora oznacza sie za pomoca wcisniecia klawisza enter. 
 * Jezeli podany ciag nie jest liczba, jest ignorowany. 
 * Nastepnie nalezy sprobowac dodac wektory, jezeli sa rownej dlugosci. 
 * Jezeli nie, sa, rzucany jest wlasny wyjatek WektoryRoznejDlugosciException, 
 * za pomoca ktorego mozna podac a nastepnie odczytac dlugosci tych wektorow. 
 * Jezeli sa rownej dlugosci, wynik dodawania zapisywany jest do pliku. 
 * Jezeli nie sa rownej dlugosci, uzytkownik jest proszony o ponowne wprowadzenie tych wektorow.
 */

public class Cw5 {

	public static void main(String[] args) {
		String tmp;

		boolean runProgram = true;
		String[] vector1in, vector2in;
		float[] vector1 = null, vector2 = null, suma = null;

		Scanner in = new Scanner(System.in);

		while (runProgram) {

			try {
				System.out
						.println("Podaj ci¹g liczb okreœlaj¹cych wektor 1, oddzielaj¹c je spacjami:");

				vector1in = in.nextLine().replaceAll("\\s+", " ").split(" ");
				if (vector1in.length > 0) {
					vector1 = new float[vector1in.length];
					for (int i = 0, j = 0; i < vector1in.length; i++) {
						if (vector1in[i].length() > 0) {
							vector1[j++] = Float.parseFloat(vector1in[i]);
							// System.out.println("DEBUG :"+vector1[(j-1)]);
						}
					}
					// System.out.println(Arrays.toString(vector1));
				} else
					throw new IllegalArgumentException(
							"Nie poda³eœ ¿adnych liczb!");
			} catch (NumberFormatException e) {
				System.out
						.println("Podany ci¹g liczb ma nieopoprawny format. Ignorowanie.");
				vector1in = null;
				vector1 = null;
			} catch (IllegalArgumentException i) {
				System.out.println(i.getMessage());
			}

			try {
				System.out
						.println("Podaj ci¹g liczb okreœlaj¹cych wektor 2, oddzielaj¹c je spacjami:");

				vector2in = in.nextLine().replaceAll("\\s+", " ").split(" ");
				if (vector2in.length > 0) {
					vector2 = new float[vector2in.length];
					for (int i = 0, j = 0; i < vector2in.length; i++) {
						tmp = vector2in[i].replaceAll("\\s+", "");
						if (tmp.length() > 0) {
							vector2[j++] = Float.parseFloat(vector2in[i]
									.replaceAll("\\s+", ""));
							// System.out.println("DEBUG :"+vector2[(j-1)]);
						}
					}
				} else
					throw new IllegalArgumentException(
							"Nie poda³eœ ¿adnych liczb!");
			} catch (NumberFormatException e) {
				System.out
						.println("Podany ci¹g liczb ma nieopoprawny format. Ignorowanie.");
				vector2in = null;
				vector2 = null;
			} catch (IllegalArgumentException i) {
				System.out.println(i.getMessage());
			}

			try {
				// System.out.println(Arrays.toString(vector1));
				// System.out.println(Arrays.toString(vector2));
				if (porownajDlugosci(vector1, vector2)) {
					suma = new float[vector1.length];
					System.out.print("Suma wektorow: ");
					for (int i = 0; i < vector1.length; i++) {
						suma[i] = vector1[i] + vector2[i];
						System.out.print(suma[i] + " ");
					}
					fileWriteIO("Suma wektorow: "+Arrays.toString(suma));
					runProgram = false;
				} else {
					break;
				}

			} catch (WektoryRoznejDlugosciException rd) // but it is caught here
			{
				System.out.println(rd.getError());
			}
		}
		in.close();
	}

	private static boolean porownajDlugosci(float[] v1, float[] v2)
			throws WektoryRoznejDlugosciException {
		boolean ret;
		if (v1.length == v2.length) {
			ret = true;
		} else {
			ret = false;
			throw new WektoryRoznejDlugosciException(
					"Wektory s¹ ró¿nej d³ugoœci! WprowadŸ ponownie parametry wektorów.");
		}
		return ret;
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
}