#include <bits/stdc++.h>

using namespace std;

long long int dp[20][30];
char s1[200], c;
int n, m, pt[30], flag;
char s2[10][10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
void init();
void solve(char str[100], int devel);
void deal_dp(int x, int y);

int main()
{
	int i, j, t, tem = 1;
	init();
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s %d %d", s1, &n, &m);
		flag = 0;
		solve(s1, n);
		printf("Case %d: %c\n", tem++, c);
	}
	return 0;
}

void deal_dp(int x, int y)
{
	int l, i;
	if (dp[x][y] > 0)
	{
		return;
	}
	l = strlen(s2[x]);
	if (y == 1)
	{
		dp[x][y] = (long long int)l;
		return;
	}
	for (i = 0; i <= l - 1; i++)
	{
		deal_dp(pt[s2[x][i] - 'A' + 1], y - 1);
		dp[x][y] += dp[pt[s2[x][i] - 'A' + 1]][y - 1];
	}
}

void init()
{
	char str;
	int i, j;
	for (i = 'A'; i <= 'Z'; i++)
	{
		str = (char)i;
		if (str >= 'A' && str <= 'C')
		{
			pt[str - 'A' + 1] = 2;
		}
		else if (str >= 'D' && str <= 'F')
		{
			pt[str - 'A' + 1] = 3;
		}
		else if (str >= 'G' && str <= 'I')
		{
			pt[str - 'A' + 1] = 4;
		}
		else if (str >= 'J' && str <= 'L')
		{
			pt[str - 'A' + 1] = 5;
		}
		else if (str >= 'M' && str <= 'O')
		{
			pt[str - 'A' + 1] = 6;
		}
		else if (str >= 'P' && str <= 'S')
		{
			pt[str - 'A' + 1] = 7;
		}
		else if (str >= 'T' && str <= 'V')
		{
			pt[str - 'A' + 1] = 8;
		}
		else if (str >= 'W' && str <= 'Z')
		{
			pt[str - 'A' + 1] = 9;
		}
	}
	memset(dp, 0, sizeof(dp));
	for (i = 2; i <= 9; i++)
	{
		for (j = 1; j <= 21; j++)
		{
			deal_dp(i, j);
		}
	}
}

void solve(char str[100], int devel)
{
	int i, j, l;
	int Str;
	if (flag)
	{
		return;
	}
	if (devel == 0)
	{
		c = str[m - 1];
		flag = 1;
		return;
	}
	l = strlen(str);
	for (i = 0; i <= l - 1; i++)
	{
		Str = str[i] - 'A' + 1;
		if (dp[pt[Str]][devel] >= m)
		{
			solve(s2[pt[Str]], devel - 1);
		}
		else
		{
			m -= dp[pt[Str]][devel];
		}
	}
}
