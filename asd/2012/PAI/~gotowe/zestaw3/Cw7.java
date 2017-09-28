import java.io.*;

/*
 * Napisz program, ktory pobiera liste plikow z linii polecen 
 * i wyswietla liczbe wierszy kazdego z nich. Program powinien 
 * utworzyc jeden watek dla kazdego z plikow i uzyc tych watkow 
 * do zliczenia liczby wierszy kazdego z plikow rownoczenie. 
 * Utworz wersje programu, ktora odczytuje pliki nie jednoczesnie 
 * a sekwencyjnie. Porownaj wydajnosc wielowatkowego i jednowatkowego 
 * programu uzywajac System.currentTimeMillis() do okreslenia czasu 
 * wykonania. Porownania dokonaj dla dwoch, trzech i pieciu plikow. 
 */

public class Cw7 {

	public static void main(String[] args) throws Exception {
		long czasPracy = 0;
		File dir = new File("C:\\");

		// Pobieranie listy plików mo¿liwych do odczytania
		FileFilter fileFilter = new FileFilter() {
			public boolean accept(File dir) {
				return dir.isFile() && dir.canExecute();
			}
		};
		File[] files = dir.listFiles(fileFilter);

		czasPracy = System.currentTimeMillis();
		for (int i = 0; i < files.length; i++) {
			String plik = files[i].toString();

			ZliczLinie watekZliczajacy = new ZliczLinie(plik);
			watekZliczajacy.start();

			// Poni¿sza linia decyduje czy w¹tki maj¹ byæ wykonywane sekwencyjnie czy wspó³bie¿nie.
			//while(watekZliczajacy.isAlive())  Thread.sleep(0);
		}
		czasPracy = System.currentTimeMillis() - czasPracy;
		while(Thread.activeCount() > 1) {
			
		}
		System.out.println("\nCzas wykonywania obliczeñ: "+ czasPracy +" milisekund.");

		
	}

}
