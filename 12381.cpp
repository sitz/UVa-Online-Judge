#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10010;

struct Rank
{
	int a, b;
	int id;
	bool operator<(const Rank &r) const
	{
		if (a == r.a && b == r.b)
		{
			return id > r.id;
		}
		else if (a == r.a)
		{
			return b > r.b;
		}
		else
		{
			return a > r.a;
		}
	}
} rank_[MAXN];

inline int EPS(double x, double y)
{
	if (fabs(x - y) < 1e-8)
	{
		return 0;
	}
	return x < y ? -1 : 1;
}
struct Pass
{
	int from, to;
	double k;
	Pass(int from, int to, double k) : from(from), to(to), k(k) {}
	bool operator<(const Pass &p) const
	{
		return EPS(k, p.k) > 0;
	}
};

int n, m;
vector<Pass> vec;

int main()
{
	int cas;
	scanf("%d", &cas);
	while (cas--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d", &rank_[i].a, &rank_[i].b);
			rank_[i].id = i;
		}
		vec.clear();
		for (int i = 0; i < m; ++i)
		{
			for (int j = m; j < n; ++j)
			{
				if (rank_[i].a > rank_[j].a && rank_[i].b < rank_[j].b)
				{
					vec.push_back(Pass(j, i, (rank_[j].b - rank_[i].b + 0.0) / (rank_[i].a - rank_[j].a)));
				}
				else if (rank_[i].a < rank_[j].a && rank_[j].b < rank_[i].b)
				{
					vec.push_back(Pass(i, j, (rank_[i].b - rank_[j].b + 0.0) / (rank_[j].a - rank_[i].a)));
				}
			}
		}
		if (n <= 1)
		{
			printf("0.0000\n");
			continue;
		}
		sort(rank_, rank_ + n);
		long long ans = 0, tmp = 0;
		for (int i = 0; i < n - 1; ++i)
		{
			if (rank_[i].id < m)
			{
				tmp++;
			}
			ans += tmp;
		}
		sort(vec.begin(), vec.end());
		int len = vec.size();
		tmp = ans;
		for (int i = 0, j; i < len; i = j)
		{
			for (j = i; j < len; ++j)
			{
				if (EPS(vec[i].k, vec[j].k) != 0)
				{
					break;
				}
				if (vec[j].from < m)
				{
					tmp++;
				}
				else
				{
					tmp--;
				}
			}
			ans = max(ans, tmp);
		}
		printf("%.4f\n", ans / (n - 1.0));
	}
	return 0;
}
