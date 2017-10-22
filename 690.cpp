#include <bits/stdc++.h>

using namespace std;

#define N 211
#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int table[5][N];
char res[5][32];
int cnt = 0;
int bit[20];

class state
{
public:
	int t[5];
	int now, size;
	void set_data(int n, int num)
	{
		size = n;
		now = num;
	}

	bool operator<(const state &a) const
	{
		if (now != a.now)
		{
			return now < a.now;
		}
		if (t[0] != a.t[0])
		{
			return t[0] < a.t[0];
		}
		if (t[1] != a.t[1])
		{
			return t[1] < a.t[1];
		}
		if (t[2] != a.t[2])
		{
			return t[2] < a.t[2];
		}
		if (t[3] != a.t[3])
		{
			return t[3] < a.t[3];
		}
		if (t[4] != a.t[4])
		{
			return t[4] < a.t[4];
		}
		return false;
	};
};

void fill_table(int x, int n, int now, bool flag, state &ins)
{
	rep(i, 5)
	{
		ins.t[i] = 0;
		rep(j, n)
		{
			if (flag == false)
			{
				if (table[i][x + j] != -1)
				{
					ins.t[i] |= bit[j];
				}
				if (res[i][j] == 'X')
				{
					table[i][x + j] = now;
				}
			}
			if (flag == true && table[i][x + j] == now)
			{
				table[i][x + j] = -1;
			}
		}
	}
}

bool can_do(int x, int n)
{
	rep(i, 5)
	{
		rep(j, n)
		{
			if (res[i][j] == '.')
			{
				continue;
			}
			else if (table[i][x + j] != -1)
			{
				return false;
			}
		}
	}
	return true;
}

int node = 0;

int solve(int n, int last, int now, map<state, int> &M, state &ins)
{
	if (M.find(ins) != M.end())
	{
		return M[ins];
	}
	if (now == 10)
	{
		return n;
	}
	state next;
	next.set_data(n, now);
	int res = N;
	int lim = n + 1;
	REP(i, 1, lim)
	{
		if (can_do(last + i, n))
		{
			fill_table(last + i, n, now, false, next);
			res = min(res, i + solve(n, last + i, now + 1, M, next));
			fill_table(last + i, n, now, true, next);
		}
	}
	return M[ins] = res;
}

main()
{
	int n;
	rep(i, 20) bit[i] = (1 << i);
	while (scanf("%d\n", &n) && n)
	{
		int lim = 11 * n + 1;
		rep(i, 5)
		{
			rep(j, lim) table[i][j] = -1;
		}
		//    rep(i,5)scanf("%s",res[i]);//rep(j,n)cin>>res[i][j];
		rep(i, 5) fgets(res[i], n + 3, stdin);
		node = 0;
		cnt = N;
		state ins;
		map<state, int> M;
		rep(i, 5)
		{
			rep(j, n) if (res[i][j] == 'X')
			{
				table[i][j] = 0;
			}
		}
		//    cout << solve(n,0,1,M,ins) << endl;
		printf("%d\n", solve(n, 0, 1, M, ins));
		//cout <<"state "<< node << endl;
	}
	return false;
}
