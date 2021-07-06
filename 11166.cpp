#include <bits/stdc++.h>

using namespace std;

#define MAXN 65536

bool u[MAXN][2], nxt[MAXN][2];
char a[2][MAXN];
int len, f[MAXN][2];

int solve(int i, int flg)
{
	if (i == len)
	{
		return 0;
	}
	if (u[i][flg])
	{
		return f[i][flg];
	}
	u[i][flg] = 1;
	if (a[flg][i] == '0')
	{
		if (i > 0)
		{
			f[i][flg] = solve(i + 1, 1 - flg) + 1;
			nxt[i][flg] = 1;
			int tmp = solve(i + 1, flg);
			if (tmp < f[i][flg])
			{
				f[i][flg] = tmp;
				nxt[i][flg] = 0;
			}
		}
		else
		{
			f[i][flg] = solve(i + 1, flg);
			nxt[i][flg] = 0;
			int tmp = solve(i + 1, 1 - flg) + 1;
			if (tmp < f[i][flg])
			{
				f[i][flg] = tmp;
				nxt[i][flg] = 1;
			}
		}
	}
	else
	{
		f[i][flg] = solve(i + 1, flg) + 1;
		nxt[i][flg] = 0;
	}
	return f[i][flg];
}

void prints(int value, int sign)
{
	if (value)
	{
		if (sign == 0)
		{
			printf("+");
		}
		else
		{
			printf("-");
		}
	}
	else
	{
		printf("0");
	}
}

void print(int i, int flg)
{
	if (i == len)
	{
		printf("\n");
		return;
	}
	int value = a[flg][i] - '0';
	if (nxt[i][flg] == 0)
	{
		if (i > 0)
		{
			prints(value, flg);
		}
		print(i + 1, flg);
	}
	else
	{
		prints(1 - value, flg);
		print(i + 1, 1 - flg);
	}
}

int main()
{
	while (1)
	{
		memset(f, 0, sizeof(f));
		memset(u, 0, sizeof(u));
		memset(nxt, 0, sizeof(nxt));
		gets(a[0] + 1);
		if (strcmp(a[0] + 1, "0") == 0)
		{
			break;
		}
		a[0][0] = '0';
		len = strlen(a[0]);
		bool flag = false;
		a[1][len] = 0;
		for (int i = len - 1; i >= 0; i--)
		{
			if (flag)
			{
				a[1][i] = 1 - (a[0][i] - '0') + '0';
			}
			else
			{
				a[1][i] = a[0][i];
			}
			if (a[0][i] == '1')
			{
				flag = true;
			}
		}
		solve(0, 0);
		print(0, 0);
	}
	return 0;
}
