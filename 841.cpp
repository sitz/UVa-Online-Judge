#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define ALL(C) (C).begin(), (C).end()
#define x second
#define y first
#define pb push_back
#define mp make_pair

typedef pair<int, int> pii;

char m[20][20];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

class snake
{
public:
	vector<pii> d;
	char m[20][20];
	int n;
	int cnt;
	snake(){};
	snake(int tn, char tm[20][20])
	{
		d.pb(mp(0, 0));
		n = tn;
		cnt = 0;
		rep(i, n) rep(j, n) m[i][j] = tm[i][j];
	}
	int getx()
	{
		return d[d.size() - 1].x;
	}
	int gety()
	{
		return d[d.size() - 1].y;
	}
	void move(int ney, int nex)
	{
		rep(i, d.size() - 1)
		{
			d[i] = d[i + 1];
		}
		d[d.size() - 1].y = ney;
		d[d.size() - 1].x = nex;
	}
	void eat(int ney, int nex)
	{
		d.pb(mp(ney, nex));
	}
	bool islegal(int ney, int nex)
	{
		rep(i, d.size())
		{
			if (d[i].y == ney && d[i].x == nex)
			{
				return false;
			}
		}
		return true;
	}
	bool operator<(const snake &a) const
	{
		if (d.size() != a.d.size())
		{
			return d.size() < a.d.size();
		}
		rep(i, n)
		{
			rep(j, n)
			{
				if (m[i][j] != a.m[i][j])
				{
					return m[i][j] < a.m[i][j];
				}
			}
		}
		rep(i, d.size())
		{
			if (d[i] != a.d[i])
			{
				return d[i] < a.d[i];
			}
		}
		return false;
	}
};

int solve(int n, snake ini, int egg)
{
	queue<snake> Q;
	set<snake> S;
	Q.push(ini);
	while (!Q.empty())
	{
		snake now = Q.front();
		Q.pop();
		if (now.d.size() == egg + 1)
		{
			return now.cnt;
		}
		rep(i, 4)
		{
			int nex = now.getx() + dx[i], ney = now.gety() + dy[i];
			if (nex < 0 || ney < 0 || nex >= n || ney >= n ||
					now.m[ney][nex] == 'x' || !now.islegal(ney, nex))
			{
				continue;
			}
			snake next = now;
			if (next.m[ney][nex] == 'o')
			{
				next.eat(ney, nex);
				next.m[ney][nex] = '.';
				next.cnt++;
				if (S.find(next) == S.end())
				{
					S.insert(next), Q.push(next);
				}
			}
			else
			{
				next.move(ney, nex);
				next.cnt++;
				if (S.find(next) == S.end())
				{
					S.insert(next), Q.push(next);
				}
			}
		}
	}
	return -1;
}

main()
{
	int te;
	cin >> te;
	while (te--)
	{
		int n;
		cin >> n;
		rep(i, n) cin >> m[i];
		int egg = 0;
		rep(i, n)
		{
			rep(j, n)
			{
				if (m[i][j] == 'o')
				{
					egg++;
				}
			}
		}
		snake ini(n, m);
		int ans = solve(n, ini, egg);
		if (ans != -1)
		{
			cout << ans << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
		if (te)
		{
			puts("");
		}
	}
}
