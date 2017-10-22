#include <bits/stdc++.h>

using namespace std;

int n, m, k, iden[1111], num_now, base = 10000;

struct bignum
{
	int value[1111], num;
};
bignum ans;

bignum operator*(bignum a, int x)
{
	int i, j, s, p, q;
	bignum res;
	res.value[0] = 0;
	for (i = 0; i < a.num; i++)
	{
		res.value[i] += a.value[i] * x;
		res.value[i + 1] = res.value[i] / base;
		res.value[i] %= base;
	}
	if (res.value[i] > 0)
	{
		i++;
	}
	res.num = i;
	return res;
}

struct pp
{
	int num, lst[202];
	bool operator<(const pp &temp) const
	{
		for (int i = 0; i < num && i < temp.num; i++)
		{
			if (lst[i] < temp.lst[i])
			{
				return true;
			}
			if (lst[i] > temp.lst[i])
			{
				return false;
			}
		}
		if (num < temp.num)
		{
			return true;
		}
		if (num > temp.num)
		{
			return false;
		}
		return false;
	}
	bool operator==(const pp &temp) const
	{
		if (num != temp.num)
		{
			return false;
		}
		for (int i = 0; i < num; i++)
		{
			if (lst[i] != temp.lst[i])
			{
				return false;
			}
		}
		return true;
	}
};
pp sg[1111];

struct qq
{
	pp ox[201];
	int num;
};
qq rs[1001], now[222];

map<pp, int> hs;

int node;

