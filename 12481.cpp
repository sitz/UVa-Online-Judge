#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP(a, b) make_pair(a, b)
#define FOREACH(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)

const int MAX_N = 1000 + 50;
int N, M, K, mat[MAX_N][MAX_N], hU[MAX_N], hR[MAX_N];

int que[MAX_N], qT;
int maxRecArea(int hR[], int hU[], int n)
{
	hR[0] = hR[n] = -1;//-INF
	que[qT = 1] = 0;
	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		ret = max(ret, hU[i]);
		while (qT > 1 && hR[i] <= hR[que[qT]])
		{
			//(que[qT-1], i], assert(qT > 1)
			ret = max(ret, min(hR[que[qT]], hU[i]) * (i - que[qT - 1]));
			--qT;
		}
		que[++qT] = i;
	}
	return ret;
}

int main()
{
	int test;
	scanf("%d", &test);
	for (int Case = 1; Case <= test; Case++)
	{
		scanf("%d %d %d", &N, &M, &K);
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
			{
				scanf("%d", &mat[i][j]);
			}
		memset(hU, 0, sizeof(hU));
		memset(hR, 0, sizeof(hR));
		int res = 1;
		for (int r = 1; r <= N; r++)
		{
			for (int c = 1; c <= M; c++)
				if (r == 1 || abs(mat[r][c] - mat[r - 1][c]) <= K)
				{
					hU[c]++;
				}
				else
				{
					hU[c] = 1;
				}
			for (int c = 1; c < M; c++)
			{
				if (abs(mat[r][c] - mat[r][c + 1]) <= K)
				{
					hR[c]++;
				}
				else
				{
					hR[c] = 0;
				}
				hR[c] = min(hU[c], hR[c]);
			}
			int upd = maxRecArea(hR, hU, M);
			res = max(res, upd);
		}
		printf("Case %d: %d\n", Case, res);
	}
	return 0;
}
