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
public class Cw2 {

	public static void main(String[] args) {

		String cutText = "";
		int cutFrom = 0, cutTo = 0;
		boolean err = false;

		try {
			cutText = args[0];
			if (cutText.isEmpty())
				throw new IllegalArgumentException("cutText");
		} catch (IllegalArgumentException e) {
			if (e.getMessage() == "cutText") {
				System.out.println("B£¥D: cutText Empty");
				err = true;
			}
		} catch (IndexOutOfBoundsException i) {
			System.out.println("B£¥D: Index Out Of Bounds (cutText)");
			err = true;
		}

		try {
			cutFrom = Integer.parseInt(args[1]);
		} catch (NumberFormatException e) {
			System.out.println("B£¥D: Number Format (cutFrom)");
			err = true;
		} catch (NullPointerException n) {
			System.out.println("B£¥D: Null Pointer (cutFrom)");
			err = true;
		} catch (IndexOutOfBoundsException i) {
			System.out.println("B£¥D: Index Out Of Bounds (cutFrom)");
			err = true;
		}

		try {
			cutTo = Integer.parseInt(args[2]);
		} catch (NumberFormatException e) {
			System.out.println("B£¥D: Number Format (cutTo)");
			err = true;
		} catch (NullPointerException n) {
			System.out.println("B£¥D: Null Pointer (cutTo)");
			err = true;
		} catch (IndexOutOfBoundsException i) {
			System.out.println("B£¥D: Index Out Of Bounds (cutTo)");
			err = true;
		}

		if (cutFrom < 0) {
			System.out.println("B£¥D: Number Negative (cutFrom)");
			err = true;
		}

		if (cutTo < 0) {
			System.out.println("B£¥D: Number Negative (cutTo)");
			err = true;
		}

		if (cutTo < cutFrom) {
			System.out.println("B£¥D: Substring Out Of Range");
			err = true;
		}

		if (!err) {
			System.out.println("Substring(\"" + cutText + "\", " + cutFrom
					+ ", " + cutTo + "): ");
			System.out.println(cutText.substring(cutFrom, cutTo));
		}
	}
}
