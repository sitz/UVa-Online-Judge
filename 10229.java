import java.util.StringTokenizer;
 
public class Main {
 
	public static void main(String[] args) {
		String b;
 
		while ((b = ReadLn(255)) != null && !b.equals("\r") && !b.equals("\n")) {
 
			StringTokenizer tokens = new StringTokenizer(b);
			int n = (int) Long.parseLong(tokens.nextToken());
			int m = (int) Long.parseLong(tokens.nextToken());
 
			long mod = 1 << m;
			System.out.println(mpow(n, mod)[0][1] % mod);
 
		}
 
	}
 
	private static long sq(long fn) {
 
		return fn * fn;
	}
 
 
 
	public static long[][] mpow(int p, long mod) {
 
		long[][] f = new long[][] { { 1, 1 }, { 1, 0 } };
 
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
 
 
 
	static String ReadLn(int maxLg) // utility function to read from stdin
	{
		byte lin[] = new byte[maxLg];
		int lg = 0, car = -1;
		try {
			while (lg < maxLg) {
				car = System.in.read();
				if ((car < 0) || (car == '\n'))
					break;
				lin[lg++] += car;
			}
		} catch (Exception e) {
			return (null);
		}
 
		if ((car < 0) && (lg == 0))
			return (null); // eof
		return (new String(lin, 0, lg));
 
	}
}
