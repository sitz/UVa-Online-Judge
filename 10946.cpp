#include <bits/stdc++.h>

using namespace std;

char a[50 + 3][50 + 3];
int R, C, cnt;

struct node
{
	char ch;
	int f;
} p[2600];

void dfs(int r, int c, char k)
{
	if (r < 0 || r == R || c < 0 || c == C || a[r][c] != k)
	{
		return;
	}
	cnt++;
	a[r][c] = '.';
	dfs(r - 1, c, k);
	dfs(r + 1, c, k);
	dfs(r, c + 1, k);
	dfs(r, c - 1, k);
}

bool cmp(const node &x, const node &y)
{
	if (x.f > y.f)
	{
		return true;
	}
	if (x.f == y.f && x.ch < y.ch)
	{
		return true;
	}
	return false;
}

int main()
{
	int t = 0;
	while (scanf("%d%d", &R, &C))
	{
		if (R == 0 && C == 0)
		{
			break;
		}
		for (int i = 0; i < R; i++)
		{
			scanf("%s", a[i]);
		}
		int len = 0;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (a[i][j] != '.')
				{
					cnt = 0;
					p[len].ch = a[i][j];
					dfs(i, j, a[i][j]);
					p[len++].f = cnt;
				}
			}
		}
		sort(p, p + len, cmp);
		printf("Problem %d:\n", ++t);
		for (int i = 0; i < len; i++)
		{
			printf("%c %d\n", p[i].ch, p[i].f);
		}
	}
	return 0;
}
