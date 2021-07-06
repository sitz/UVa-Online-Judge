#include <bits/stdc++.h>

using namespace std;

struct pp
{
	int id, ip;
};
pp adj[111][333];

struct qq
{
	int flag, ip;
};

bool vis[666], mark[111];
int n, m, e[2][333], ch[333], last[333], num[111], c, prev_[111], preu[111];

bool find_cycle(int flag, int x, int p)
{
	int i, j, s, q, id, ip;
	if (x == p)
	{
		return true;
	}
	for (i = 0; i < num[x]; i++)
	{
		id = adj[x][i].id;
		ip = adj[x][i].ip;
		if (ch[ip] == flag && !mark[id])
		{
			mark[id] = true;
			prev_[id] = ((ip << 1) | flag);
			preu[id] = x;
			if (find_cycle(flag, id, p))
			{
				return true;
			}
		}
	}
	return false;
}

bool bfs(int ip)
{
	int id, i, j, s, p, q, temp1, temp2, temp, flag, ipen;
	qq queue[666];
	bool inq[666] = {0};
	temp = 0;
	queue[temp++].ip = (ip << 1);
	queue[temp++].ip = (ip << 1) | 1;
	inq[ip << 1] = true;
	inq[(ip << 1) | 1] = true;
	temp1 = 0;
	temp2 = temp - 1;
	while (temp1 <= temp2)
	{
		for (i = temp1; i <= temp2; i++)
		{
			ipen = queue[i].ip;
			memset(mark, false, sizeof(mark));
			mark[e[0][ipen >> 1]] = true;
			if (!find_cycle(ipen & 1, e[0][ipen >> 1], e[1][ipen >> 1]))
			{
				while ((ipen >> 1) != ip)
				{
					ch[ipen >> 1] ^= 1;
					ipen = last[ipen];
				}
				ch[ip] = (ipen & 1);
				return 1;
			}
			for (j = e[1][ipen >> 1]; j != e[0][ipen >> 1]; j = preu[j])
			{
				int ipe = prev_[j] ^ 1;
				if (!inq[ipe])
				{
					inq[ipe] = true;
					queue[temp++].ip = ipe;
					last[ipe] = queue[i].ip;
				}
			}
		}
		temp1 = temp2 + 1;
		temp2 = temp - 1;
	}
	return 0;
}

int main()
{
	int i, j, s, p, q, u, v, T, u1, v1, u2, v2, t = 0;
	scanf("%d", &T);
	while (T--)
	{
		t++;
		scanf("%d%d", &n, &m);
		memset(num, 0, sizeof(num));
		memset(ch, -1, sizeof(ch));
		c = 0;
		for (i = 0; i < m; i++)
		{
			scanf("%d%d", &e[0][i], &e[1][i]);
			u = e[0][i];
			v = e[1][i];
			adj[u][num[u]].id = v;
			adj[u][num[u]++].ip = i;
			adj[v][num[v]].id = u;
			adj[v][num[v]++].ip = i;
			c += bfs(i);
		}
		printf("Case %d: ", t);
		if (c == 2 * (n - 1))
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
	}
	return 0;
}
