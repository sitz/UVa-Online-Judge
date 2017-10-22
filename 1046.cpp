#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef pair<int, int> PII;

const int N = 1005;

int n, m, th, tm_, v[N];
PII a[N], b[N];

bool cmp(PII a, PII b)
{
	return a.first > b.first || (a.first == b.first && a.second > b.second);
}

int main()
{
	int ri = 0;
	while (scanf("%d", &n) && n)
	{
		int sum = 0;
		rep(i, n)
		{
			scanf("%d%d", &a[i].first, &a[i].second);
			sum += a[i].first;
		}
		sort(a, a + n, cmp);
		scanf("%d", &m);
		rep(i, m)
		{
			scanf("%d%d:%d", &b[i].first, &th, &tm_);
			b[i].second = (th - 14) * 60 + tm_;
		}
		memset(v, 0, sizeof(v));
		int res1 = 0, res2 = 0;
		rep(i, n)
		{
			int c = -1;
			rep(j, m)
			{
				if (!v[j] && b[j].first >= a[i].first && b[j].second >= a[i].second)
				{
					if (c == -1 || b[j].second < b[c].second)
					{
						c = j;
					}
				}
			}
			if (c != -1)
			{
				v[c] = 1;
				res1++;
				res2 += a[i].first;
			}
		}
		printf("Trial %d: %d %d\n\n", ++ri, n - res1, sum - res2);
	}
	return 0;
}
