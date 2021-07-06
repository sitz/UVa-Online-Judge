#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 1;
const int adj = 3;
const int di[] = {0, 1, 1, -1};
const int dj[] = {1, 0, 1, -1};

char g[N][N];

inline int cons(int i, int j, int n, int m)
{
	int cnt = 0, tmp;
	if (m == 1)
	{
		return g[i][j] != '.';
	}
	for (int d = 0; d < adj; ++d)
	{
		bool flg = true;
		tmp = i + di[d] * (m - 1);
		if (tmp < 0 || n <= tmp)
    {
			continue;
    }
		tmp = j + dj[d] * (m - 1);
		if (tmp < 0 || n <= tmp)
    {
			continue;
    }
		int l;
		for (l = 0; l < m; ++l)
		{
			int ni = i + di[d] * l;
			int nj = j + dj[d] * l;
			if (ni < 0 || n <= ni)
      {
				break;
      }
			if (nj < 0 || n <= nj)
      {
				break;
      }
			if (g[i][j] != g[ni][nj])
      {
				break;
      }
		}
		if (m <= l)
		{
			++cnt;
			while (l--)
			{
				int ni = i + di[d] * l;
				int nj = j + dj[d] * l;
				if (l)
        {
					g[ni][nj] = '.';
        }
			}
		}
	}
	return (bool)cnt;
	return cnt;
}

char s1[] = "X WINS";
char s2[] = "O WINS";
char s3[] = "DRAW";
char s4[] = "IN PROGRESS";
char s5[] = "ERROR";

char *solve(int n, int m)
{
	int x = count(&g[0][0], &g[n - 1][n], 'X');
	int o = count(&g[0][0], &g[n - 1][n], 'O');
	int dot = n * n - x - o;
	if (!(x == o) && !(x == o + 1))
  {
		return s5;
  }
	int X = x;
	int O = o;
	x = o = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (g[i][j] == '.')
      {
				continue;
      }
			int tmp = cons(i, j, n, m);
			if (tmp)
			{
				if (g[i][j] == 'X')
        {
					x += tmp;
        }
				else
        {
					o += tmp;
        }
			}
			g[i][j] = '.';
		}
	}
	if ((x && o) || 2 <= x || 2 <= o)
  {
		return s5;
  }
	if (x == 1 && o == 0)
	{
		if (X != O)
    {
			return s1;
    }
		else
    {
			return s5;
    }
	}
	if (x == 0 && o == 1)
	{
		if (X == O)
    {
			return s2;
    }
		else
    {
			return s5;
    }
	}
	if (x == 0 && o == 0)
	{
		if (dot == 0)
    {
			return s3;
    }
		else
    {
			return s4;
    }
	}
	return s4;
}

int main()
{
	int tc;
	scanf("%d\n", &tc);
	while (tc--)
	{
		fill(&g[0][0], &g[N - 1][N], '.');
		int n, m;
		scanf("%d %d\n", &n, &m);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				scanf("%c", &g[i][j]);
			}
			scanf("\n");
		}
		printf("%s\n", solve(n, m));
	}
	return 0;
}
