import java.math.*;
import java.util.*;

public class Main{
	public static void main(String[] args){
		BigInteger ZERO=new BigInteger("0");
		BigInteger ONE=new BigInteger("1");
		BigInteger sum=ZERO;
		BigInteger[] F=new BigInteger[5050];
		F[0]=ZERO;
		F[1]=ONE;
		int i=0,N=0;
		Scanner in=new Scanner(System.in);
		for(i=2;i<5050;i++)
			F[i]=F[i-1].add(F[i-2]);
		while(in.hasNext()){
			N=in.nextInt();
			System.out.printf("The Fibonacci number for %d is %d\n",N,F[N]);
		}
	}
}
