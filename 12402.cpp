#include <bits/stdc++.h>

using namespace std;

int maze[10][8];
int cap[10];
int n;

int dep;
int ans[22];

int ht[10000020];
int val[10000020];

inline int p(int pos, int x)
{
	return (pos & (7 << (x * 3))) >> (x * 3);
}

bool dfs(int d, int pos)
{
	int h = 0, th = 0;
	bool col[15] = {false};
	for (int i = 0; i < n; i++)
	{
		int tp = p(pos, i);
		if (cap[i] - tp > th)
		{
			th = cap[i] - tp;
		}
		for (int j = tp; j < cap[i]; j++)
		{
			if (col[maze[i][j]])
			{
				continue;
			}
			col[maze[i][j]] = true;
			h++;
		}
	}
	if (th > h)
	{
		h = th;
	}
	if (h + d > dep)
	{
		return false;
	}
	if (h == 0)
	{
		return true;
	}
	for (int i = 0; i < n; i++)
	{
		int tp = p(pos, i);
		if (cap[i] == tp)
		{
			continue;
		}
		int c = maze[i][tp];
		bool flag = true;
		for (int j = 0; j < i; j++)
		{
			int ttp = p(pos, j);
			if (ttp >= cap[j])
			{
				continue;
			}
			if (maze[j][ttp] == c)
			{
				flag = false;
				break;
			}
		}
		if (!flag)
		{
			continue;
		}
		int tpos = pos;
		for (int j = i; j < n; j++)
		{
			int ttp = p(pos, j);
			if (ttp >= cap[j])
			{
				continue;
			}
			if (maze[j][ttp] == c)
			{
				tpos += (1 << (j * 3));
			}
		}
		int th = tpos % 10000007;
		if (ht[th] == dep && val[th] <= d)
		{
			continue;
		}
		ht[th] = dep;
		val[th] = d;
		ans[d] = c;
		if (dfs(d + 1, tpos))
		{
			return true;
		}
	}
	return false;
}

int main()
{
	while (~scanf("%d", &n))
	{
		memset(ht, -1, sizeof(ht));
		memset(val, -1, sizeof(val));
		memset(maze, -1, sizeof(maze));
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &cap[i]);
			for (int j = 0; j < cap[i]; j++)
			{
				scanf("%d", &maze[i][j]);
			}
		}
		int k;
		scanf("%d", &k);
		int pos = 0;
		for (int i = 0; i < n; i++)
		{
			pos += ((maze[i][0] == k) << (i * 3));
		}
		dep = 0;
		while (true)
		{
			if (dfs(0, pos))
			{
				break;
			}
			dep++;
		}
		printf("%d", k);
		for (int i = 0; i < dep; i++)
		{
			printf(" %d", ans[i]);
		}
		puts("");
	}
	return 0;
}
