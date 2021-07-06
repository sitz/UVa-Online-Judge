#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

const int N = 10;

int rowrem[N], colrem[N], diagrem[2 * N];
int inr[N], inc[N], ind[2 * N];

bool m[N][N];
bool ans[N][N];
int cnt;

void solve(int now, int r, int c)
{
	if (now == r * c)
	{
		if (cnt == 0)
		{
			rep(i, r) rep(j, c) ans[i][j] = m[i][j];
		}
		cnt++;
		return;
	}
	int y = now / c, x = now % c;
	int dir = r - 1 - y + x;
	//cout <<y <<" " <<x <<" " <<   dir << " : " << inr[y] <<" "<< inc[x] <<" " << ind[dir] <<" : "
	//       << rowrem[y] <<" " << colrem[x] <<" " << diagrem[dir] << endl;
	//0
	if (rowrem[y] == inr[y] || colrem[x] == inc[x] || diagrem[dir] == ind[dir])
		;
	else
	{
		m[y][x] = false;
		rowrem[y]--;
		colrem[x]--;
		diagrem[dir]--;
		solve(now + 1, r, c);
		rowrem[y]++;
		colrem[x]++;
		diagrem[dir]++;
	}
	//1
	if (inr[y] == 0 || inc[x] == 0 || ind[dir] == 0)
		;
	else
	{
		m[y][x] = true;
		rowrem[y]--;
		colrem[x]--;
		diagrem[dir]--;
		inr[y]--;
		inc[x]--;
		ind[dir]--;
		solve(now + 1, r, c);
		rowrem[y]++;
		colrem[x]++;
		diagrem[dir]++;
		inr[y]++;
		inc[x]++;
		ind[dir]++;
	}
}

main()
{
	int r, c;
	int tc = 0;
	while (cin >> r >> c)
	{
		if (tc)
		{
			cout << endl;
		}
		tc = 1;
		rep(i, N) rowrem[i] = 0, colrem[i] = 0;
		rep(i, 2 * N) diagrem[i] = 0;
		rep(i, r)
		{
			rep(j, c)
			{
				rowrem[i]++;
				colrem[j]++;
				diagrem[r - 1 - i + j]++;
			}
		}
		rep(i, r) cin >> inr[i];
		rep(i, c) cin >> inc[i];
		rep(i, r + c - 1) cin >> ind[i];
		cnt = 0;
		solve(0, r, c);
		if (cnt == 1)
		{
			rep(i, r)
			{
				rep(j, c)
				{
					if (ans[i][j])
					{
						cout << 'X';
					}
					else
					{
						cout << '.';
					}
				}
				cout << endl;
			}
		}
		else
		{
			cout << cnt << endl;
		}
	}
	return false;
}
