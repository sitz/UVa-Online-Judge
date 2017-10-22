#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

unsigned xor32()
{
	static unsigned x = 123456789, y = 362436069, z = 521288629, w = 88675123;
	unsigned t = x ^ (x << 11);
	x = y;
	y = z;
	z = w;
	return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		double p;
		scanf("%d%lf", &n, &p);
		int win = 0;
		rep(t, 100000)
		{
			int a = 0, b = 0;
			while (a < n && b < n)
			{
				if (xor32() < p * UINT_MAX)
				{
					a++;
				}
				else
				{
					b++;
				}
			}
			if (a == n)
			{
				win++;
			}
		}
		printf("%.2f\n", win / 1e5);
	}
	return 0;
}
