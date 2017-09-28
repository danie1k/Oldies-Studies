
public abstract class Location {
	
	protected String msg;
	protected Identyfikator id;
	public abstract void printMsg();
	public boolean porownaj(Location a){
		if(this.id.compareTo(a.getId())==0) return true;
		return false;
	}
	public Identyfikator getId() {
		if(this.id.compareTo(new Identyfikator(-1,-1,-1))!=-1) return this.id;
		return new Identyfikator(-1,-1,-1);
	}
	
}
