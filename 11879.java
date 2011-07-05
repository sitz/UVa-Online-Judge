import java.util.*;
import java.math.*;

public class Main{
	static BigInteger Z = new BigInteger("0");
	static BigInteger O = new BigInteger("1");
	static BigInteger S = new BigInteger("17");
	
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		while (true){
			BigInteger N = in.nextBigInteger();
			if (N.equals(Z))
				break;
			BigInteger R = N.mod(S);
			if (R.equals(Z))
				System.out.println("1");
			else
				System.out.println("0");
		}
	}
}
