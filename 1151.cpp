#include <bits/stdc++.h>

using namespace std;

//#pragma comment(linker, "/STACK:16777216")

typedef long long LL;
const int N = 1005;

int n, q, ca;
int C[10];
vector<int> Z[10];
pair<int, int> a[N];
vector<pair<int, int>> E;
pair<int, int> d[N];
int f[N];
int getf(int x)
{
	return x == f[x] ? x : f[x] = getf(f[x]);
}
inline int dist(int i, int j)
{
	return (a[i].first - a[j].first) * (a[i].first - a[j].first) + (a[i].second - a[j].second) * (a[i].second - a[j].second);
}
bool cmp(pair<int, int> A, pair<int, int> B)
{
	return dist(A.first, A.second) < dist(B.first, B.second);
}

void work()
{
	if (ca++)
	{
		puts("");
	}
	int i, j, k, x, y;
	scanf("%d%d", &n, &q);
	for (i = 0; i < q; ++i)
	{
		scanf("%d%d", &y, &C[i]);
		Z[i].resize(y);
		for (j = 0; j < y; ++j)
		{
			scanf("%d", &Z[i][j]);
		}
	}
	for (i = 1; i <= n; ++i)
	{
		scanf("%d%d", &a[i].first, &a[i].second);
		d[i] = make_pair(1 << 30, 0), f[i] = 0;
	}
	int ans = 1 << 30;
	d[1].first = 0, E.clear();
	while (1)
	{
		x = -1;
		for (i = 1; i <= n; ++i)
			if (!f[i] && (!~x || d[i] < d[x]))
			{
				x = i;
			}
		if (!~x)
		{
			break;
		}
		f[x] = 1;
		if (d[x].second)
		{
			E.push_back(make_pair(d[x].second, x));
		}
		for (i = 1; i <= n; ++i)
			if (!f[i])
			{
				d[i] = min(d[i], make_pair(dist(x, i), x));
			}
	}
	sort(E.begin(), E.end(), cmp);
	for (k = 0; k < 1 << q; ++k)
	{
		int sum = 0;
		for (i = 1; i <= n; ++i)
		{
			f[i] = i;
		}
		for (i = 0; i < q; ++i)
		{
			if (k >> i & 1)
			{
				sum += C[i];
				for (j = 1; j < Z[i].size(); ++j)
				{
					f[getf(Z[i][j])] = getf(Z[i][j - 1]);
				}
			}
		}
		for (i = 0; i < n - 1; ++i)
		{
			x = E[i].first, y = E[i].second;
			if (getf(x) != getf(y))
			{
				sum += dist(x, y);
				f[getf(x)] = getf(y);
			}
		}
		ans = min(ans, sum);
	}
	printf("%d\n", ans);
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
