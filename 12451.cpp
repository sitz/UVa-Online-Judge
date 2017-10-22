#include <bits/stdc++.h>

using namespace std;

char str[200], dis[200];
int dp[200], nxt[200];

void get_nxt(int n)
{
	memset(nxt, 0, sizeof(nxt));
	int i, j = -1;
	nxt[0] = -1;
	for (i = 1; i <= n; i++)
	{
		while (j > -1 && dis[j + 1] != dis[i])
			j = nxt[j];
		if (dis[j + 1] == dis[i])
			j++;
		nxt[i] = j;
	}
}

int get(int start, int end)
{
	int n = end - start;
	for (int i = 0; i < n; i++)
		dis[i] = str[start + i];
	dis[n] = '\0';
	get_nxt(n);
	int l = (n - 1) - nxt[n - 1];
	if (n % l == 0)
		return n / l;
	else
		return 1;
}

int getNum(int t)
{
	int re = 0;
	while (t)
	{
		re++;
		t = t / 10;
	}
	return re;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", str);
		int len = strlen(str);
		dp[0] = 0;
		dp[1] = 1;
		for (int i = 2; i <= len; i++)
		{
			dp[i] = 1212000;
			for (int j = 0; j < i; j++)
			{
				int t = get(j, i);
				int len = i - j;
				int ll = len / t;
				if (len < ll + 2 + getNum(t))
				{
					dp[i] = min(dp[i], dp[j] + len);
				}
				else
				{
					dp[i] = min(dp[i], dp[j] + ll + 2 + getNum(t));
				}
			}
		}
		printf("%d\n", dp[len]);
	}
	return 0;
}
