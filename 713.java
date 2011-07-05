import java.math.*;
import java.util.*;

public class Main{
		static BigInteger ZERO=new BigInteger("0");
		static BigInteger TEN=new BigInteger("10");
	public static void main(String[] args){

		int N=0;
		Scanner in=new Scanner(System.in);
		N=in.nextInt();
		for(int i=0;i<N;i++){
			BigInteger n1=in.nextBigInteger();
			BigInteger n2=in.nextBigInteger();
			BigInteger rev_n=rev(n1).add(rev(n2));
			BigInteger res=rev(rev_n);
			System.out.println(res);
		}
	}
	static BigInteger rev(BigInteger A){
		BigInteger rem=new BigInteger("0");
		BigInteger rev=new BigInteger("0");
		while(A.compareTo(ZERO)>0){
			rem=A.mod(TEN);
			rev=rev.multiply(TEN).add(rem);
			A=A.divide(TEN);
		}
		return rev;
	}
}
