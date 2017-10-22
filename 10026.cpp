#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int(i) = int(a); (i) < int(b); (i)++)
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) ((int)(a).size())
#define pb push_back
#define mp make_pair

inline bool by_key_desc_val_asc(const pair<double, int> &a, const pair<double, int> &b)
{
	if (a.first == b.first)
	{
		return a.second < b.second;
	}
	return a.first > b.first;
}

static int cases, n, t, f;
static vector<pair<double, int>> v;

int main()
{
	scanf("%d", &cases);
	while (cases--)
	{
		scanf("%d", &n);
		v.clear();
		FOR(i, 0, n)
		{
			scanf("%d%d", &t, &f);
			v.pb(mp(f * 1.0 / t, i + 1));
		}
		sort(ALL(v), by_key_desc_val_asc);
		int sz = SZ(v);
		FOR(i, 0, sz)
		{
			if (i > 0)
			{
				printf(" ");
			}
			printf("%d", v[i].second);
		}
		printf("\n");
		if (cases)
		{
			printf("\n");
		}
	}
	return 0;
}
