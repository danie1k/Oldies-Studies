
public class Pokoj extends Location {
	
	public Pokoj(int bud, int pie, int nrP){
		if(bud>0&&pie>0&&nrP>0) this.id = new Identyfikator(bud,pie,nrP);
		else this.id = new Identyfikator(-1,-1,-1);
	}

	@Override
	public void printMsg() {
		if(this.id.compareTo(new Identyfikator(-1,-1,-1))!=-1){
			System.out.println(this.id);
		}
	}

}
