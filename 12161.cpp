#include <bits/stdc++.h>

using namespace std;

const int N = 30005;

struct edge {int x, w, l, next;} e[N << 1];

bool f[N];
int n, m, pre[N], mcnt, s[N], ans, ca;
set<pair<int, int>> hash_;
set<pair<int, int>>::iterator it;
vector<pair<int, int>> Vec;

pair<int, int> findcenter(int x, int fa, int size)
{
	s[x] = 1;
	pair<int, int> res = make_pair(1 << 30, -1);
	int mx = 0;
	for (int i = pre[x]; ~i; i = e[i].next)
	{
		int y = e[i].x;
		if (!f[y] && y != fa)
		{
			res = min(res, findcenter(y, x, size));
			mx = max(mx, s[y]), s[x] += s[y];
		}
	}
	return min(res, make_pair(max(mx, size - s[x]), x));
}

void Getdis(int x, int fa, int W, int L)
{
	Vec.push_back(make_pair(W, L));
	if (W < m)
	{
		it = --hash_.upper_bound(make_pair(m - W, 1 << 30));
		ans = max(ans, L + it->second);
	}
	for (int i = pre[x]; ~i; i = e[i].next)
	{
		int y = e[i].x;
		if (!f[y] && y != fa)
		{
			Getdis(y, x, W + e[i].w, L + e[i].l);
		}
	}
}

void divide(int x, int size)
{
	x = findcenter(x, 0, size).second;
	f[x] = 1;
	hash_.insert(make_pair(0, 0));
	for (int i = pre[x]; ~i; i = e[i].next)
	{
		int y = e[i].x;
		if (!f[y])
		{
			Getdis(y, x, e[i].w, e[i].l);
			while (!Vec.empty())
			{
				pair<int, int> A = Vec.back();
				Vec.pop_back();
				it = --hash_.upper_bound(A);
				if (it->second >= A.second)
				{
					continue;
				}
				hash_.insert(A);
				do
				{
					it = hash_.upper_bound(A);
					if (it != hash_.end() && A.second >= it->second)
					{
						hash_.erase(it);
					}
					else
					{
						break;
					}
				} while (1);
			}
		}
	}
	hash_.clear();
	for (int i = pre[x]; ~i; i = e[i].next)
	{
		int y = e[i].x;
		if (!f[y])
		{
			divide(y, s[y]);
		}
	}
}

void work()
{
	int i, j, k, x, y;
	scanf("%d%d", &n, &m);
	memset(pre, -1, sizeof(pre)), mcnt = 0;
	for (i = 1; i < n; ++i)
	{
		scanf("%d%d%d%d", &x, &y, &j, &k);
		e[mcnt] = (edge){y, j, k, pre[x]}, pre[x] = mcnt++;
		e[mcnt] = (edge){x, j, k, pre[y]}, pre[y] = mcnt++;
	}
	memset(f, 0, sizeof(f));
	ans = 0;
	divide(1, n);
	printf("Case %d: %d\n", ++ca, ans);
}

int main()
{
	int _;
	scanf("%d", &_);
	while (_--)
	{
		work();
	}
	return 0;
}
