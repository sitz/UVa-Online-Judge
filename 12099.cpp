#include <bits/stdc++.h>

using namespace std;

/* Sample solution for NWERC'06: The Bookcase
 * Author: Per Austrin
 */

typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 0x1f1f1f1f;
const int MAX2 = 1700;

pii books[100];
int tsum[100], minh[2000000];

int encode(int w1, int w2, int w3)
{
	w3 -= w1 + w2;
	if (w3 < w2)
	{
		swap(w3, w2);
	}
	if (w2 < w1)
	{
		swap(w2, w1);
	}
	if (w3 < w2)
	{
		swap(w3, w2);
	}
	return MAX2 * w1 + w2;
}

int main()
{
	int t, n;
	for (scanf("%d", &t); scanf("%d", &n) && t--;)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d", &books[i].first, &books[i].second);
		}
		sort(books, books + n, greater<pii>());
		tsum[0] = books[0].second;
		for (int i = 1; i < n; ++i)
		{
			tsum[i] = tsum[i - 1] + books[i].second;
		}
		vi idxs, nidxs;
		memset(minh, inf, sizeof(minh));
		minh[0] = books[0].first;
		idxs.push_back(0);
		int ans = 1 << 30;
		int kills = 0;
		for (int i = 1; i < n; ++i)
		{
			kills = 0;
			sort(idxs.begin(), idxs.end());
			nidxs.clear();
			for (int j = idxs.size(); j--;)
			{
				int idx = idxs[j];
				int w1 = idx / MAX2, w2 = idx % MAX2;
				int H = minh[idx], st;
				// These two if statements are just pruning, their only
				// purpose is to speed up the solution.
				if (w1)
				{
					ans = min(ans, H * max(tsum[n - 1] - w1 - w2, max(w1, w2)));
				}
				if (H * max(tsum[i - 1] - w1 - w2, max(w1, w2)) >= ans)
				{
					++kills;
					minh[idx] = inf;
					continue;
				}
				nidxs.push_back(idx);
				st = encode(w1 + books[i].second, w2, tsum[i]);
				if (minh[st] == inf)
				{
					nidxs.push_back(st);
				}
				minh[st] = min(minh[st], H + (w1 ? 0 : books[i].first));
				st = encode(w1, w2 + books[i].second, tsum[i]);
				if (minh[st] == inf)
				{
					nidxs.push_back(st);
				}
				minh[st] = min(minh[st], H + (w2 ? 0 : books[i].first));
			}
			idxs.swap(nidxs);
		}
		for (vi::iterator it = idxs.begin(); it != idxs.end(); ++it)
		{
			int w1 = *it / MAX2, w2 = *it % MAX2;
			if (w1)
			{
				ans = min(ans, minh[*it] * max(tsum[n - 1] - w1 - w2, max(w1, w2)));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
