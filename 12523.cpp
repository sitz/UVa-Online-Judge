#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-8;

bool Cmp(const pair<int, int> a, const pair<int, int> b)
{
	return a.first > b.first;
}

vector<int> sum;
vector<pair<int, int>> tt;

int main()
{
	int i, s, n, temp, j, a, b;
	while (cin >> s >> n && (s || n))
	{
		tt.clear();
		sum.clear();
		sum.resize(n);
		for (i = 0; i < s; i++)
			for (j = 0; j < n; j++)
			{
				cin >> temp, sum[j] += temp;
			}
		int per, ans;
		per = ans = 0;
		for (i = 0; i < n; i++)
		{
			cin >> a >> b;
			per += a;
			ans += (a * sum[i]);
			tt.push_back(make_pair(sum[i], b - a));
		}
		sort(tt.begin(), tt.end(), Cmp);
		i = 0;
		while ((per + tt[i].second) < 100)
		{
			ans += (tt[i].second * tt[i].first), per += tt[i].second, i++;
		}
		ans += (tt[i].first * (100 - per));
		double anss;
		anss = (double)ans / (double)(100 * s) + EPS;
		printf("%.2f\n", anss);
	}
	return 0;
}
