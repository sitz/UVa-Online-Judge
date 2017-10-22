#include <bits/stdc++.h>

using namespace std;

char img[19][4][5] =// 19 kinds by 4x4
		{
				{{"xx.."},
				 {"xx.."},
				 {"...."},
				 {"...."}},
				{{"xx.."},
				 {".xx."},
				 {"...."},
				 {"...."}},
				{{".x.."},
				 {"xx.."},
				 {"x..."},
				 {"...."}},
				{{".xx."},
				 {"xx.."},
				 {"...."},
				 {"...."}},
				{{"x..."},
				 {"xx.."},
				 {".x.."},
				 {"...."}},
				{{"x..."},
				 {"xxx."},
				 {"...."},
				 {"...."}},
				{{".x.."},
				 {".x.."},
				 {"xx.."},
				 {"...."}},
				{{"xx.."},
				 {"x..."},
				 {"x..."},
				 {"...."}},
				{{"xxx."},
				 {"..x."},
				 {"...."},
				 {"...."}},
				{{"..x."},
				 {"xxx."},
				 {"...."},
				 {"...."}},
				{{"x..."},
				 {"x..."},
				 {"xx.."},
				 {"...."}},
				{{"xx.."},
				 {".x.."},
				 {".x.."},
				 {"...."}},
				{{"xxx."},
				 {"x..."},
				 {"...."},
				 {"...."}},
				{{"xxxx"},
				 {"...."},
				 {"...."},
				 {"...."}},
				{{"x..."},
				 {"x..."},
				 {"x..."},
				 {"x..."}},
				{{".x.."},
				 {"xxx."},
				 {"...."},
				 {"...."}},
				{{"x..."},
				 {"xx.."},
				 {"x..."},
				 {"...."}},
				{{"xxx."},
				 {".x.."},
				 {"...."},
				 {"...."}},
				{{".x.."},
				 {"xx.."},
				 {".x.."},
				 {"...."}}};
int kinds[19] = {0, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 6, 6, 6, 6};
int hk[19] = {2, 2, 3, 2, 3, 2, 3, 3, 2, 2, 3, 3, 2, 1, 4, 2, 3, 2, 3};
int wk[19] = {2, 3, 2, 3, 2, 3, 2, 2, 3, 3, 2, 2, 3, 4, 1, 3, 2, 3, 2};
int lk[7] = {0, 1, 3, 5, 9, 13, 15};
int rk[7] = {0, 2, 4, 8, 12, 14, 18};
int h, w;
char g[30][30];
struct BITMAP//16x16 = 256, 256/64 = 4
{
	unsigned long long f[4];
};

BITMAP bitImg[19][16][16];// transform img->bitImg, [kinds][left_upX][left_upY]

