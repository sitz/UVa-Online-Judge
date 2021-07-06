#include <bits/stdc++.h>

using namespace std;

const int N = 55 * 3;
const int INF = 0x3f3f3f3f;

char ss[20000];
char str[N];
int dp[N][N][N];
int limit;

char match(char ch)
{
	if (ch == 'A')
		return 'U';
	else if (ch == 'U')
		return 'A';
	else if (ch == 'C')
		return 'G';
	else
		return 'C';
}
bool isau(char a, char b)
{
	return (a == 'A' && b == 'U') || (a == 'U' && b == 'A');
}
bool iscg(char a, char b)
{
	return (a == 'C' && b == 'G') || (a == 'G' && b == 'C');
}
void work()
{
	scanf("%s%d", ss, &limit);
	int ls = strlen(ss);
	int len = 0;
	int left = 1, right = ls - 1;
	while (left < ls && isdigit(ss[left]))
		left++;
	while (isdigit(ss[right]))
		right--;
	if (left == ls)
	{
		puts("0");
		return;
	}

	int res = 0;
	char lch = ss[0];
	int lcnt = 0;
	for (int i = 1; i < left; i++)
		lcnt = lcnt * 10 + ss[i] - '0';
	char rch = ss[right];
	int rcnt = 0;
	for (int i = right + 1; i < ls; i++)
		rcnt = rcnt * 10 + ss[i] - '0';

	if (isau(lch, rch))
	{
		int d = min(lcnt, rcnt);
		res += d;
		lcnt -= d;
		rcnt -= d;
	}
	if (iscg(lch, rch))
	{
		int d = min(lcnt, rcnt);
		d = min(d, limit);
		res += d;
		lcnt -= d;
		rcnt -= d;
		limit -= d;
	}
	str[0] = 0;
	int p = left;
	while (p < right)
	{
		char ch = ss[p++];
		int k = 0;
		while (p < right && isdigit(ss[p]))
			k = k * 10 + ss[p++] - '0';
		for (int i = 0; i < k; i++)
			str[++len] = ch;
	}
	int cnt = 0;
	for (int i = 1; i <= len; i++)
		if (str[i] == match(lch))
			cnt++;
	if (lcnt > cnt)
		lcnt = cnt;
	cnt = 0;
	for (int i = 1; i <= len; i++)
		if (str[i] == match(rch))
			cnt++;
	if (rcnt > len)
		rcnt = len;
	for (int i = 0; i < rcnt; i++)
		str[++len] = rch;
	reverse(str + 1, str + len + 1);
	for (int i = 0; i < lcnt; i++)
		str[++len] = lch;

	//printf("%d\n", res);
	//puts(str+1);
	memset(dp, 0, sizeof(dp));
	for (int c = 0; c <= limit; c++)
		for (int s = 2; s <= len; s++)
			for (int i = 1; i + s - 1 <= len; i++)
			{
				int j = i + s - 1;
				for (int k = i; k < j; k++)
				{
					for (int c1 = 0; c1 <= c; c1++)
						dp[i][j][c] = max(dp[i][j][c], dp[i][k][c1] + dp[k + 1][j][c - c1]);
				}
				if (isau(str[i], str[j]))
					dp[i][j][c] = max(dp[i][j][c], dp[i + 1][j - 1][c] + 1);
				if (c > 0 && iscg(str[i], str[j]))
					dp[i][j][c] = max(dp[i][j][c], dp[i + 1][j - 1][c - 1] + 1);
			}
	int ans = 0;
	for (int c = 0; c <= limit; c++)
		ans = max(ans, dp[1][len][c]);
	printf("%d\n", ans + res);
}

int main()
{
	int T, C = 0;
	scanf("%d", &T);
	while (T--)
	{
		printf("Case %d: ", ++C);
		work();
	}
	return 0;
}
