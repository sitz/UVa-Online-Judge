#include <bits/stdc++.h>

using namespace std;

#define REP(i, s, t) for (int i = (s); i < (t); i++)
#define FOREACH(i, v) for (typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)

typedef long long ll;

int N, M, T;
int d[100][100];
int ti[100];
bool vis[2][101][100];// [direction][length][pos]

int main()
{
	for (int test = 1;; test++)
	{
		scanf("%d%d", &N, &M);
		if (N == 0)
			break;
		REP(i, 0, N)
		REP(j, 0, N)
				d[i][j] = -1;
		REP(m, 0, M)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			d[a][b] = d[b][a] = c;
		}
		scanf("%d", &T);
		REP(t, 0, T)
		scanf("%d", ti + t);
		REP(dir, 0, 2)
		{
			REP(i, 0, N)
			vis[dir][0][i] = false;
			vis[dir][0][dir ? N - 1 : 0] = true;
			REP(l, 1, T + 1)
			{
				REP(i, 0, N)
				{
					vis[dir][l][i] = false;
					REP(j, 0, N)
					if (d[i][j] == ti[l - 1] && vis[dir][l - 1][j])
						vis[dir][l][i] = true;
				}
			}
			reverse(ti, ti + T);
		}
		int res = 0;
		REP(i, 0, N)
		{
			bool ok = false;
			REP(l, 0, T + 1)
			if (vis[0][l][i] && vis[1][T - l][i])
				ok = true;
			res += ok;
		}
		printf("Tour %d: %d\n", test, res);
	}
	return 0;
}
