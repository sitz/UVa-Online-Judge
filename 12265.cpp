#include <bits/stdc++.h>

using namespace std;

#define P pair<int, int>

int n, m;
char s[1001][1001];
int mh[1001][1001];

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			scanf("%s", s[i]);
			for (int j = 0; j < m; j++)
			{
				if (s[i][j] == '#')
				{
					mh[i][j] = 0;
				}
				else
				{
					if (!i)
					{
						mh[i][j] = 1;
					}
					else
					{
						mh[i][j] = mh[i - 1][j] + 1;
					}
				}
			}
		}
		int ans[5000] = {0};
		for (int i = 0; i < n; i++)
		{
			P p[1001];
			for (int j = 0; j < m; j++)
			{
				p[j].first = mh[i][j];
				p[j].second = j;
			}
			sort(p, p + m);
			set<int> st;
			int H[1001] = {0}, L[1001] = {0};
			for (int j = 0; j < m; j++)
			{
				if (!p[j].first)
				{
					st.insert(p[j].second);
					continue;
				}
				int x = p[j].second;
				set<int>::iterator it = st.lower_bound(p[j].second);
				if (it != st.begin())
				{
					it--;
					int h1 = H[*it] + L[*it] + p[j].second - *it;
					int h2 = p[j].first + p[j].second - *it;
					if (h1 >= h2)
					{
						H[x] = H[*it];
						L[x] = L[*it] + p[j].second - *it;
					}
					else
					{
						H[x] = p[j].first;
						L[x] = p[j].second - *it;
					}
				}
				else
				{
					H[x] = p[j].first;
					L[x] = p[j].second + 1;
				}
				st.insert(x);
				int k = (H[x] + L[x]) * 2;
				ans[k]++;
			}
		}
		for (int i = 1; i < 5000; i++)
		{
			if (ans[i])
			{
				printf("%d x %d\n", ans[i], i);
			}
		}
	}
	return 0;
}
