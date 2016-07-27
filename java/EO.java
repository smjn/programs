class Counter{
	private int c;
	private boolean oddChance;
	Counter(){
		c = 0;
		oddChance = false;
	}

	synchronized void waitForOdd(){
		try{
			while(oddChance)
				wait();
		}
		catch(InterruptedException ie){
			ie.printStackTrace();
		}
	}

	synchronized void waitForEven(){
		try{
			while(!oddChance)
				wait();
		}
		catch(InterruptedException ie){
			ie.printStackTrace();
		}
	}

	synchronized void printOdd(){
		System.out.println("[Odd]:"+c++);
		oddChance = false;	//ready for Even
		notifyAll();
	}

	synchronized void printEven(){
		System.out.println("[Even]:"+c++);
		oddChance = true;	//ready for odd
		notifyAll();
	}
}

class Even implements Runnable{
	boolean isDone;
	Counter cnt;

	Even(Counter c){
		cnt = c;
		isDone = false;
	}

	public void run(){
		while(!isDone){
			cnt.printEven();
			cnt.waitForOdd();
		}
	}
}

class Odd implements Runnable{
	boolean isDone;
	Counter cnt;

	Odd(Counter c){
		cnt = c;
		isDone = false;
	}

	public void run(){
		while(!isDone){
			cnt.waitForEven();
			cnt.printOdd();
		}
	}
}

public class EO{
	public static void main(String[] args){
		Counter c = new Counter();
		new Thread(new Even(c)).start();
		new Thread(new Odd(c)).start();
	}
}
