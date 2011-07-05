import java.math.*;
import java.util.*;

public class Main{
	public static void main(String[] args){
		BigInteger ZERO=new BigInteger("0");
		BigInteger N=ZERO;
		BigInteger sum=ZERO;
		Scanner in=new Scanner(System.in);
		for(;;){
			N=in.nextBigInteger();
			if(N.compareTo(ZERO)==0){
				System.out.println(sum);
				break;
			}
			sum=sum.add(N);
		}
		
	}
}