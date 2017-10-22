#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define mp make_pair
#define pb push_back

typedef pair<int, int> pii;

class st
{
public:
	st *r, *l;
	int val, child;
	st() : r(NULL), l(NULL){};
	st(int tval) : r(NULL), l(NULL), val(tval), child(0){};
};

void make(st *now, int val)
{
	if (val < now->val)
	{
		if (now->l == NULL)
		{
			now->l = new st(val);
		}
		else
		{
			make(now->l, val);
		}
	}
	else if (now->val < val)
	{
		if (now->r == NULL)
		{
			now->r = new st(val);
		}
		else
		{
			make(now->r, val);
		}
	}
	now->child++;
}

void decide(st *now, bool isleft, int prev, int depth, vector<pii> &ret,
						vector<int> &r, vector<int> &l)
{
	int cnt = 0;
	if (isleft)
	{
		if (now->r != NULL)
		{
			cnt = now->r->child + 1;
		}
		prev -= (cnt + 1);
	}
	else
	{
		if (now->l != NULL)
		{
			cnt = now->l->child + 1;
		}
		prev += (cnt + 1);
	}
	ret[now->val].first = depth;
	ret[now->val].second = prev;
	if (now->r != NULL)
		decide(now->r, false, prev, depth + 1, ret, r, l),
				r[now->val] = 1;
	if (now->l != NULL)
		decide(now->l, true, prev, depth + 1, ret, r, l),
				l[now->val] = 1;
}

const int N = 200;
char buf[N][N];
int num[N][N];

void putline(int y, int l, int r)
{
	REP(i, l, r + 1)
	buf[y][i] = '-';
}

const int dx[] = {1, -1};
void output(int r, vector<int> *a)
{
	rep(i, N)
	{
		rep(j, N)
		{
			if (buf[i][j] == 'o')
			{
				rep(l, 2)
				{
					if (a[l][num[i][j]] != 1)
					{
						continue;
					}
					for (int k = j + dx[l]; 0 <= k && k < N; k += dx[l])
					{
						if (buf[i][k] == '+')
						{
							putline(i, min(j + dx[l], k), max(j + dx[l], k));
							buf[i][k] = '+';
							break;
						}
						else if (buf[i][k] != ' ')
						{
							break;
						}
					}
				}
			}
		}
	}
	rep(i, r)
	{
		int p = 0;
		rep(j, N) if (buf[i][j] != ' ')
		{
			p = j + 1;
		}
		rep(j, p) cout << buf[i][j];
		cout << endl;
	}
	/*
	rep(j,N){
	  int cnt=0;
	  rep(i,r){
	    if (buf[i][j] == 'o')cnt++;
	  }
	  if (cnt > 1)assert(false);
	}
	*/
}

main()
{
	int te;
	cin >> te;
	rep(tc, te)
	{
		cout << "Case #" << tc + 1 << ":" << endl;
		rep(i, N) rep(j, N) buf[i][j] = ' ', num[i][j] = -1;
		int n;
		cin >> n;
		int tmp;
		cin >> tmp;
		st *root = new st(tmp - 1);
		REP(i, 1, n)
		{
			cin >> tmp;
			make(root, tmp - 1);
		}
		vector<pii> ans(n);
		vector<int> info[2];
		rep(i, 2) rep(j, n) info[i].push_back(0);
		ans[root->val].first = 0;
		ans[root->val].second = 0;
		if (root->r != NULL)
			decide(root->r, false, 0, 1, ans, info[0], info[1]),
					info[0][root->val] = 1;
		if (root->l != NULL)
			decide(root->l, true, 0, 1, ans, info[0], info[1]),
					info[1][root->val] = 1;
		int mini = 0, maxi = 0;
		rep(i, (int)ans.size()) mini = min(mini, ans[i].second),
														maxi = max(maxi, ans[i].first);
		rep(i, (int)ans.size()) ans[i].second -= mini;
		rep(i, (int)ans.size())
		{
			if (i != root->val)
			{
				buf[ans[i].first * 2 - 1][ans[i].second] = '|';
				buf[ans[i].first * 2 - 2][ans[i].second] = '+';
			}
			buf[ans[i].first * 2][ans[i].second] = 'o';
			num[ans[i].first * 2][ans[i].second] = i;
		}
		output(maxi * 2 + 1, info);
	}
	return false;
}
