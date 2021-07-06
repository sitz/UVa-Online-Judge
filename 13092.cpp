#include <bits/stdc++.h>

using namespace std;

// according to problem, we have given a string,starting from last position of string,we have to fold the string into even palindrome mirror with cost of "y" or we may erase last char with cost of "x". first, observation to solve this problem is that , from each point we should try to fold a string with maximum length possible. so, using manacer, we find from each position , minimum possible index to which it can be folded. for this, initially, put a minimum index to each end index of palindrome centered at some position. then, update this minimum values to each valid index coming from backside of string. now, finally a simple dp with two options whether to erase last char or to go to min index

const int MX = 2000115;
const int INF = 2000000010;

char s[MX + 2], ss[MX + 2];
int n, m, x, y, p[MX + 2], mn[MX + 2], dp[MX + 2];

void manacher()
{
	m = n * 2 + 2;
	ss[0] = '*';
	for (int i = 1, j = 0; i < m; i += 2, j++)
	{
		ss[i] = s[j];
		ss[i + 1] = '*';
	}
	ss[m - 1] = '\0';
	int c = 0, r = 0, len;
	for (int i = 1; i < m - 1; i++)
	{
		int mi = 2 * c - i;
		len = (r > i) ? min(r - i, p[mi]) : 0;
		while (i - 1 - len >= 0 && i + 1 + len < m && ss[i - 1 - len] == ss[i + 1 + len])
		{
			++len;
		}
		p[i] = len;
		if (i + len > r)
		{
			c = i, r = i + len;
		}
	}
}

int go(int p)
{
	if (p <= 0)
	{
		return 0;
	}
	int &ret = dp[p];
	if (ret != -1)
	{
		return ret;
	}
	ret = x + go(p - 1);
	if (mn[p] < p)
	{
		ret = min(ret, y + go(mn[p]));
	}
	return ret;
}

int main()
{
	int T, t = 1;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &x, &y);
		scanf("%s", s);
		n = strlen(s);
		manacher();
		for (int i = 0; i < m; i++)
		{
			mn[i] = INF;
		}
		for (int i = 0; i < m - 1; i++)
		{
			if (i % 2 == 0 && p[i])
			{
				// 1-based endpos in main str of pal having mirror @i
				int nx = (i + p[i]) / 2;
				mn[nx] = min(mn[nx], i / 2);
			}
		}
		int pv = INF;
		for (int i = n; i >= 1; i--)
		{
			pv = min(pv, mn[i]);
			if (pv < i)
			{
				mn[i] = pv;
			}
		}
		memset(dp, -1, sizeof(dp));
		int ans = go(n);
		printf("Case %d: %d\n", t++, ans);
	}
	return 0;
}
