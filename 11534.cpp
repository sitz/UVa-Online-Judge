#include <bits/stdc++.h>

using namespace std;

int T, f[4][105], i, j, s, c, x, N;
bool b[105];
char p, a[105];
int main()
{
	for (i = 1; i <= 100; ++i)// 計 SG
	{
		for (j = 0; j <= 100; ++j)
		{
			b[j] = false;
		}
		for (j = 0; j < i; ++j)
		{
			b[f[1][j] ^ f[1][i - j - 1]] = true;
		}
		for (j = 1; j < i - 1; ++j)
		{
			b[f[0][j] ^ f[0][i - j - 1]] = true;
		}
		j = 0;
		while (b[j] == true)
		{
			++j;
		}
		f[0][i] = j;
		for (j = 0; j <= 100; ++j)
		{
			b[j] = false;
		}
		for (j = 0; j < i - 1; ++j)
		{
			b[f[1][j] ^ f[0][i - j - 1]] = true;
		}
		for (j = 1; j < i; ++j)
		{
			b[f[0][j] ^ f[1][i - j - 1]] = true;
		}
		j = 0;
		while (b[j] == true)
		{
			++j;
		}
		f[1][i] = j;
		for (j = 0; j <= 100; ++j)
		{
			b[j] = false;
		}
		for (j = 0; j < i; ++j)
		{
			b[f[1][j] ^ f[2][i - j - 1]] = true;
		}
		for (j = 1; j < i; ++j)
		{
			b[f[0][j] ^ f[2][i - j - 1]] = true;
		}
		j = 0;
		while (b[j] == true)
		{
			++j;
		}
		f[2][i] = j;
		for (j = 0; j <= 100; ++j)
		{
			b[j] = false;
		}
		for (j = 0; j < i; ++j)
		{
			b[f[2][j] ^ f[2][i - j - 1]] = true;
		}
		j = 0;
		while (b[j] == true)
		{
			++j;
		}
		f[3][i] = j;
	}
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", a);
		p = '.';
		x = s = c = 0;
		N = strlen(a);
		for (i = 0; i < N; ++i)
		{
			if (a[i] != '.')
			{
				++c;
				if (p == '.')
				{
					x ^= f[2][s];// 對每個平行遊戲的 SG 去 XOR
				}
				else if (a[i] == p)
				{
					x ^= f[0][s];
				}
				else
				{
					x ^= f[1][s];
				}
				s = 0;
				p = a[i];
			}
			else
			{
				++s;
			}
		}
		x ^= f[2][s];
		if (c == 0)
		{
			if (f[3][N] == 0)
			{
				printf("Impossible.\n");
			}
			else
			{
				printf("Possible.\n");
			}
		}
		else
		{
			if (c % 2 == 0)
			{
				if (x == 0)
				{
					printf("Impossible.\n");
				}
				else
				{
					printf("Possible.\n");
				}
			}
			else
			{
				if (x != 0)
				{
					printf("Impossible.\n");
				}
				else
				{
					printf("Possible.\n");
				}
			}
		}
	}
	return 0;
}
