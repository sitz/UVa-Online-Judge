#include <bits/stdc++.h>

using namespace std;

int abs(int k)
{
	return (k > 0) ? k : -k;
}
int m[31][31];
int n;
int det(int n, int r, int c)
{
	if (n == 1)
	{
		return m[r][c];
	}
	if (n == 2)
	{
		return m[r][c] * m[r + 1][c + 1] - m[r][c + 1] * m[r + 1][c];
	}
	else
	{
		int res = 1, min, p;
		bool flag;
		while (true)
		{
			flag = true;
			for (int i = r + 1, t = 1; t < n; i++, t++)
				if (m[i][c])
				{
					flag = false;
				}
			if (flag)
			{
				break;
			}
			min = 999999999;
			for (int i = r, t = 0; t < n; i++, t++)
				if (m[i][c] && abs(m[i][c]) < min)
				{
					min = abs(m[i][c]);
					p = i;
				}
			if (p != r)
			{
				res *= (-1);
				for (int i = 0; i < n; i++)
				{
					int t = m[r][c + i];
					m[r][c + i] = m[p][c + i];
					m[p][c + i] = t;
				}
			}
			for (int i = 1; i < n; i++)
			{
				int base = m[r + i][c] / m[r][c];
				for (int j = 0; j < n; j++)
				{
					m[r + i][c + j] -= base * m[r][c + j];
				}
			}
		}
		int k = det(n - 1, r + 1, c + 1);
		return res * m[r][c] * k;
	}
}
int main()
{
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &m[i][j]);
			}
		int ans = det(n, 0, 0);
		printf("%d\n", ans);
	}
	puts("*");
}