pp operator*(pp a, pp b)
{
	int i, j, s, p, q;
	pp res;
	i = j = 0;
	res.num = 0;
	while (i < a.num && j < b.num)
	{
		if (a.lst[i] < b.lst[j])
		{
			i++;
		}
		else if (a.lst[i] > b.lst[j])
		{
			j++;
		}
		else
		{
			res.lst[res.num++] = a.lst[i];
			i++;
			j++;
		}
	}
	return res;
}
pp operator+(pp a, pp b)
{
	int i, j, s, p, q, ff;
	pp res;
	i = j = 0;
	res.num = 0;
	while (i < a.num || j < b.num)
	{
		ff = 0;
		if ((j >= b.num) || (i < a.num && j < b.num && a.lst[i] < b.lst[j]))
		{
			ff = -1;
		}
		else if ((i >= a.num) || (i < a.num && j < b.num && a.lst[i] > b.lst[j]))
		{
			ff = 1;
		}
		if (ff == 0)
		{
			i++;
			j++;
		}
		else if (ff < 0)
		{
			res.lst[res.num++] = a.lst[i];
			i++;
		}
		else
		{
			res.lst[res.num++] = b.lst[j];
			j++;
		}
	}
	return res;
}
struct nod
{
	int adj[1001], deg, flag;
	bool rev;
};
nod tree[1001];
bool vis[1111];
void rever(int id)
{
	int i, j, s, p, q;
	for (i = 0; i < tree[id].deg; i++)
	{
		rever(tree[id].adj[i]);
	}
	for (i = 0; i < tree[id].deg / 2; i++)
	{
		swap(tree[id].adj[i], tree[id].adj[tree[id].deg - 1 - i]);
	}
}
bool judge(pp nw, int id, int flag, int pre)
{
	int i, j, s, p, q, nc = 0, ix[2], l = -1, r = -1, np = 0, dx = -1, nflag, ip, im, nst[221], iden[221];
	int ll = tree[id].deg, rr = -1, lx = tree[id].deg, rx = -1;
	pp now, tw;
	for (i = 0; i < tree[id].deg; i++)
	{
		now = nw * sg[tree[id].adj[i]];
		if (now.num > 0 && !(now == sg[tree[id].adj[i]]))
		{
			nc++;
			if (l < 0)
			{
				l = np;
			}
			else
			{
				r = np;
			}
		}
		else if (now.num > 0)
		{
			if (lx > i)
			{
				lx = i;
			}
			if (rx < i)
			{
				rx = i;
			}
		}
		if (now.num > 0)
		{
			if (ll > i)
			{
				ll = i;
			}
			if (rr < i)
			{
				rr = i;
			}
			nst[np++] = tree[id].adj[i];
			if (tree[id].flag)
			{
				if (dx < 0)
				{
					dx = i + 1 - np;
				}
				else if (dx != i + 1 - np)
				{
					return false;
				}
			}
		}
	}
	if ((flag && nc > 1) || nc > 2)
	{
		return false;
	}
	if (tree[id].flag)
	{
		if (l == np - 1)
		{
			swap(l, r);
		}
	}
	if (tree[id].flag && ((l != 0 && l >= 0) || (r != np - 1 && r >= 0)))
	{
		return false;
	}
	if (tree[id].flag && flag != 0)
	{
		if (pre == 0)
		{
			if (flag > 0)
			{
				if ((rx == tree[id].deg - 1) || (np == 1 && nc == 1 && nst[0] == tree[id].adj[tree[id].deg - 1]))
				{
					rever(id);
					if (np - nc > 0)
					{
						swap(lx, rx);
						lx = tree[id].deg - 1 - lx;
						rx = tree[id].deg - 1 - rx;
					}
					swap(ll, rr);
					ll = tree[id].deg - 1 - ll;
					rr = tree[id].deg - 1 - rr;
					swap(l, r);
					if (l >= 0)
					{
						l = np - 1 - l;
					}
					if (r >= 0)
					{
						r = np - 1 - r;
					}
					for (i = 0; i < np / 2; i++)
					{
						swap(nst[i], nst[np - 1 - i]);
					}
				}
			}
			else if (flag < 0)
			{
				if (lx == 0 || (np == 1 && nc == 1 && nst[0] == tree[id].adj[0]))
				{
					rever(id);
					if (np - nc > 0)
					{
						swap(lx, rx);
						lx = tree[id].deg - 1 - lx;
						rx = tree[id].deg - 1 - rx;
					}
					swap(ll, rr);
					ll = tree[id].deg - 1 - ll;
					rr = tree[id].deg - 1 - rr;
					swap(l, r);
					if (l >= 0)
					{
						l = np - 1 - l;
					}
					if (r >= 0)
					{
						r = np - 1 - r;
					}
					for (i = 0; i < np / 2; i++)
					{
						swap(nst[i], nst[np - 1 - i]);
					}
				}
			}
		}
		if (flag > 0 && lx != 0)
		{
			if (!(np - nc == 0 && nc == 1 && nst[0] == tree[id].adj[0]))
			{
				return false;
			}
		}
		if (flag < 0 && rx != tree[id].deg - 1)
		{
			if (!(np - nc == 0 && nc == 1 && nst[0] == tree[id].adj[tree[id].deg - 1]))
			{
				return false;
			}
		}
	}
	nc = 0;
	for (i = 0; i < np; i++)
	{
		if (i == l || i == r)
		{
			tw = nw * sg[nst[i]];
			if (tw == nw && flag == 0)
			{
				nflag = 0;
			}
			else
			{
				if (flag != 0)
				{
					nflag = flag;
				}
				else if (l == i)
				{
					nflag = -1;
				}
				else
				{
					nflag = 1;
				}
			}
			if (!judge(tw, nst[i], nflag, tree[id].flag))
			{
				return false;
			}
		}
	}
	if ((flag > 0 && tree[id].flag && l >= 0 && (ll != rr)) || (flag < 0 && tree[id].flag && r >= 0 && (ll != rr)))
	{
		return false;
	}
	return true;
}
int insert(pp nw, int id, int flag)
{
	int i, j, s, p, q, nc = 0, ix[2], l = -1, r = -1, np = 0, dx = -1, nflag, ip, im, nst[201];
	int ll = tree[id].deg, rr = -1, lx = -1, rx = -1;
	pp now, tw;
	for (i = 0; i < tree[id].deg; i++)
	{
		now = nw * sg[tree[id].adj[i]];
		if (now.num > 0 && !(now == sg[tree[id].adj[i]]))
		{
			nc++;
			if (l < 0)
			{
				l = np;
			}
			else
			{
				r = np;
			}
		}
		if (now.num > 0)
		{
			if (ll > i)
			{
				ll = i;
			}
			if (rr < i)
			{
				rr = i;
			}
			nst[np++] = tree[id].adj[i];
		}
	}
	if (tree[id].flag)
	{
		if (l == np - 1)
		{
			swap(l, r);
		}
	}
	nc = 0;
	for (i = 0; i < np; i++)
	{
		if (i == l || i == r)
		{
			tw = nw * sg[nst[i]];
			if (tw == nw && flag == 0)
			{
				nflag = 0;
			}
			else
			{
				if (flag != 0)
				{
					nflag = flag;
				}
				else if (l == i)
				{
					nflag = -1;
				}
				else
				{
					nflag = 1;
				}
			}
			ix[nc++] = insert(tw, nst[i], nflag);
			if (i == l)
			{
				lx = ix[nc - 1];
			}
			if (i == r)
			{
				rx = ix[nc - 1];
			}
		}
	}
	now.num = 0;
	for (i = 0; i < np; i++)
	{
		if (l != i && r != i)
		{
			now = now + sg[nst[i]];
		}
	}
	if (!hs.count(now))
	{
		hs[now] = node;
		while (node >= 1000)
		{
			puts("orz");
		}
		sg[node++] = now;
		ip = node - 1;
	}
	else
	{
		ip = hs[now];
	}
	if (now.num > 0)
	{
		for (i = 0; i < np; i++)
		{
			if (l != i && r != i)
			{
				if (ip == nst[i])
				{
					break;
				}
			}
		}
		if (i >= np)
		{
			tree[ip].deg = 0;
			tree[ip].flag = tree[id].flag;
			for (i = 0; i < np; i++)
			{
				if (l != i && r != i)
				{
					if (sg[nst[i]].num > 0)
					{
						tree[ip].adj[tree[ip].deg++] = nst[i];
					}
				}
			}
		}
	}
	for (i = 0; i < nc; i++)
	{
		now = now + sg[ix[i]];
	}
	if (!hs.count(now))
	{
		hs[now] = node;
		while (node >= 1000)
		{
			puts("Orz");
		}
		sg[node++] = now;
		im = node - 1;
	}
	else
	{
		im = hs[now];
	}
	if (im != ip)
	{
		bool go = true;
		if (nc > 0 && im == ix[0])
		{
			go = false;
		}
		if (nc > 1 && im == ix[1])
		{
			go = false;
		}
		if (go)
		{
			tree[im].deg = 0;
			if (lx >= 0 && im != lx)
			{
				tree[im].adj[tree[im].deg++] = lx;
			}
			if (sg[ip].num > 0)
			{
				tree[im].adj[tree[im].deg++] = ip;
			}
			if (rx >= 0 && im != rx)
			{
				tree[im].adj[tree[im].deg++] = rx;
			}
			tree[im].flag = tree[id].flag;
			if (flag != 0 || (nc > 0 && np > 1))
			{
				tree[im].flag = 1;
			}
		}
	}
	if (im == id)
	{
		return id;
	}
	if (flag == 0 || tree[id].flag)
	{
		if (tree[id].flag)
		{
			int ndeg = 0;
			for (i = ll + 1; i + rr - ll < tree[id].deg; i++)
			{
				tree[id].adj[i] = tree[id].adj[i + rr - ll];
			}
			tree[id].deg = i;
			tree[id].adj[ll] = im;
		}
		else
		{
			int ndeg = 0;
			for (i = 0; i < tree[id].deg; i++)
			{
				vis[tree[id].adj[i]] = false;
			}
			for (i = 0; i < np; i++)
			{
				vis[nst[i]] = true;
			}
			for (i = 0; i < tree[id].deg; i++)
			{
				if (!vis[tree[id].adj[i]])
				{
					tree[id].adj[ndeg++] = tree[id].adj[i];
				}
			}
			if (sg[im].num != 0)
			{
				tree[id].adj[ndeg++] = im;
			}
			tree[id].deg = ndeg;
		}
	}
	else
	{
		for (i = 0; i < tree[id].deg; i++)
		{
			vis[tree[id].adj[i]] = false;
		}
		for (i = 0; i < np; i++)
		{
			vis[nst[i]] = true;
		}
		now.num = 0;
		for (i = 0; i < tree[id].deg; i++)
		{
			if (!vis[tree[id].adj[i]])
			{
				now = now + sg[tree[id].adj[i]];
			}
		}
		if (!hs.count(now))
		{
			hs[now] = node;
			while (node >= 1000)
			{
				puts("orz");
			}
			sg[node++] = now;
			ip = node - 1;
		}
		else
		{
			ip = hs[now];
		}
		if (now.num > 0)
		{
			tree[ip].flag = false;
			for (i = 0; i < tree[id].deg; i++)
			{
				if (!vis[tree[id].adj[i]] && (ip == tree[id].adj[i]))
				{
					break;
				}
			}
			if (i >= tree[id].deg)
			{
				tree[ip].deg = 0;
				for (i = 0; i < tree[id].deg; i++)
				{
					if (!vis[tree[id].adj[i]])
					{
						tree[ip].adj[tree[ip].deg++] = tree[id].adj[i];
					}
				}
			}
		}
		if (ip == id)
		{
			return id;
		}
		tree[id].deg = 2;
		tree[id].flag = true;
		if (flag < 0)
		{
			tree[id].adj[0] = ip;
			tree[id].adj[1] = im;
		}
		else
		{
			tree[id].adj[0] = im;
			tree[id].adj[1] = ip;
		}
	}
	return id;
}
void dfs(int id)
{
	int i, j, s, p, q, ip;
	vis[id] = true;
	if (!tree[id].flag)
	{
		for (i = 2; i <= tree[id].deg; i++)
		{
			ans = ans * i;
		}
	}
	for (i = 0; i < tree[id].deg; i++)
	{
		ip = tree[id].adj[i];
		while (vis[ip])
		{
			puts("orz");
		}
		dfs(tree[id].adj[i]);
		if (!tree[id].flag && tree[ip].flag)
		{
			ans = ans * 2;
		}
	}
}
void tri(int iden, int id, int up, int flag)
{
	int i, j, s, p, q, ip, nx;
	if (id >= up)
	{
		for (i = 0; i < now[id].num; i++)
		{
			rs[iden].ox[rs[iden].num++] = now[id].ox[i];
		}
		return;
	}
	for (i = 0; i < up; i++)
	{
		if (!vis[i])
		{
			vis[i] = true;
			ip = tree[iden].adj[i];
			nx = 0;
			for (p = 0; p < now[id].num; p++)
				for (q = 0; q < rs[ip].num; q++)
				{
					now[id + 1].ox[nx] = now[id].ox[p];
					for (j = 0; j < rs[ip].ox[q].num; j++)
					{
						now[id + 1].ox[nx].lst[now[id + 1].ox[nx].num++] = rs[ip].ox[q].lst[j];
					}
					nx++;
				}
			now[id + 1].num = nx;
			tri(iden, id + 1, up, flag);
			vis[i] = false;
			if (flag)
			{
				return;
			}
		}
	}
}
void display(int id)
{
	int i, j, s, p, q, ip, nu;
	for (i = 0; i < tree[id].deg; i++)
	{
		ip = tree[id].adj[i];
		display(ip);
		if (!tree[id].flag && tree[ip].flag)
		{
			nu = rs[ip].num;
			for (j = 0; j < rs[ip].num; j++)
			{
				rs[ip].ox[nu] = rs[ip].ox[j];
				int nx = rs[ip].ox[nu].num;
				for (s = 0; s < rs[ip].ox[nu].num / 2; s++)
				{
					swap(rs[ip].ox[nu].lst[s], rs[ip].ox[nu].lst[nx - s - 1]);
				}
				nu++;
			}
			rs[ip].num = nu;
		}
		vis[i] = false;
	}
	if (tree[id].deg == 0)
	{
		rs[id].num = 1;
		rs[id].ox[0] = sg[id];
	}
	else
	{
		rs[id].num = 0;
		now[0].num = 1;
		now[0].ox[0].num = 0;
		tri(id, 0, tree[id].deg, tree[id].flag);
	}
}
void out(bignum xy)
{
	int i;
	for (i = xy.num - 1; i >= 0; i--)
	{
		if (i == xy.num - 1)
		{
			printf("%d", xy.value[i]);
		}
		else
		{
			printf("%04d", xy.value[i]);
		}
	}
	printf("\n");
}

