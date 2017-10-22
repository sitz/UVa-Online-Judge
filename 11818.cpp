#include <bits/stdc++.h>

using namespace std;

#define LL long long

const int MAX = 1 << 12;
const int nMAX = 20;
const int mMAX = 10000;
const int INF = ((1 << 31) - 1);
const int MOD = 1000000007;

int G[nMAX][nMAX];
int vis[nMAX][2], f[nMAX];
int dp[10][10][MAX];
int mark[4][4][4][4];
int s, t;
void init()
{
	vis[0][0] = 1;
	vis[0][1] = 2;
	vis[1][0] = 2;
	vis[1][1] = 3;
	vis[2][0] = 1;
	vis[2][1] = 4;
	vis[3][0] = 2;
	vis[3][1] = 5;
	vis[4][0] = 3;
	vis[4][1] = 6;
	vis[5][0] = 4;
	vis[5][1] = 5;
	vis[6][0] = 5;
	vis[6][1] = 6;
	vis[7][0] = 4;
	vis[7][1] = 7;
	vis[8][0] = 5;
	vis[8][1] = 8;
	vis[9][0] = 6;
	vis[9][1] = 9;
	vis[10][0] = 7;
	vis[10][1] = 8;
	vis[11][0] = 8;
	vis[11][1] = 9;
	mark[1][0][1][1] = 0;
	mark[1][1][1][0] = 0;
	mark[2][0][2][1] = 1;
	mark[2][1][2][0] = 1;
	mark[0][1][1][1] = 2;
	mark[1][1][0][1] = 2;
	mark[1][1][2][1] = 3;
	mark[2][1][1][1] = 3;
	mark[2][1][3][1] = 4;
	mark[3][1][2][1] = 4;
	mark[1][1][1][2] = 5;
	mark[1][2][1][1] = 5;
	mark[2][1][2][2] = 6;
	mark[2][2][2][1] = 6;
	mark[0][2][1][2] = 7;
	mark[1][2][0][2] = 7;
	mark[1][2][2][2] = 8;
	mark[2][2][1][2] = 8;
	mark[2][2][3][2] = 9;
	mark[3][2][2][2] = 9;
	mark[1][2][1][3] = 10;
	mark[1][3][1][2] = 10;
	mark[2][2][2][3] = 11;
	mark[2][3][2][2] = 11;
	for (int i = 0; i < 12; i++)
	{
		f[i] = (1 << i);
	}
}
bool floy(int s, int t)
{
	for (int k = 1; k <= 9; k++)
		for (int i = 1; i <= 9; i++)
			for (int j = 1; j <= 9; j++)
				if (G[i][k] && G[k][j])
				{
					G[i][j] = 1;
				}
	if (G[s][t])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool dfs(int x)
{
	/*cout<<bitset<32>(x)<<" "<<x<<endl;*/
	if (dp[s][t][x] == 2)
	{
		return 0;
	}
	else if (dp[s][t][x] != -1)
	{
		return dp[s][t][x];
	}
	for (int i = 0; i < 12; i++)
	{
		if (f[i] & x)
		{
			if (!dfs(x ^ f[i]))
			{
				dp[s][t][x] = 1;
				return true;
			}
		}
	}
	dp[s][t][x] = 0;
	return false;
}
bool v[10][10];
int main()
{
	init();
	int T, CASE = 1, n;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &s, &t);
		if (!v[s][t])
		{
			for (int i = 0; i < (1 << 12); i++)
			{
				for (int j = 1; j <= 9; j++)
					for (int k = 1; k <= 9; k++)
					{
						if (abs((j - 1) % 3 - (k - 1) % 3) + abs((j - 1) / 3 - (k - 1) / 3) <= 1)
						{
							G[j][k] = 1;
						}
						else
						{
							G[j][k] = 0;
						}
					}
				for (int j = 0; j < 12; j++)
				{
					if (f[j] & i)
					{
						G[vis[j][0]][vis[j][1]] = 0;
						G[vis[j][1]][vis[j][0]] = 0;
					}
				}
				if (floy(s, t))
				{
					dp[s][t][i] = 2;
				}
				else
				{
					dp[s][t][i] = -1;
				}
			}
		}
		v[s][t] = true;
		scanf("%d", &n);
		int x = 0;
		for (int i = 0; i < 12; i++)
		{
			x += f[i];
		}
		while (n--)
		{
			int x1, x2, y1, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			if (x & (1 << mark[x1][y1][x2][y2]))
			{
				x ^= (1 << mark[x1][y1][x2][y2]);
			}
		}
		printf("Case %d: ", CASE++);
		if (dp[s][t][x] == 2)
		{
			printf("No Cheese!\n");
		}
		else
		{
			if (dfs(x))
			{
				printf("SOHA\n");
			}
			else
			{
				printf("TARA\n");
			}
		}
	}
}
