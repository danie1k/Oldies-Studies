/*
 * Napisz program czytajacy argumenty wywolania programu i konwertujacy je
 * do Integer. Zmodyfikuj program w ten sposob, aby kolejne argumenty byly
 * wspolczynikami wielomianu postaci Ax2+Bx+C=0. Policz pierwiastki tego
 * wielomianu.
 */

public class Cw1 {

	public static void main(String[] args) {
		int A = Integer.parseInt(args[0]);
		int B = Integer.parseInt(args[1]);
		int C = Integer.parseInt(args[2]);

		System.out.println("\nRownanie ma postac: " + A + "x^2 + " + B + "x + "
				+ C + " = 0\n");

		if (A == 0) {
			if (B != 0) {
				System.out
						.println("Rownanie jest liniowe i jego rozwiazanie wynosi: "
								+ (-C / B));
			} else {
				if (C != 0)
					System.out.println("Rownanie jest sprzeczne.");
				else
					System.out
							.println("Rownanie ma nieskonczenie wiele rozwiazan.");
			}
		} else {
			int delta = (B * B - (4 * A * C));
			System.out.println("Rownanie kwadratowe, delta = " + delta);

			System.out.println();

			if (delta < 0)
				System.out
						.println("Delta ujemna, rownanie nie ma rozwiazania!");
			else if (delta == 0) {
				double x = -B / (2 * A);
				System.out.println("Rownanie ma jedno rozwiazanie: x = " + x);
			} else {
				double x1 = (-B - Math.sqrt(delta)) / (2 * A);
				double x2 = (-B + Math.sqrt(delta)) / (2 * A);
				System.out.println("Rownanie ma 2 rozwiazania: x1 = " + x1
						+ "; x2 = " + x2);
			}
		}
	}
}