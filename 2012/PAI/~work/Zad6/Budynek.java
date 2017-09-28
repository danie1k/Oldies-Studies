
public class Budynek extends Location {
	private Pietro[] pieterka;
	
	public Budynek(int numer, int ilePieter, int ilePokoi){
		if(numer>0 && ilePieter>0 && ilePokoi>0){
			this.id = new Identyfikator(numer,-1,-1);
			pieterka = new Pietro[ilePieter];
			for(int i = 0;i<ilePieter;i++) pieterka[i] = new Pietro(numer,i+1,ilePokoi);
		}else this.id = new Identyfikator(-1,-1,-1);
	}

	@Override
	public void printMsg() {
		if(this.id.compareTo(new Identyfikator(-1,-1,-1))!=-1){
			System.out.println(this.id);
			System.out.println("Ten Budynek posiada: "+pieterka.length+" pieter");
		}
	}
	
	public Location getLocation(int ktore){
		if((this.id.compareTo(new Identyfikator(-1,-1,-1))!=-1)&&
				(ktore>0&&ktore<=pieterka.length)){
			return pieterka[ktore-1];
		}else return new Pietro(-1,-1,-1);
	}
	
	public Location getLocation(int floor, int room){
		if((this.id.compareTo(new Identyfikator(-1,-1,-1))!=-1)&&
				(floor>0&&floor<=pieterka.length)){
			return pieterka[floor-1].getRoom(room);
		}return new Pokoj(-1,-1,-1);
	}
}
