import java.math.*;

class BigGCD{
	public static void main(String[] args){
		System.out.println(
				new BigInteger(args[0]).gcd(
					new BigInteger(args[1])
					)
				);
	}
}
