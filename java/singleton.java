class Singleton{
	private Singleton(){
	}

	enum HelperEnum{
		INSTANCE;

		private final Singleton instance;

		HelperEnum(){
			instance = new Singleton();
		}

		Singleton getInstance(){
			return instance;
		}
	}

	private static class Helper{
		private static final Singleton _instance = new Singleton();
		private static Singleton getInstance(){
			return _instance;
		}
	}

	public static Singleton getInstance(){
		return Helper.getInstance();
	}
}

class SingletonDriver{
	public static void main(String[] args){
		Singleton obj1 = Singleton.getInstance();
		Singleton obj2 = Singleton.getInstance();

		if(obj1 != obj2)	System.out.println("Not same");
		else	System.out.println("Same");

		if(Singleton.HelperEnum.INSTANCE.getInstance() != Singleton.HelperEnum.INSTANCE.getInstance())	System.out.println("Not same");
		else	System.out.println("Same");
	}
}
