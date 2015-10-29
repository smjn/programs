import java.math.*;
import java.io.*;
import java.util.*;

class yodlee{

	static ArrayList<BigInteger> bigs = new ArrayList<BigInteger>();
	static int prec=500;

	public static void main(String[] args) throws Exception{
		preprocess2();
		//System.out.println(bigs.size());
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());

		BigInteger b0 = BigInteger.valueOf(0L);
		while(n!=0){
			n--;
			BigInteger x = new BigInteger(br.readLine());
			for(int i=0;i<bigs.size();i++){
				//System.out.println(bigs.get(i).mod(x));
				if(bigs.get(i).mod(x).equals(b0)){
					printIt(bigs.get(i));
					break;
				}
			}
		}
	}

	public static void preprocess(){
		BigInteger b0 = BigInteger.valueOf(0L), b4 = BigInteger.valueOf(4L), b10 = BigInteger.valueOf(10L);
		
		BigInteger cur = b0, temp;

		for(int i=0;i<prec;i++){
			cur = cur.multiply(b10).add(b4);
			bigs.add(cur);
			temp = cur;
			for(int j=0;j<prec-i;j++){
				temp = temp.multiply(b10);
				bigs.add(temp);
			}
		}

		Collections.sort(bigs);
	}

	public static void preprocess2(){
		String s="",temp;
		for(int i=0;i<prec;i++){
			s+="4";
			bigs.add(new BigInteger(s));
			temp = s;
			for(int j=0;j<prec-i;j++){
				temp+="0";
				bigs.add(new BigInteger(temp));
			}
		}

		Collections.sort(bigs);

		//for(BigInteger x:bigs)	System.out.println(x);
	}

	public static void printIt(BigInteger b){
		System.out.println(b);
		String x = b.toString();
		int s=0,p=0;
		for(int i=0;i<x.length();i++){
			if(x.charAt(i)=='4')	s++;
			if(x.charAt(i)=='0')	p++;
		}

		System.out.println(2*s+p);
	}
}