#define DEBUG (0)
void buildBitImg()
{
	int i, j, k;
	int p, q;
	memset(&bitImg, 0, sizeof(bitImg));
	for (i = 0; i < 19; i++)
	{
		for (p = 0; p + hk[i] <= 16; p++)
		{
			for (q = 0; q + wk[i] <= 16; q++)
			{
				for (j = 0; j < 4; j++)
				{
					for (k = 0; k < 4; k++)
					{
						if (img[i][j][k] == 'x')
						{
							int pos = (p + j) * 16 + (q + k);
							bitImg[i][p][q].f[pos / 64] |= 1LLU << (pos % 64);
						}
					}
				}
#if DEBUG == 2
				for (j = 0; j < 16; j++, puts(""))
				{
					for (k = 0; k < 16; k++)
					{
						int pos = j * 16 + k;
						int v = (bitImg[i][p][q].f[pos / 64] >> (pos % 64)) & 1;
						printf("%d", v);
					}
				}
				puts("");
				getchar();
#endif
			}
		}
	}
}
void printBITMAP(BITMAP &S)
{
	int i, j;
	for (i = 0; i < h; i++, puts(""))
	{
		for (j = 0; j < w; j++)
		{
			int pos = i * 16 + j;
			int v = (S.f[pos / 64] >> (pos % 64)) & 1;
			printf("%d", v);
		}
	}
	puts("");
}
BITMAP G, X;
BITMAP buf[1000];
int solution;
int check(BITMAP &Filter, BITMAP &IMG)
{
	int i;
	unsigned long long r1, r2;
	r1 = 1, r2 = 0;
	for (i = 0; i < 4; i++)
	{
		r1 &= (G.f[i] & IMG.f[i]) == IMG.f[i];
		r2 |= Filter.f[i] & IMG.f[i];
	}//r2 == 0 and r1 == 1
	return r1 == 1 && r2 == 0;
}
void dfs(int idx, BITMAP &S, BITMAP &Filter)//find i-th ship cover map
{
	// G: (x, y) still can place set 1, i.e. can_used[x][y]
	// Filter: (x, y) is obstacle set 1, i.e. 'o'
	int i, j, k, p, f;
	BITMAP NS;
	if (solution > h * w)
	{
		return;
	}
	if (idx == 7)//find one of solutions
	{
		for (i = 0; i < 4; i++)//all 'x' must be cover.
		{
			if ((S.f[i] & X.f[i]) != X.f[i])
			{
				return;
			}
		}
		for (i = 0; i < solution; i++)
		{
			for (j = 0; j < 4; j++)
				if (buf[i].f[j] != S.f[j])
				{
					break;
				}
			if (j == 4)//equal
			{
				return;
			}
		}
		if (solution > h * w)
		{
			return;
		}
		for (i = 0; i < 4; i++)
		{
			buf[solution].f[i] = S.f[i];
		}
		solution++;
#if DEBUG == 1
		for (i = 0; i < h; i++, puts(""))
		{
			for (j = 0; j < w; j++)
			{
				int pos = i * 16 + j;
				int v = (S.f[pos / 64] >> (pos % 64)) & 1;
				printf("%d", v);
			}
		}
		puts("");
		getchar();
#endif
		return;
	}
	for (i = lk[idx]; i <= rk[idx]; i++)//this ship rotation
	{
		for (j = 0; j + hk[i] <= h; j++)
		{
			for (k = 0; k + wk[i] <= w; k++)
			{
				f = check(Filter, bitImg[i][j][k]);
				if (f == 1)
				{
					NS = S;
					for (p = 0; p < 4; p++)
					{
						G.f[p] ^= bitImg[i][j][k].f[p];
						NS.f[p] |= bitImg[i][j][k].f[p];
					}
					dfs(idx + 1, NS, Filter);
					for (p = 0; p < 4; p++)
					{
						G.f[p] ^= bitImg[i][j][k].f[p];
						NS.f[p] |= bitImg[i][j][k].f[p];
					}
				}
			}
		}
	}
}
int main()
{
	buildBitImg();
	/*freopen("in.txt", "r+t", stdin);
	freopen("out2.txt", "w+t", stdout);*/
	int i, j, k, cases = 0;
	while (scanf("%d %d", &w, &h) == 2 && h)
	{
		for (i = 0; i < h; i++)
		{
			scanf("%s", g[i]);
		}
		BITMAP Filter, S;
		memset(&G, 0, sizeof(G));
		memset(&S, 0, sizeof(S));
		memset(&X, 0, sizeof(X));
		memset(&Filter, 0, sizeof(Filter));
		for (i = 0; i < h; i++)
		{
			for (j = 0; j < w; j++)
			{
				int pos = i * 16 + j;
				if (g[i][j] == 'o')
				{
					Filter.f[pos / 64] |= 1LLU << (pos % 64);
				}
				else
				{
					G.f[pos / 64] |= 1LLU << (pos % 64);//'.' or 'x'
				}
				if (g[i][j] == 'x')
				{
					X.f[pos / 64] |= 1LLU << (pos % 64);
				}
			}
		}
		solution = 0;
		dfs(0, S, Filter);
		printf("Game #%d\n", ++cases);
		if (solution == 0)
		{
			puts("no.");
		}
		else
		{
			int update;
			int judge[10000] = {};
			do
			{
				update = 0;
				for (i = 0; i < h; i++)
				{
					for (j = 0; j < w; j++)
					{
						if (g[i][j] != '.')
						{
							continue;
						}
						// if cover '.' -> 'o', must be one solution.
						int sol = 0, solidx;
						int pos = i * 16 + j, v;
						for (k = 0; k < solution; k++)
						{
							if (judge[k])
							{
								continue;
							}
							v = (buf[k].f[pos / 64] >> (pos % 64)) & 1;
							if (v == 0)// one solution don't place (i, j)
							{
								sol++, solidx = k;
								if (sol >= 2)
								{
									break;
								}
							}
						}
						if (sol == 1)
						{
							judge[solidx] = 1;
							update = 1;
						}
					}
				}
			} while (update);
			int ret = 1;
			for (i = 0; i < solution; i++)
			{
				ret &= judge[i];
			}
			if (solution == 1)
			{
				ret = 1;
			}
			puts(ret ? "yes." : "no.");
		}
		puts("");
	}
	return 0;
}
