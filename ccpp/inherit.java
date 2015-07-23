class Singleton{
	private static Singleton obj;
	
	private Singleton(){
		System.out.println("Constructor");
	}

	public static Singleton getInstance(){
		synchronized(Singleton.class){
			if(obj == null)
				obj = new Singleton();
			return obj;
		}
	}

	public static void main(String... aArgs){
		Singleton.getInstance();
		Singleton.getInstance();
		Singleton.getInstance();
	}
}


