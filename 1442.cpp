#include <bits/stdc++.h>

using namespace std;

const int maxn = 10e6 + 10;
const int inf = 0x3f3f3f3f;
int n, ans;

struct _node
{
	int f, c;
} node[maxn];

int main(void)
{
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &node[i].f);
		}
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &node[i].c);
		}
		int t = inf;
		for (int i = n; i >= 1; --i)
		{
			t = max(node[i].f, t);
			t = min(node[i].c, t);
			node[i].c = t;
		}
		ans = 0;
		t = inf;
		for (int i = 1; i <= n; ++i)
		{
			t = max(node[i].f, t);
			t = min(node[i].c, t);
			ans += (t - node[i].f);
		}
		cout << ans << endl;
	}
	return 0;
}
