class Counter{
	volatile int c;
	private static Integer lock = new Integer(0);
	Counter(int c){
		this.c = c;
	}

	void even(){
		synchronized(lock){
			System.out.println("Even:"+c);
			c++;
			try{
				lock.notify();
				lock.wait();
			}
			catch(InterruptedException ie){
			}
		}
	}

	void odd(){
		synchronized(lock){
			System.out.println("Odd:"+c);
			c++;
			try{
				lock.notify();
				lock.wait();
			}
			catch(InterruptedException ie){
			}
		}
	}
}

class Even implements Runnable{
	Counter cnt;

	Even(Counter c){
		cnt = c;
	}

	public void run(){
		int i=0;
		while(i++ < 10){
			cnt.even();
		}
	}
}

class Odd implements Runnable{
	Counter cnt;
	Odd(Counter c){
		cnt = c;
	}

	public void run(){
		int i=0;
		while(i++ < 10){
			cnt.odd();
		}
	}
}

public class EO{
	public static void main(String[] args){
		Counter c = new Counter(1);
		new Thread(new Even(c)).start();
		new Thread(new Odd(c)).start();
	}
}
