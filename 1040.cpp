#include <bits/stdc++.h>

using namespace std;

struct edges
{
	int a, b, c;
} e[500];
int nc, nr, dc, nj;
int father[100], mark[100], flag[100], g[20][20];
int order[500];
bool cmp(int i, int j)
{
	if (e[i].c == e[j].c)
	{
		if (e[i].a == e[j].a)
		{
			return e[i].b < e[i].b;
		}
		else
		{
			return e[i].a < e[j].a;
		}
	}
	else
	{
		return e[i].c < e[j].c;
	}
}
int getf(int x)
{
	if (father[x] == x)
	{
		return x;
	}
	else
	{
		return father[x] = getf(father[x]);
	}
}
bool Unoin(int a, int b)
{
	int fa = getf(a), fb = getf(b);
	if (fa == fb)
	{
		return false;
	}
	father[fa] = fb;
	g[a][b] = g[b][a] = 1;
	return 1;
}

vector<int> path[100];
int arr[100], tot;
void dfs(int now, int dep, int fa)
{
	// printf("%d %d %d\n",now,dep,fa);
	arr[dep++] = now;
	if (mark[now])
	{
		path[now].clear();
		for (int i = dep - 1; i >= 0; i--)
		{
			path[now].push_back(arr[i]);
		}
	}
	for (int i = 0; i < nc; i++)
		if (g[now][i] && i != fa)
		{
			dfs(i, dep, now);
		}
}

void renew()
{
	dfs(dc, 0, -1);
}
bool better(int st0, int st1)
{
	for (int i = 0; i < tot; i++)
	{
		if (!((1 << i) & st0) && ((1 << i) & st1))
		{
			return 0;
		}
		if (!((1 << i) & st1) && ((1 << i) & st0))
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	int i, j, tcas = 1;
	while (scanf("%d", &nc) && nc != -1)
	{
		int Ans = 1 << 30, Anscnt = 1 << 30, Ansmask;
		scanf("%d%d", &dc, &nr);
		dc--;
		for (i = 0; i < nr; i++)
		{
			scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].c);
			e[i].a--, e[i].b--;
		}
		scanf("%d", &nj);
		memset(mark, 0, sizeof(mark));
		int In[100];
		for (i = 0; i < nj; i++)
		{
			int a;
			scanf("%d", &a);
			a--;
			In[i] = a;
			mark[a] = 1;
		}
		mark[dc] = 1;
		int Tn = 0;
		tot = 0;
		int num[100];
		for (i = 0; i < nc; i++)
			if (!mark[i])
			{
				num[tot++] = i;
			}
			else
			{
				Tn++;
			}
		for (int st = 0; st < (1 << tot); st++)
		{
			memcpy(flag, mark, sizeof(mark));
			int addn = 0;
			for (i = 0; i < tot; i++)
				if ((1 << i) & st)
				{
					addn++;
					flag[num[i]] = 1;
				}
			int T = 0;
			for (i = 0; i < nr; i++)
				if (flag[e[i].a] && flag[e[i].b])
				{
					order[T++] = i;
				}
			sort(order, order + T, cmp);
			memset(g, 0, sizeof(g));
			int cnt = 0;
			for (i = 0; i < nc; i++)
			{
				father[i] = i;
			}
			int tmps = 0;
			memset(g, 0, sizeof(g));
			for (i = 0; i < T; i++)
				if (Unoin(e[order[i]].a, e[order[i]].b))
				{
					cnt++;
					tmps += e[order[i]].c;
					if (cnt == Tn + addn - 1)
					{
						break;
					}
				}
			if (cnt == Tn + addn - 1)
			{
				if (tmps < Ans || (tmps == Ans && cnt < Anscnt) || (tmps == Ans && cnt == Anscnt && better(st, Ansmask)))
				{
					Ans = tmps;
					Anscnt = cnt;
					Ansmask = st;
					renew();
				}
			}
		}
		printf("Case %d: distance = %d\n", tcas++, Ans);
		for (i = 0; i < nj; i++)
		{
			printf("   %d", In[i] + 1);
			for (j = 1; j < path[In[i]].size(); j++)
			{
				printf("-%d", path[In[i]][j] + 1);
			}
			printf("\n");
		}
		printf("\n");
	}
}
