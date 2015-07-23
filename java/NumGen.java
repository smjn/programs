import java.util.Random;

class NumGen{
	public static void main(String[] aArgs){
		Random rand = new Random(47);
		int size = Integer.parseInt(aArgs[0]);
		for(int i=0;i<size;i++){
			System.out.println(rand.nextInt(10000));
		}
	}		
}
