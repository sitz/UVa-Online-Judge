#include <bits/stdc++.h>

using namespace std;

int table[2][2] = {0, 0, 0, 1};
int sg[105][105], a[105][105], b[105][105], num[1 << 15], tmp[105], on[105];

int Nim_Mult(int x, int y)
{
	if (x < y)
		return Nim_Mult(y, x);
	if (x < 2)
		return table[x][y];
	int a = 0;
	while (x >= (1 << (1 << (a + 1))))
		a++;
	int m = 1 << (1 << a);
	int p = x / m, q = x % m, s = y / m, t = y % m;
	int c1 = Nim_Mult(p, s), c2 = Nim_Mult(p, t) ^ Nim_Mult(q, s), c3 = Nim_Mult(q, t);
	return m * (c1 ^ c2) ^ c3 ^ Nim_Mult(m / 2, c1);
}

void init()
{
	int i, j;
	for (i = 1; i <= 100; i++)
		for (j = 1; j <= 100; j++)
			sg[i][j] = Nim_Mult(i & -i, j & -j);
}

int main()
{
	int n, m, c, i, j, k, s;
	init();
	while (scanf("%d%d", &n, &m) != EOF)
	{
		s = c = 0;
		memset(on, 0, sizeof(on));
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
			{
				scanf("%d", &a[i][j]);
				if (a[i][j])
					s ^= sg[n - i + 1][m - j + 1];
				on[i] = 1;
			}
		if (!s)
		{
			puts("No");
			continue;
		}
		for (j = 1; j <= m; j++)
			for (i = 1; i <= n; i++)
				b[i][j] = b[i - 1][j] ^ sg[n - i + 1][m - j + 1];
		int x1 = n, y1 = m, x2, y2;
		for (i = 1; i <= n; i++)
			if (on[i])
				for (j = i; j <= n; j++)
				{
					for (k = 1; k <= m; k++)
						tmp[k] = b[i - 1][k] ^ b[j][k];
					tmp[m + 1] = 0;
					for (k = m; k > 0; k--)
						tmp[k] ^= tmp[k + 1];
					num[s] = 1;
					for (k = m; k > 0; k--)
					{
						if (a[i][k] && num[tmp[k]])
						{
							c += num[tmp[k]];
							if (i < x1 || (i == x1 && k < y1))
								x1 = i, y1 = k;
						}
						num[tmp[k] ^ s]++;
					}
					num[s]--;
					for (k = 1; k <= m; k++)
						num[tmp[k] ^ s]--;
				}
		memset(b, 0, sizeof(b));
		for (i = n; i > 0; i--)
			for (j = m; j > 0; j--)
				b[i][j] = sg[n - i + 1][m - j + 1] ^ b[i + 1][j] ^ b[i][j + 1] ^ b[i + 1][j + 1];
		for (i = x1; i <= n; i++)
		{
			for (j = y1; j <= m; j++)
			{
				if ((b[x1][y1] ^ b[x1][j + 1] ^ b[i + 1][y1] ^ b[i + 1][j + 1]) == s)
				{
					x2 = i, y2 = j;
					break;
				}
			}
			if (j <= m)
				break;
		}
		printf("%d %d %d %d %d\n", c, x1, y1, x2, y2);
	}
	return 0;
}
