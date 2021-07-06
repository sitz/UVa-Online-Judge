#include <bits/stdc++.h>

using namespace std;

const int MOD = 100007;

struct pp
{
	int id, dig, ip;
};
pp adj[11][11], nw;

struct sta
{
	int pos[11];
};
sta now;

struct re
{
	char str[13];
	int len;
	bool operator<(const re &temp) const
	{
		return strcmp(str, temp.str) < 0;
	}
};
re res[1 << 11];

bool have_esc[1 << 11], vi[11], can[11][11];
int n, m, num[11], dig[11], cnt_dig, sum, ns, tr[11][1 << 10], num_tr[11], vis[11], num_ans, comb[1 << 11], num_com, at[10], num_h[MOD];
long long hash_[MOD][107];

bool dfs(int state, int iden, int deep)
{
	int i, j, s, p, q, id, ip, nt, idd, vv, la, nst;
	long long st;
	sta nw;
	nt = 0;
	st = 0;
	int mt = 0;
	for (i = 0; i < 9; i++)
	{
		id = now.pos[i];
		st = (long long)n * st + id;
		if (id == n - 1)
		{
			nt++;
		}
		if (can[id][n - 1])
		{
			mt++;
		}
	}
	if (mt < num_ans)
	{
		return false;
	}
	st = (1LL << m) * st + state;
	if (num_ans < nt)
	{
		num_ans = nt;
		num_com = 1;
		have_esc[at[n - 1]] = true;
		comb[0] = at[n - 1];
	}
	else if (num_ans == nt && nt > 0 && !have_esc[at[n - 1]])
	{
		comb[num_com++] = at[n - 1];
		have_esc[at[n - 1]] = true;
	}
	if (num_ans == 9)
	{
		return true;
	}
	la = (int)(st % MOD);
	for (i = 0; i < num_h[la]; i++)
	{
		if (hash_[la][i])
		{
			return false;
		}
	}
	hash_[la][num_h[la]++] = st;
	for (int ii = iden; ii < iden + n; ii++)
	{
		i = ii % n;
		if (!can[i][n - 1])
		{
			continue;
		}
		for (j = 0; j < num[i]; j++)
		{
			id = i;
			vv = adj[i][j].dig;
			ip = adj[i][j].ip;
			idd = adj[i][j].id;
			if (vv == 0 || !(state & (1 << ip)))
			{
				if (vv != 0)
				{
					state |= (1 << ip);
				}
				for (s = 0; s < num_tr[vv]; s++)
				{
					nst = (at[id] & tr[vv][s]);
					if (nst != tr[vv][s])
					{
						continue;
					}
					at[id] ^= nst;
					at[idd] |= nst;
					for (p = 0; p < 9; p++)
					{
						if (nst & (1 << p))
						{
							now.pos[p] = idd;
						}
					}
					if (dfs(state, i, deep + 1))
					{
						return true;
					}
					at[id] |= nst;
					at[idd] ^= nst;
					for (p = 0; p < 9; p++)
					{
						if (nst & (1 << p))
						{
							now.pos[p] = id;
						}
					}
				}
				if (vv != 0)
				{
					state ^= (1 << ip);
				}
			}
		}
	}
	return false;
}
void get_to(int id, int ip)
{
	if (can[id][ip])
	{
		return;
	}
	can[id][ip] = true;
	int i, j, s, p, q;
	for (i = 0; i < num[ip]; i++)
	{
		get_to(id, adj[ip][i].id);
	}
}
int main()
{
	int i, j, s, p, q, u, v, d, id;
	memset(num_tr, 0, sizeof(num_tr));
	for (i = 1; i < (1 << 9); i++)
	{
		cnt_dig = 0;
		for (j = 0; j < 9; j++)
		{
			if (i & (1 << j))
			{
				dig[cnt_dig++] = j + 1;
			}
		}
		if (cnt_dig > 5 || cnt_dig < 3)
		{
			continue;
		}
		sum = 0;
		for (j = 0; j < cnt_dig; j++)
		{
			sum += dig[j];
		}
		while (sum >= 10)
		{
			ns = 0;
			while (sum)
			{
				ns += sum % 10;
				sum /= 10;
			}
			sum = ns;
		}
		tr[sum][num_tr[sum]++] = i;
	}
	for (i = 1; i <= 9; i++)
	{
		tr[0][num_tr[0]++] = (1 << (i - 1));
	}
	for (i = 0; i < 10; i++)
	{
		sort(tr[i], tr[i] + num_tr[i]);
	}
	while (scanf("%d%d", &n, &m) == 2)
	{
		memset(num, 0, sizeof(num));
		for (i = 0; i < m; i++)
		{
			scanf("%d%d%d", &u, &v, &d);
			u--;
			v--;
			nw.id = v;
			nw.dig = d;
			nw.ip = i;
			adj[u][num[u]++] = nw;
			dig[i] = d;
		}
		memset(can, false, sizeof(can));
		for (i = 0; i < n; i++)
		{
			get_to(i, i);
		}
		memset(vis, -1, sizeof(vis));
		for (i = 0; i < 9; i++)
		{
			now.pos[i] = 0;
		}
		num_ans = 0;
		memset(have_esc, false, sizeof(have_esc));
		memset(at, 0, sizeof(at));
		at[0] = (1 << 9) - 1;
		num_com = 0;
		memset(num_h, 0, sizeof(num_h));
		dfs(0, 0, 0);
		for (i = 0; i < num_com; i++)
		{
			id = comb[i];
			res[i].len = 0;
			for (j = 0; j < 9; j++)
			{
				if (id & (1 << j))
				{
					res[i].str[res[i].len++] = j + 1 + '0';
				}
			}
			res[i].str[res[i].len] = 0;
		}
		sort(res, res + num_com);
		printf("%d", num_ans);
		for (i = 0; i < num_com; i++)
		{
			printf(" ");
			printf("%s", res[i].str);
		}
		printf("\n");
	}
	return 0;
}
