#include <bits/stdc++.h>

using namespace std;

struct Clue
{
	int left[26], right[26];
	char compare;
	int pl, pr;
} clues[10000];
char str[300], *p;
bool used[27];
int ans[26];
int n, m;
bool check()
{
	int left, right, nl;
	int total;
	for (int i = 0; i < m; i++)
	{
		left = right = nl = 0;
		for (int j = 0; j < clues[i].pl; j++)
			if (ans[clues[i].left[j]] != 0)
			{
				nl++;
				left += ans[clues[i].left[j]];
			}
		total = n * (n + 1) / 2;
		if (clues[i].compare == '>')
		{
			for (int p = n, count = 0; count < clues[i].pl - nl; p--)
				if (!used[p])
				{
					left += p;
					count++;
				}
			right = total - left;
			if (left <= right)
			{
				return false;
			}
		}
		else if (clues[i].compare == '<')
		{
			for (int p = 1, count = 0; count < clues[i].pl - nl; p++)
				if (!used[p])
				{
					left += p;
					count++;
				}
			right = total - left;
			if (left >= right)
			{
				return false;
			}
		}
		else
		{
			bool flag1 = false, flag2 = false;
			int temp = left, best;
			for (int p = n, count = 0; count < clues[i].pl - nl; p--)
				if (!used[p])
				{
					left += p;
					count++;
				}
			right = total - left;
			best = (left > right) ? left : right;
			if (best * 2 < total)
			{
				return false;
			}
			if (nl == clues[i].pl)
				if (left == right)
				{
					continue;
				}
				else
				{
					return false;
				}
			if (left >= right)
			{
				flag1 = true;
			}
			left = temp;
			for (int p = 1, count = 0; count < clues[i].pl - nl; p++)
				if (!used[p])
				{
					left += p;
					count++;
				}
			right = total - left;
			best = (left > right) ? left : right;
			if (best * 2 < total)
			{
				return false;
			}
			if (!flag1 && !flag2)
			{
				return false;
			}
		}
	}
	return true;
}
bool DFS(int d)
{
	if (d == n)
	{
		printf("Solution:");
		for (int i = 0; i < n; i++)
		{
			printf(" %d", ans[i]);
		}
		printf("\n");
		return true;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (used[i])
			{
				continue;
			}
			ans[d] = i;
			used[i] = true;
			if (!check())
			{
				ans[d] = 0;
				used[i] = false;
				continue;
			}
			if (DFS(d + 1))
			{
				return true;
			}
			used[i] = false;
			ans[d] = 0;
		}
		return false;
	}
}
int main()
{
	while (gets(str) != NULL)
	{
		sscanf(str, "%d %d", &n, &m);
		memset(used, false, sizeof(used));
		memset(ans, 0, sizeof(ans));
		for (int i = 0; i < m; i++)
		{
			gets(str);
			clues[i].pl = 0;
			bool flag = true;
			for (p = strtok(str, " "); p; p = strtok(NULL, " "))
			{
				if (*p == '=' || *p == '>' || *p == '<')
				{
					clues[i].compare = *p;
					flag = false;
				}
				else if (flag)
				{
					clues[i].left[clues[i].pl++] = *p - 'a';
				}
			}
		}
		if (!DFS(0))
		{
			puts("No solution possible!");
		}
	}
}
