#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

pair<string, int> str[N];
int t, n, sav[N], height[N], rank_[N], best[N * 10][20];

int main()
{
	int cas = 0;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			cin >> str[i].first;
			sav[i] = str[i].first.length();
			str[i].second = i;
		}
		sort(str, str + n);

		for (int i = 0; i < n; i++)
		{
			rank_[str[i].second] = i;
			if (i == 0)
			{
				continue;
			}
			int len = min(str[i - 1].first.length(), str[i].first.length());
			int j;
			for (j = 0; j < len; j++)
			{
				if (str[i - 1].first[j] != str[i].first[j])
				{
					break;
				}
			}
			height[i] = j;
		}

		for (int i = 0; i < n; i++)
		{
			best[i][0] = height[i];
		}
		for (int j = 1; (1 << j) <= n; j++)
		{
			for (int i = 0; i + (1 << j) - 1 < n; i++)
			{
				best[i][j] = min(best[i][j - 1], best[i + (1 << (j - 1))][j - 1]);
			}
		}

		int q, l, r;
		scanf("%d", &q);
		printf("Case %d:\n", ++cas);
		while (q--)
		{
			scanf("%d%d", &l, &r);
			l--;
			r--;
			if (l == r)
			{
				printf("%d\n", sav[l]);
				continue;
			}
			l = rank_[l];
			r = rank_[r];
			if (l > r)
			{
				swap(l, r);
			}
			l++;
			int k = 0;
			while ((1 << (k + 1)) <= r - l + 1)
			{
				k++;
			}
			printf("%d\n", min(best[l][k], best[r - (1 << k) + 1][k]));
		}
	}
	return 0;
}
