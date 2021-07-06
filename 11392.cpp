#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

const int N = 1000000;
const int inf = 3 * N;
int cost[N][2];
int path[N][2];
int val[N][2];
enum
{
	ZERO = 0,
	THREE = 1
};

bool verify(int div, int th, int z)
{
	int rem = 0;
	int cnt = th + z;
	rep(i, th)
	{
		rem = (rem * 10 + 3) % div;
		cnt--;
		if (rem % div == 0 && cnt != 0)
		{
			return false;
		}
	}
	rep(i, z)
	{
		rem = (rem * 10) % div;
		cnt--;
		if (rem % div == 0 && cnt != 0)
		{
			return false;
		}
	}
	return true;
}

void bfs(int div)
{
	if (div == 1 || div == 3)
	{
		cout << "1 1 0" << endl;
		return;
	}
	int now, last;
	rep(i, div) cost[i][0] = cost[i][1] = inf, path[i][0] = path[i][1] = -1;
	path[3][THREE] = -1;
	val[3][THREE] = 3;
	cost[3][THREE] = 0;
	queue<pair<int, int>> Q;
	Q.push(make_pair(3, (int)THREE));
	while (!Q.empty())
	{
		now = Q.front().first;
		last = Q.front().second;
		Q.pop();
		if (now == 0)
		{
			break;
		}
		int next;
		next = (now * 10 + 3) % div;
		if (cost[next][THREE] == inf && last == THREE)
		{
			Q.push(make_pair(next, (int)THREE));
			cost[next][THREE] = cost[now][last] + 1;
			val[next][THREE] = last;
			path[next][THREE] = now;
		}
		next = (now * 10) % div;
		if (cost[next][ZERO] == inf)
		{
			Q.push(make_pair(next, (int)ZERO));
			cost[next][ZERO] = cost[now][last] + 1;
			val[next][ZERO] = last;
			path[next][ZERO] = now;
		}
	}
	int th = 1, ze = 0, ans = cost[0][last] + 1;
	while (now != 3)
	{
		if (last == THREE)
		{
			th++;
		}
		else
		{
			ze++;
		}
		int tnow = now, tlast = last;
		now = path[tnow][tlast];
		last = val[tnow][tlast];
	}
	printf("%d %d %d\n", ans, th, ze);
	if (!verify(div, th, ze))
	{
		cout << div << " wrong " << endl;
		assert(false);
	}
}

main()
{
	int n;
	while (cin >> n)
	{
		bfs(n);
	}
}
