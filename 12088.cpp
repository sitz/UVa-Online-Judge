#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 210;

int T, cas = 1, n, len;
ll ans;
struct Node
{
	int idx, weight;
} a[maxn];
char str[maxn], str2[maxn];
int num[10];

bool operator<(const Node &a, const Node &b)
{
	return (a.weight == b.weight && a.idx > b.idx) || a.weight > b.weight;
}

void dfs(int &i, int sym)
{
	int cursym = 1, cnt = 0;
	while (i < len)
	{
		if (str[i] == '#')
		{
			cnt++;
			i++;
		}
		else
		{
			if (cnt > 0)
			{
				for (int j = 1, r = 1; j <= cnt; j++, r *= 10)
				{
					a[n].idx = i - j;
					a[n].weight = r * (sym * cursym);
					n++;
				}
				cnt = 0;
			}
			if (str[i] == ')')
			{
				i++;
				return;
			}
			else if (str[i] == '(')
			{
				i++;
				dfs(i, sym * cursym);
			}
			else if (str[i] == '+')
			{
				cursym = 1;
				i++;
			}
			else if (str[i] == '-')
			{
				cursym = -1;
				i++;
			}
			else
			{
				return;
			}
		}
	}
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s%s", str, str2);
		for (int i = 0; i < 10; i++)
		{
			num[i] = 0;
		}
		for (int i = 0; str2[i]; i++)
		{
			num[str2[i] - 48]++;
		}
		len = strlen(str);
		str[len] = '$';
		len++;
		str[len] = 0;
		n = 0;
		int i = 0;
		dfs(i, 1);
		sort(a, a + n);
		ans = 0;
		for (int i = 0, cur = 9; i < n; i++)
		{
			while (num[cur] == 0)
			{
				cur--;
			}
			num[cur]--;
			ans += cur * a[i].weight;
			str[a[i].idx] = cur + 48;
		}
		printf("Case %d:\n", cas++);
		str[--len] = 0;
		printf("%s\n", str);
		printf("%lld\n", ans);
	}
	return 0;
}
