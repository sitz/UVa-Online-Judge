import java.math.*;
import java.util.*;

public class Main{
	public static void main(String[] args){
		BigInteger B=new BigInteger("0");
		int P=0;
		BigInteger M=new BigInteger("0");
		Scanner in=new Scanner(System.in);
		for(;;){
			B=in.nextBigInteger();
			P=in.nextInt();
			M=in.nextBigInteger();
			if(B.compareTo(M)=='\u0000')
				break;
			BigInteger R=B.mod(M);
			R=R.pow(P);
			R=R.mod(M);
			System.out.println(R);
		}
	}
}
