#include <bits/stdc++.h>

using namespace std;

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL long long

#define For(i, a, b) for (int i = (a); i < (b); i++)
#define Fors(i, sz) for (size_t i = 0; i < sz.size(); i++)
#define Fore(it, x) for (typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define Set(a, s) memset(a, s, sizeof(a))

int n;
bool mat[100 + 3][100 + 3], vis[100 + 3];

void printLine()
{
	printf("+");
	for (int i = 0; i < n * 2 - 1; i++)
		printf("-");
	printf("+\n");
}

void dfs(int at, int absent)
{
	if (at == absent)
		return;
	vis[at] = true;
	for (int i = 0; i < n; i++)
		if (mat[at][i] && !vis[i])
			dfs(i, absent);
}

int main()
{
	int testCase;
	scanf("%d", &testCase);
	int cases = 0;
	while (testCase--)
	{
		scanf("%d", &n);
		Set(mat, false);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int a;
				scanf("%d", &a);
				mat[i][j] = a;
			}
		}
		bool output[100 + 3][100 + 3];
		bool firstVis[100 + 3];
		Set(vis, false);
		dfs(0, -1);
		for (int i = 0; i < 103; i++)
			firstVis[i] = vis[i];
		for (int i = 0; i < n; i++)
		{
			Set(vis, false);
			dfs(0, i);
			for (int j = 0; j < n; j++)
			{
				if (firstVis[j] && !vis[j])
					output[i][j] = true;
				else
					output[i][j] = false;
			}
			output[i][i] = firstVis[i];
		}
		printf("Case %d:\n", ++cases);
		printLine();
		for (int i = 0; i < n; i++)
		{
			printf("|");
			for (int j = 0; j < n; j++)
			{
				if (output[i][j])
					printf("Y|");
				else
					printf("N|");
			}
			printf("\n");
			printLine();
		}
	}
	return 0;
}
