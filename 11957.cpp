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

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

char mat[100 + 5][100 + 5];
int paths[100 + 5][100 + 5];
int n;

void reset()
{
	for (int i = 0; i < 105; i++)
		for (int j = 0; j < 105; j++)
		{
			paths[i][j] = 0;
		}
}

void inc(int r, int c)
{
	paths[r][c] %= 1000007;
	if (r + 1 < n && c + 1 < n)
		if (mat[r + 1][c + 1] != 'B')
		{
			paths[r + 1][c + 1] = (paths[r + 1][c + 1] + paths[r][c]) % 1000007;
		}
		else if (r + 2 < n && c + 2 < n)
			if (mat[r + 2][c + 2] != 'B')
			{
				paths[r + 2][c + 2] = (paths[r + 2][c + 2] + paths[r][c]) % 1000007;
			}
	if (r + 1 < n && c - 1 >= 0)
		if (mat[r + 1][c - 1] != 'B')
		{
			paths[r + 1][c - 1] = (paths[r + 1][c - 1] + paths[r][c]) % 1000007;
		}
		else if (r + 2 < n && c - 2 >= 0)
			if (mat[r + 2][c - 2] != 'B')
			{
				paths[r + 2][c - 2] = (paths[r + 2][c - 2] + paths[r][c]) % 1000007;
			}
}

int main()
{
	int testCase;
	scanf("%d", &testCase);
	int cases = 0;
	while (testCase--)
	{
		reset();
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%s", mat[i]);
		for (int i = 0; i < n; i++)
			if (mat[0][i] != 'B')
				paths[0][i] = 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				inc(i, j);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (mat[i][j] == 'W')
					printf("Case %d: %d\n", ++cases, paths[i][j] % 1000007);
	}
	return 0;
}
