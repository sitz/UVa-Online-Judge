import java.util.*;
import java.math.*;

class Main{
	static final BigDecimal ZERO = new BigDecimal("0");
	static final BigDecimal ONE  = new BigDecimal("1");
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		while( T-- > 0 ){
			BigDecimal tot = ZERO;
			while( true ){
				BigDecimal temp = in.nextBigDecimal();
				if( temp.equals( ZERO ) ){
					char[] out = tot.toString().toCharArray();
					int L = out.length - 1;
					while( L >= 0 && out[L] == '0' )	--L;
					if( L >= 0 && out[L] == '.' )	--L;
					
					for (int i = 0; i <= L; i++)
						System.out.print(out[i]);
					System.out.println();
					break;
				}
				tot = tot.add( temp );
			}
		}
	}
}
