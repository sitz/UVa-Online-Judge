#include <bits/stdc++.h>

using namespace std;
int n, f, b, t;

const int MAXN = 3e3 + 10;
const int MAXB = 1e6 + 10;

vector<int> td, tu;

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d", &n, &f, &b);
		td.clear();
		tu.clear();
		for (int i = 1; i <= n; ++i)
		{
			int fi, bi;
			scanf("%d%d", &fi, &bi);
			if (bi)
			{
				tu.push_back(f - fi);
			}
			else
			{
				td.push_back(fi);
			}
		}
		sort(tu.begin(), tu.end());
		sort(td.begin(), td.end());
		int sz = td.size();
		int ans = 0;
		while (b > sz)
		{
			ans += f;
			swap(tu, td);
			b -= sz;
			sz = td.size();
		}
		ans += td[b - 1] + f;
		printf("%d\n", ans);
	}
	return 0;
}
