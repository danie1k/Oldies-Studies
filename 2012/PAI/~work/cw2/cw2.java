package cw2;

public class cw2 {
	/*
	 * Napisz program, ktory pobiera dwie liczby oraz lancuch znakow z wiersza
	 * polecen oraz wyswietla fragment podanego lancucha okreslony wprowadzonymi
	 * liczbami.
	 * 
	 * Na przyklad: java Substring Witaj 2 4
	 * 
	 * powinien wyswietlic: taj
	 * 
	 * Obsluz wszystkie mozliwe wyjatki, ktore moga wystapic w przypadku zlego
	 * zestawu argumentow.
	 */

	public static void main(String[] args) {

		String cutText = "";
		int cutFrom = 0, cutTo = 0;
		boolean err = false;

		try {
			cutText = args[0];
			if (cutText.isEmpty())
				throw new IllegalArgumentException("No Text Entered (cutText)");
		} catch (IllegalArgumentException e) {
			System.out.println("ERROR: No Text Entered (cutText)");
			err = true;
		} catch (IndexOutOfBoundsException i) {
			System.out.println("ERROR: Index Out Of Bounds (cutText)");
			err = true;
		}

		try {
			cutFrom = Integer.parseInt(args[1]);
		} catch (NumberFormatException e) {
			System.out.println("ERROR: Number Format (cutFrom)");
			err = true;
		} catch (NullPointerException n) {
			System.out.println("ERROR: Null Pointer (cutFrom)");
			err = true;
		} catch (IndexOutOfBoundsException i) {
			System.out.println("ERROR: Index Out Of Bounds (cutFrom)");
			err = true;
		}

		try {
			cutTo = Integer.parseInt(args[2]);
		} catch (NumberFormatException e) {
			System.out.println("ERROR: Number Format (cutTo)");
			err = true;
		} catch (NullPointerException n) {
			System.out.println("ERROR: Null Pointer (cutTo)");
			err = true;
		} catch (IndexOutOfBoundsException i) {
			System.out.println("ERROR: Index Out Of Bounds (cutTo)");
			err = true;
		}

		if (cutFrom < 0) {
			System.out.println("ERROR: Number Negative (cutFrom)");
			err = true;
		}

		if (cutTo < 0) {
			System.out.println("ERROR: Number Negative (cutTo)");
			err = true;
		}

		if (cutTo < cutFrom) {
			System.out.println("ERROR: Substring Out Of Range");
			err = true;
		}

		if(!err) 
			System.out.println("Substring(\""+cutText+"\", "+cutFrom+", "+cutTo+"): ");
			System.out.println(cutText.substring(cutFrom, cutTo));
	}
}