int main()
{
	int i, j, s, p, q, vv, id;
	pp nw;
	while (scanf("%d%d%d", &n, &m, &k) == 3)
	{
		hs.clear();
		node = 0;
		for (i = 0; i < n; i++)
		{
			nw.num = 1;
			nw.lst[0] = i;
			hs[nw] = i;
			tree[i].deg = tree[i].flag = tree[i].rev = 0;
			sg[node++] = nw;
		}
		nw.num = n;
		for (i = 0; i < n; i++)
		{
			nw.lst[i] = i;
		}
		hs[nw] = n;
		sg[node++] = nw;
		nw.num = 0;
		hs[nw] = node;
		sg[node++] = nw;
		tree[n].deg = n;
		tree[n].flag = tree[n].rev = 0;
		for (i = 0; i < n; i++)
		{
			tree[n].adj[i] = i;
		}
		for (i = 0; i < m; i++)
		{
			nw.num = 0;
			while (scanf("%d", &vv) && vv != 0)
			{
				nw.lst[nw.num++] = vv - 1;
			}
			sort(nw.lst, nw.lst + nw.num);
			int nr = 0;
			for (j = 0; j < nw.num; j++)
			{
				if (nr == 0 || nw.lst[nr - 1] < nw.lst[j])
				{
					nw.lst[nr++] = nw.lst[j];
				}
			}
			nw.num = nr;
			if (nw.num == 0)
			{
				id = n;
			}
			else if (!judge(nw, n, 0, 0))
			{
				id = -1;
			}
			else
			{
				id = insert(nw, n, 0);
			}
			if (id < 0)
			{
				printf("0\n");
			}
			else
			{
				ans.num = 1;
				ans.value[0] = 1;
				memset(vis, false, sizeof(vis));
				dfs(id);
				if (tree[id].flag)
				{
					ans = ans * 2;
				}
				out(ans);
				if (ans.num == 1 && ans.value[0] <= k)
				{
					display(id);
					if (tree[id].flag)
					{
						int nu = 0, ip = id;
						nu = rs[ip].num;
						for (j = 0; j < rs[ip].num; j++)
						{
							rs[ip].ox[nu] = rs[ip].ox[j];
							int nx = rs[ip].ox[nu].num;
							for (s = 0; s < rs[ip].ox[nu].num / 2; s++)
							{
								swap(rs[ip].ox[nu].lst[s], rs[ip].ox[nu].lst[nx - s - 1]);
							}
							nu++;
						}
						rs[ip].num = nu;
					}
					sort(rs[id].ox, rs[id].ox + rs[id].num);
					while (rs[id].num != ans.value[0])
					{
						puts("orz");
					}
					for (s = 0; s < rs[id].num; s++)
					{
						while (rs[id].ox[s].num != n)
						{
							puts("orz");
						}
						for (j = 0; j < rs[id].ox[s].num; j++)
						{
							if (j > 0)
							{
								putchar(' ');
							}
							printf("%d", rs[id].ox[s].lst[j] + 1);
						}
						printf("\n");
					}
				}
			}
		}
	}
	return 0;
}
