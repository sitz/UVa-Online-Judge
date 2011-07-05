import java.math.BigInteger;
import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		BigInteger TEN=new BigInteger("10");
		BigInteger ONE=new BigInteger("1");
		BigInteger ZERO=new BigInteger("0");
		BigInteger N=ZERO;
		BigInteger []F=new BigInteger[10000];
		int i=0;
		F[0]=ZERO;
		F[1]=ONE;
		F[2]=ONE.add(ONE);
		for(i=3;;i++){
			F[i]=F[i-1].add(F[i-2]);
			if(F[i].compareTo(TEN.pow(100))>0)
				break;
		}
		Scanner in=new Scanner(System.in);
		for(;;){
			BigInteger a=in.nextBigInteger();
			BigInteger b=in.nextBigInteger();
			BigInteger ctr=ZERO;
			if(a.compareTo(ZERO)==0 && b.compareTo(ZERO)==0)
				break;
			
			for(i=1;;i++){
				if(F[i].compareTo(b)>=0)
					break;
				if(F[i].compareTo(a)>0)
					ctr=ctr.add(ONE);
			}
			System.out.println(ctr);
		}
	}
}