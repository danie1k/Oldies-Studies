
public class Pietro extends Location {
	
	private Pokoj[] pokoiki;
	
	public Pietro(int Budynek, int nrPietra, int ileP){
		if(Budynek>0&&nrPietra>0&&ileP>0){
			this.id = new Identyfikator(Budynek, nrPietra,-1);
			pokoiki = new Pokoj[ileP];
			for(int i=0;i<ileP;i++){
				pokoiki[i]=new Pokoj(Budynek, nrPietra, i+1);
			}
		}else this.id = new Identyfikator(-1,-1,-1);
	}

	@Override
	public void printMsg() {
		if(this.id.compareTo(new Identyfikator(-1,-1,-1))!=-1){
			System.out.println(this.id);
			System.out.println("To pietro posiada: "+pokoiki.length+" pokoi");
		}
	}

	public Location getRoom(int jaki){
		if((this.id.compareTo(new Identyfikator(-1,-1,-1))!=-1)&&
				(jaki>0&&jaki<=pokoiki.length)){
			return pokoiki[jaki-1];
		}else return new Pokoj(-1,-1,-1);		
	}
	
}
