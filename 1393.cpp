#include <bits/stdc++.h>

using namespace std;

int gcd[310][310];

int Gcd(int a, int b)
{
	return b == 0 ? a : Gcd(b, a % b);
}

int main()
{
	for (int i = 1; i <= 300; i++)
		for (int j = i; j <= 300; j++)
			gcd[i][j] = Gcd(i, j);
	int n, m;
	long long int ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (!n && !m)
			break;
		n--;
		m--;
		if (n > m)
			n ^= m, m ^= n, n ^= m;
		ans = 0;
		for (int x = 1; x <= n; x++)
		{
			for (int y = x; y <= m; y++)
				if (gcd[x][y] <= 2)
				{
					if (x == y)
					{
						int tmp = (n - x + 1) * (m - y + 1);
						if (gcd[x][y] == 1)
							ans += tmp;
						else
							ans -= tmp;
					}
					else
					{
						int tmp = (n - x + 1) * (m - y + 1);
						if (x <= m && y <= n)
							tmp += (m - x + 1) * (n - y + 1);
						if (gcd[x][y] == 1)
							ans += tmp;
						else
							ans -= tmp;
					}
				}
		}
		ans *= 2;
		printf("%lld\n", ans);
	}
	return 0;
}
