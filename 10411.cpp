#include <bits/stdc++.h>

using namespace std;

int h[100], n;
int cc[19], ptr;
int d[19] = {0, 0, 0, -1, 0, -1, 0, 0, -1, -1, 0, 0, -2, 0, 0, 0, -1, 0, 0};
int l[19] = {1, 4, 2, 3, 3, 2, 2, 3, 3, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2};
int c[19][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, -1, -1, 0}, {0, 0, 1, 0}, {0, -1, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, -1, 0, 0}, {0, -1, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, -1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 2, 0, 0}, {0, -2, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
int a[19][4] = {{4, 0, 0, 0}, {1, 1, 1, 1}, {2, 2, 0, 0}, {1, 2, 1, 0}, {1, 2, 1, 0}, {2, 2, 0, 0}, {2, 2, 0, 0}, {1, 2, 1, 0}, {1, 2, 1, 0}, {1, 3, 0, 0}, {3, 1, 0, 0}, {2, 1, 1, 0}, {1, 1, 2, 0}, {2, 1, 1, 0}, {1, 1, 2, 0}, {3, 1, 0, 0}, {1, 3, 0, 0}, {3, 1, 0, 0}, {1, 3, 0, 0}};
bool gameover()
{
	for (int i = 0; i < n; i++)
		if (h[i])
		{
			return false;
		}
	return true;
}
int can(int col, int type)
{
	int temp[100], max = 0;
	if (col + d[type] < 0 || col + d[type] + l[type] >= n + 1)
	{
		return -1;
	}
	int basecol = col + d[type];
	for (int i = 1; i < l[type]; i++)
		if (h[basecol + i] != h[basecol] + c[type][i])
		{
			return -1;
		}
	for (int i = 0; i < n; i++)
	{
		temp[i] = h[i];
	}
	for (int i = 0; i < l[type]; i++)
	{
		temp[basecol + i] += a[type][i];
		if (temp[basecol + i] > max)
		{
			max = temp[basecol + i];
		}
	}
	return max;
}
void put(int col, int type)
{
	int min = 9999999;
	int basecol = col + d[type];
	for (int i = 0; i < l[type]; i++)
	{
		h[basecol + i] += a[type][i];
	}
	for (int i = 0; i < n; i++)
		if (h[i] < min)
		{
			min = h[i];
		}
	for (int i = 0; i < n; i++)
	{
		h[i] -= min;
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	srand(time(NULL));
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", h + i);
		}
		while (true)
		{
			if (gameover())
			{
				break;
			}
			int c = 0, min = 999, p;
			ptr = 0;
			for (int i = 0; i < n; i++)
				if (h[i] < h[c])
				{
					c = i;
				}
			for (int k = 0; k < 19; k++)
			{
				int d = can(c, k);
				if (d == -1)
				{
					continue;
				}
				if (d < min)
				{
					min = d;
					ptr = 0;
					cc[ptr++] = k;
				}
				else if (d == min)
				{
					cc[ptr++] = k;
				}
			}
			p = cc[rand() % ptr];
			put(c, p);
			printf("%d %d\n", p + 1, c + d[p] + 1);
		}
		puts("-1 -1");
	}
	return 0;
}
