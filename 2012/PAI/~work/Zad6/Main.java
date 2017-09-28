
public class Main {


	public static void main(String[] args) {
		
		Budynek nowy = new Budynek(103,5,20);
		Budynek nowy2 = new Budynek(103,5,21);
		Location s = nowy.getLocation(2);
		Location s2 = nowy.getLocation(2);
		if(nowy2.porownaj(nowy)==true)System.out.println("Takie same");
		else System.out.println("inne");
		
	}

}
