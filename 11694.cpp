#include <bits/stdc++.h>

using namespace std;

char a[10][10];
struct node
{
	vector<int> pre;
} dp[10][128];
int s[10], n, ans[10];
//  0 \
//  1 /
bool check(int i)
{
	int j;
	for (j = 0; j <= n; ++j)
	{
		if (s[j] == 0 && j != 0 && j != n && i != 0 && i != n)
		{
			break;
		}
		if (a[i][j] != '.')
		{
			if (a[i][j] != s[j] + '0')
			{
				break;
			}
		}
	}
	if (j == n + 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool judge1(int i, int k)
{
	int ii;
	memset(s, 0, sizeof(s));
	for (ii = 0; ii < n; ++ii)
	{
		if (k % 2 == 0)
		{
			s[ii]++;
		}
		else
		{
			s[ii + 1]++;
		}
		k /= 2;
	}
	return check(i);
}
bool judge2(int i, int j, int k)
{
	int ii;
	memset(s, 0, sizeof(s));
	for (ii = 0; ii < n; ++ii)
	{
		if (j % 2 == 0)
		{
			s[ii + 1]++;
		}
		else
		{
			s[ii]++;
		}
		j /= 2;
	}
	for (ii = 0; ii < n; ++ii)
	{
		if (k % 2 == 0)
		{
			s[ii]++;
		}
		else
		{
			s[ii + 1]++;
		}
		k /= 2;
	}
	return check(i);
}
bool judge3(int i, int j)
{
	int ii;
	memset(s, 0, sizeof(s));
	for (ii = 0; ii < n; ++ii)
	{
		if (j % 2 == 0)
		{
			s[ii + 1]++;
		}
		else
		{
			s[ii]++;
		}
		j /= 2;
	}
	return check(i);
}
void print()
{
	int i, j;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			if (ans[i] & (1 << j))
			{
				printf("/");
			}
			else
			{
				printf("\\");
			}
		}
		printf("\n");
	}
}
//  0 \
//  1 /
///
int f[100];
void init()
{
	int i;
	for (i = 0; i < 80; i++)
	{
		f[i] = i;
	}
}
int find(int x)
{
	if (x == f[x])
	{
		return x;
	}
	f[x] = find(f[x]);
	return f[x];
}
////
bool che()
{
	int i, k, a, b;
	init();
	for (i = 0; i < n; i++)
	{
		for (k = 0; k < n; k++)
		{
			if (ans[i] & (1 << k))
			{
				a = (i + 1) * (n + 1) + k;
				b = i * (n + 1) + k + 1;
			}
			else
			{
				a = (i) * (n + 1) + k;
				b = (i + 1) * (n + 1) + k + 1;
			}
			a = find(a);
			b = find(b);
			if (a == b)
			{
				return false;
			}
			f[a] = b;
		}
	}
	return true;
}
bool dfs(int i, int j)
{
	int k;
	if (i < 0)
	{
		if (che())
		{
			print();
			return true;
		}
		else
		{
			return false;
		}
	}
	ans[i] = j;
	for (k = 0; k < dp[i][j].pre.size(); ++k)
	{
		if (dfs(i - 1, dp[i][j].pre[k]))
		{
			return true;
		}
	}
	return false;
}
int main()
{
	int i, j, k, t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (i = 0; i <= n; ++i)
		{
			scanf("%s", a[i]);
		}
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < (1 << n); ++j)
			{
				dp[i][j].pre.clear();
			}
		}
		for (j = 0; j < (1 << n); ++j)
		{
			if (judge1(0, j))
			{
				dp[0][j].pre.push_back(0);
			}
		}
		for (i = 0; i < n - 1; ++i)
		{
			for (j = 0; j < (1 << n); ++j)
			{
				if (!dp[i][j].pre.empty())
				{
					for (k = 0; k < (1 << n); ++k)
					{
						if (judge2(i + 1, j, k))
						{
							dp[i + 1][k].pre.push_back(j);
						}
					}
				}
			}
		}
		for (k = 0; k < (1 << n); ++k)
		{
			if ((!dp[n - 1][k].pre.empty()) && judge3(n, k))
			{
				if (dfs(n - 1, k))
				{
					break;
				}
			}
		}
	}
	return 0;
}
