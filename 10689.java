import java.util.*;
import java.math.*;
 
public class Main {
 	static long f0, f1, n, m;
 	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long T = in.nextLong();
 		while (T-- > 0) {
			f0 = in.nextLong();
			f1 = in.nextLong();
 			n  = in.nextLong();
 			m  = in.nextLong();
			
			long mod = (long) Math.pow(10, m);
			long [][]mat = mpow(n, mod);
			System.out.println((f0 * mat[0][0] + f1 * mat[0][1]) % mod);
		}
	}
 
	public static long[][] mpow(long p, long mod) {
		long[][] f = new long[][] { {0, 1}, {1, 1} };
 
		if (p == 0)
			return new long[2][2];
 
		if (p == 1)
			return f;
 
		else if (p % 2 == 0) {
			long[][] a = mpow(p / 2, mod);
			return multiply(a, a, mod);
		} else
			return multiply(f, mpow(p - 1, mod), mod);
	}
 
	public static long[][] multiply(long[][] a, long[][] a2, long mod) {
		long[][] r = new long[2][2];
 
		r[0][0] = ( a[0][0] * a2[0][0] + a[0][1] * a2[1][0] ) % mod;
		r[0][1] = ( a[0][0] * a2[0][1] + a[0][1] * a2[1][1] ) % mod;
		r[1][0] = ( a[1][0] * a2[0][0] + a[1][1] * a2[1][0] ) % mod;
		r[1][1] = ( a[1][0] * a2[0][1] + a[1][1] * a2[1][1] ) % mod;
 
		return r;
	}
}
