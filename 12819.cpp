#include <bits/stdc++.h>

using namespace std;

template <class T>
inline T sqr(T x)
{
	return x * x;
}
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<LL, LL> PLL;
typedef pair<LL, int> PLI;
typedef pair<LD, LD> PDD;
#define MP make_pair
#define PB push_back
#define sz(x) ((int)(x).size())
#define clr(ar, val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR (i, n) for (int i = 0; i < (n); ++i)
#define forIt(mp, it) for (__typeof(mp.begin()) it = mp.begin(); it != mp.end(); it++)
const double PI = acos(-1.0);

#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
#define lowbit(u) (u & (-u))

using namespace std;

int cover[25];
int dp[22][17][1 << 16][2];
int g[17][17];
int r, c;

#define MOD 1000000007

inline int get(int x, int y)
{
	return x * c + y;
}

void Add(int &ans, int v)
{
	ans += v;
	if (ans >= MOD)
	{
		ans -= MOD;
	}
}

int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("/Users/mac/Desktop/data.in", "r", stdin);
#endif
	while (scanf("%d %d", &r, &c) != EOF)
	{
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
			{
				scanf("%d", &g[i][j]);
			}
		for (int i = 0; i <= 20; i++)
		{
			cover[i] = 0;
			for (int j = 0; j < r; j++)
			{
				for (int k = 0; k < c; k++)
				{
					if (g[j][k] >= i)
					{
						cover[i] |= (1 << get(j, k));
					}
				}
			}
		}
		memset(dp, 0, sizeof(dp));
		dp[1][0][(1 << (r * c)) - 1][0] = 1;
		for (int f = 1; f <= 20; f++)
		{
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					for (int st = 0; st < (1 << (r * c)); st++)
					{
						for (int l = 0; l < 2; l++)
						{
							if (dp[f][get(i, j)][st][l] == 0)
							{
								continue;
							}
							int nx = i, ny = j + 1, nf = f;
							if (ny == c)
							{
								ny = 0, nx++;
							}
							if (nx == r)
							{
								nx = ny = 0, nf++;
							}
							if (((st & (1 << (get(i, j)))) == 0) && g[i][j] >= f - 1)
							{
								if (g[i][j] >= f)
								{
									Add(dp[nf][get(nx, ny)][st | (1 << get(i, j))][l],
											dp[f][get(i, j)][st][l]);//å¿é¡»æ¾ä¸å»1*2
								}
								continue;
							}
							if (st & (1 << get(i, j)))
								Add(dp[nf][get(nx, ny)][st ^ (1 << get(i, j))][l],
										dp[f][get(i, j)][st][l]);//ä¸æ¾
							else
							{
								Add(dp[nf][get(nx, ny)][st][l], dp[f][get(i, j)][st][l]);
							}
							if (g[i][j] >= f)
								Add(dp[nf][get(nx, ny)][st | (1 << get(i, j))][1],
										dp[f][get(i, j)][st][l]);//1*1
							if (j)
							{
								if ((st & (1 << get(i, j - 1))) == 0)
								{
									if (g[i][j] >= f && g[i][j - 1] >= f)
										Add(dp[nf][get(nx, ny)][st | (1 << get(i, j)) | (1 << get(i, j - 1))][l],
												dp[f][get(i, j)][st][l]);
								}
							}
							if (i)
							{
								if ((st & (1 << get(i - 1, j))) == 0)
								{
									if (g[i][j] >= f && g[i - 1][j] >= f)
										Add(dp[nf][get(nx, ny)][st | (1 << get(i, j)) | (1 << get(i - 1, j))][l],
												dp[f][get(i, j)][st][l]);
								}
							}
						}
					}
				}
			}
		}
		static int ca = 1;
		printf("Case %d: %d %d\n", ca++, dp[21][get(0, 0)][cover[20]][1], dp[21][get(0, 0)][cover[20]][0]);
	}
	return 0;
}
