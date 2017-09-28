
public class Identyfikator implements Comparable<Identyfikator> {
	
	private int nrBudynku, nrPietra, nrPokoju;
	
	public Identyfikator(int nrBudynku, int nrPietra, int nrPokoju){
		this.nrBudynku = nrBudynku;
		this.nrPietra = nrPietra;
		this.nrPokoju = nrPokoju;
	}
	
	@Override
	public int compareTo(Identyfikator o) {
		if (this.nrBudynku == -1 && this.nrPietra == -1 && this.nrPokoju == -1 &&
				o.nrBudynku == -1 && o.nrPietra == -1 && o.nrPokoju == -1){
			return -1;
		}
		if (this.nrBudynku == o.nrBudynku && this.nrPietra == o.nrPietra 
				&& this.nrPokoju == o.nrPokoju){
			return 0;
		}
		return 1;
	}
	
	@Override
	public String toString(){
		if(this.nrBudynku==-1&&this.nrPietra==-1&&this.nrPokoju==-1) return "Brak Loklizacji";
		String wiad = "Jestes ";
		if(this.nrBudynku!=-1){
			wiad += "w "+this.nrBudynku+" budynku ";
			
		}
		if(this.nrPietra != -1){
			wiad += "na " + this.nrPietra+" pietrze ";
		}
		if(this.nrPokoju != -1){
			wiad += "w "+ this.nrPokoju+" pokoju.";
		}
		
		return wiad;
		
	}

}
