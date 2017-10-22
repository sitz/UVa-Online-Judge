#include <bits/stdc++.h>

using namespace std;

int m[1001][1001];
int main()
{
	for (int i = 2; i <= 1000; i++)
	{
		if (i % 3 == 0)
		{
			for (int j = 1; j <= 500; j++)
			{
				m[i][2 * j] = 1;
			}
			if (i != 3)
				for (int j = (!(i & 1)) ? 1 : 2; j <= 499; j++)
				{
					m[i][2 * j + 1] = 1;
				}
		}
		else
		{
			for (int j = 2; j <= 333; j++)
			{
				m[i][3 * j] = 1;
			}
			if (!(i & 1))
			{
				m[i][3] = 1;
			}
		}
	}
	for (int i = 1; i <= 1000; i++)
		for (int j = 1; j <= 1000; j++)
		{
			m[i][j] = m[i][j] + m[i - 1][j] + m[i][j - 1] - m[i - 1][j - 1];
		}
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int l1, l2, w1, w2, c = 0;
		scanf("%d%d%d%d", &l1, &l2, &w1, &w2);
		if (l1 > l2)
		{
			int t = l1;
			l1 = l2;
			l2 = t;
		}
		if (w1 > w2)
		{
			int t = w1;
			w1 = w2;
			w2 = t;
		}
		printf("%d\n", m[w2][l2] - m[w2][l1 - 1] - m[w1 - 1][l2] + m[w1 - 1][l1 - 1]);
	}
}
