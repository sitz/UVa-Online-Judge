#include <bits/stdc++.h>

using namespace std;

bool v[10][10];
int s[2], e[2], ans[50001][2];
int len;
bool DFS(int r, int c)
{
	ans[len][0] = r;
	ans[len++][1] = c;
	if (len > 50000)
	{
		return false;
	}
	v[r][c] = true;
	if (r == e[0] && c == e[1])
	{
		for (int i = 0; i < len; i++)
		{
			if (i)
			{
				printf(", ");
			}
			printf("(%d,%d)", ans[i][0], ans[i][1]);
		}
		printf("\n");
		return true;
	}
	else
	{
		if (r > 1 && c < 9 && !v[r - 1][c + 1])
		{
			if (DFS(r - 1, c + 1))
			{
				return true;
			}
			if (len > 50000)
			{
				return false;
			}
			ans[len][0] = r;
			ans[len][1] = c;
			if (++len > 50000)
			{
				return false;
			}
		}
		if (r < 9 && c < 9 && !v[r + 1][c + 1])
		{
			if (DFS(r + 1, c + 1))
			{
				return true;
			}
			if (len > 50000)
			{
				return false;
			}
			ans[len][0] = r;
			ans[len][1] = c;
			if (++len > 50000)
			{
				return false;
			}
		}
		if (r < 9 && c > 1 && !v[r + 1][c - 1])
		{
			if (DFS(r + 1, c - 1))
			{
				return true;
			}
			if (len > 50000)
			{
				return false;
			}
			ans[len][0] = r;
			ans[len][1] = c;
			if (++len > 50000)
			{
				return false;
			}
		}
		if (r > 1 && c > 1 && !v[r - 1][c - 1])
		{
			if (DFS(r - 1, c - 1))
			{
				return true;
			}
			if (len > 50000)
			{
				return false;
			}
			ans[len][0] = r;
			ans[len][1] = c;
			if (++len > 50000)
			{
				return false;
			}
		}
	}
	v[r][c] = false;
	return false;
}
int main()
{
	int t;
	char str[100], c;
	scanf("%d", &t);
	for (int ca = 0; ca < t; ca++)
	{
		if (ca)
		{
			puts("");
		}
		while ((c = getchar()) != '(')
			;
		scanf("%d", &s[0]);
		while ((c = getchar()) != ',')
			;
		scanf("%d", &s[1]);
		while ((c = getchar()) != '(')
			;
		scanf("%d", &e[0]);
		while ((c = getchar()) != ',')
			;
		scanf("%d", &e[1]);
		if ((s[0] + s[1]) % 2 != (e[0] + e[1]) % 2)
		{
			puts("fail");
		}
		else
		{
			len = 0;
			memset(v, false, sizeof(v));
			if (!DFS(s[0], s[1]))
			{
				puts("more than 50000 steps");
			}
		}
	}
	return 0;
}
