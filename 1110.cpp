#include <bits/stdc++.h>

using namespace std;

struct rec
{
	int num;
	int base, type;
} a[400];
int cmp(rec a, rec b)
{
	return a.num < b.num;
}
char f[321][1000001];
int c, cnt, max;
char tmp[10];
std::vector<rec> ans, now;
int anscnt;
void solve()
{
	if (f[cnt][c] > 100)
	{
		puts("impossible");
		return;
	}
	int pre = cnt;
	ans.clear();
	for (int i = cnt - 1; i >= 0; i--)
		if (a[i].num <= c && f[i][c - a[i].num] + 1 == f[pre][c])
		{
			ans.push_back(a[i]), c -= a[i].num, pre = i;
		}
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d%c%c", ans[i].base, "HL"[ans[i].type], " \n"[i == ans.size() - 1]);
	}
}
int main()
{
	for (int i = 2;; i++)
	{
		int t = i * (i + 1) * (2 * i + 1) / 6;
		if (t > 1000000)
		{
			break;
		}
		a[cnt].num = t, a[cnt].base = i, a[cnt].type = 0, cnt++;
	}
	for (int i = 2;; i++)
	{
		int t = 2 * i * (i + 1) * (2 * i + 1) / 3;
		if (t > 1000000)
		{
			break;
		}
		a[cnt].num = t, a[cnt].base = 2 * i, a[cnt].type = 1, cnt++;
	}
	for (int i = 2;; i++)
	{
		int t = i * (2 * i - 1) * (2 * i + 1) / 3;
		if (t > 1000000)
		{
			break;
		}
		a[cnt].num = t, a[cnt].base = 2 * i - 1, a[cnt].type = 1, cnt++;
	}
	std::sort(a, a + cnt, cmp);
	memset(f, 0x70, sizeof f);
	f[0][0] = 0;
	for (int j = 0; j < cnt; j++)
	{
		for (int i = a[j].num; i <= 1000000; i++)
		{
			f[j + 1][i] = f[j][i - a[j].num] + 1;
		}
		for (int i = 0; i <= 1000000; i++)
			if (f[j][i] < f[j + 1][i])
			{
				f[j + 1][i] = f[j][i];
			}
	}
	int _ = 0;
	while (scanf("%d", &c), c)
	{
		printf("Case %d: ", ++_), solve();
	}
	return 0;
}
