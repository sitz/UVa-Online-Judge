#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000005;

bool is[MAX];
vector<int> p;
vector<pair<int, int>> v;

void pri()
{
	int i, j;
	p.clear();
	for (i = 2; i < MAX; i++)
	{
		if (!is[i])
		{
			for (j = i + i; j < MAX; j += i)
			{
				is[j] = true;
			}
			p.push_back(i);
		}
	}
}

int main()
{
	int i, j;
	long long n, tmp, N;
	pri();
	while (scanf(" %lld", &n) == 1 && n)
	{
		v.clear();
		tmp = sqrt(n);
		N = n;
		i = 0;
		while (i < p.size() && p[i] <= tmp && N > 1)
		{
			if (N % p[i] == 0)
			{
				v.push_back(make_pair(p[i], 0));
				while (N % p[i] == 0)
				{
					v[v.size() - 1].second++;
					N /= p[i];
				}
			}
			i++;
		}
		if (N != 1)
		{
			v.push_back(make_pair(N, 1));
		}
		//
		long long ans = 0, temp = -1;
		for (j = 1; temp != 0; j++)
		{
			temp = 1;
			for (i = 0; i < v.size(); i++)
			{
				//printf("%d %d\n",v[i].first,v[i].second);
				temp *= ((v[i].second / j) + 1);
			}
			temp -= 1;
			ans += temp;
		}
		printf("%lld %lld\n", n, ans);
	}
	return 0;
}
