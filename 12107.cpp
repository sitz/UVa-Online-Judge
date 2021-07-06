#include <bits/stdc++.h>

using namespace std;

const int maxn = 10;

bool flag;
int tot, t;
char s[3][maxn];
char ans[3][maxn];

bool is_ok()
{
	int a = 0, b = 0, c;
	for (int i = 0; i < strlen(s[0]); i++)
	{
		a = a * 10 + s[0][i] - '0';
	}
	for (int i = 0; i < strlen(s[1]); i++)
	{
		b = b * 10 + s[1][i] - '0';
	}
	c = a * b;
	char cur[maxn];
	for (int i = strlen(s[2]) - 1; i >= 0; i--)
	{
		cur[i] = '0' + c % 10;
		c /= 10;
	}
	if (c > 0 || cur[0] == '0')
	{
		return false;
	}
	for (int i = 0; i < strlen(s[2]); i++)
		if (s[2][i] != '*' && s[2][i] != cur[i])
		{
			return false;
		}
	return true;
}

void dfs(int a, int b)
{
	if (b >= strlen(s[a]))
	{
		b = 0;
		a++;
	}
	if (a == 2)
	{
		if (is_ok())
		{
			tot++;
		}
		return;
	}
	if (s[a][b] != '*')
	{
		dfs(a, b + 1);
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			if (i == 0 && b == 0)
			{
				continue;
			}
			s[a][b] = '0' + i;
			dfs(a, b + 1);
			if (tot > 1)
			{
				s[a][b] = '*';
				return;
			}
		}
		s[a][b] = '*';
	}
}

void Change(int a, int b, int c)
{
	if (b >= strlen(s[a]))
	{
		b = 0;
		a++;
	}
	if (c == t)
	{
		tot = 0;
		dfs(0, 0);
		if (tot == 1)
		{
			flag = true;
			for (int i = 0; i < 3; i++)
			{
				memcpy(ans[i], s[i], sizeof(s[i]));
			}
		}
		return;
	}
	char ch = s[a][b], m;
	for (int i = 0; i <= 10; i++)
	{
		if (i == 1 && b == 0)
		{
			continue;
		}
		if (i == 0)
		{
			m = '*';
		}
		else
		{
			m = '0' + i - 1;
		}
		if (m == ch)
		{
			Change(a, b + 1, c);
		}
		else
		{
			s[a][b] = m;
			Change(a, b + 1, c + 1);
		}
		if (flag)
		{
			s[a][b] = ch;
			return;
		}
		s[a][b] = ch;
	}
}

int main()
{
	int cas = 0;
	while (scanf("%s", s[0]) == 1 && s[0][0] != '0')
	{
		scanf("%s%s", s[1], s[2]);
		tot = 0;
		dfs(0, 0);
		if (tot == 1)
		{
			printf("Case %d: %s %s %s\n", ++cas, s[0], s[1], s[2]);
		}
		else
		{
			int sum_len = strlen(s[0]) + strlen(s[1]) + strlen(s[2]);
			flag = false;
			for (t = 1; t <= sum_len; t++)
			{
				Change(0, 0, 0);
				if (flag)
				{
					break;
				}
			}
			printf("Case %d: %s %s %s\n", ++cas, ans[0], ans[1], ans[2]);
		}
	}
	return 0;
}
