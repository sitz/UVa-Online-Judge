#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<pdd, pdd> ppii;
typedef vector<pii> vp;
typedef vector<vi> vvi;

const int N = 100010;
const int M = 210;
const int K = 200010;
const int LIT = 2500;
const int INF = 1 << 30;
const double eps = 1e-8;
const int dir[6][2] = {{2, 0}, {-2, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
const int ABS(int x)
{
	while (x < 0)
		x = -x;
	return x;
}

#define mp make_pair
#define pb push_back
#define fst first
#define snd second

struct node
{
	int sl, sr, col;
} r[N];

int n, cnt, L, R;
set<pii> have, loc;
set<pii>::iterator itr;
vp v[N];

void insert(int w, int p)
{
	pii nt = mp(w, p);
	if (have.count(nt))
		return;
	itr = have.lower_bound(nt);
	if (itr == have.begin())
	{
		r[L].sl = p;
		L = p;
	}
	else if (itr == have.end())
	{
		r[R].sr = p;
		R = p;
	}
	else
	{
		pii tmp = *itr;
		int p2 = tmp.snd;
		itr--;
		tmp = *itr;
		int p1 = tmp.snd;
		if (r[p1].sr == -1)
			r[p1].sr = p;
		else
			r[p2].sl = p;
	}
	have.insert(nt);
}

stack<int> sta;
int beg[N];

void dfs()
{
	sta.push(1);
	beg[1] = -1;
	while (!sta.empty())
	{
		int x = sta.top();
		if (beg[x] < 0)
		{
			if (r[x].sl != -1)
			{
				sta.push(r[x].sl);
				beg[r[x].sl] = beg[x] - 2;
			}
			beg[x] = -beg[x];
		}
		else if (beg[x] > 0)
		{
			loc.insert(mp(beg[x], ++cnt));
			v[(beg[x] + 1) >> 1].pb(mp(cnt, x));
			r[x].col = cnt;
			sta.pop();
			if (r[x].sr != -1)
			{
				sta.push(r[x].sr);
				beg[r[x].sr] = (-beg[x]) - 2;
			}
		}
	}
}

void init()
{
	have.clear();
	loc.clear();
	cnt = 0;
	int w;
	scanf("%d", &n);
	for (int i = 0; i < N; i++)
	{
		r[i].sl = r[i].sr = -1;
		v[i].clear();
		beg[i] = 0;
	}
	scanf("%d", &w);
	have.insert(mp(w, 1));
	L = R = 1;
	for (int i = 2; i <= n; i++)
	{
		scanf("%d", &w);
		insert(w, i);
	}
	dfs();
}

char res[M][M];

char cal(int x, int y)
{
	pii pt = mp(x, y);
	if (loc.count(pt))
		return 'o';
	pt.fst++;
	if (loc.count(pt))
		return '|';
	pt.fst++;
	if (loc.count(pt))
		return '+';
	if (x % 2 == 0)
		return ' ';
	int xx = (x + 1) >> 1;
	if (!v[xx].size())
		return ' ';
	int p2 = lower_bound(v[xx].begin(), v[xx].end(), mp(y, 0)) - v[xx].begin();
	int p1 = p2 - 1;
	if (p1 >= 0)
	{
		int tmp = v[xx][p1].snd;
		int lit = r[r[tmp].sr].col;
		if (r[tmp].sr != -1 && y < lit)
			return '-';
	}
	if (p2 < v[xx].size())
	{
		int tmp = v[xx][p2].snd;
		int lit = r[r[tmp].sl].col;
		if (r[tmp].sl != -1 && y > lit)
			return '-';
	}
	return ' ';
}

void solve()
{
	int q;
	cin >> q;
	while (q--)
	{
		int X1, X2, Y1, Y2;
		scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
		for (int i = X1, ii = 1; i <= X2 + X1 - 1; i++, ii++)
		{
			res[ii][0] = 0;
			for (int j = Y1, jj = 1; j <= Y2 + Y1 - 1; j++, jj++)
			{
				res[ii][jj] = cal(i, j);
				if (res[ii][jj] != ' ')
					res[ii][0] = 1;
			}
		};
		for (int i = X1, ii = 1; i <= X2 + X1 - 1; i++, ii++)
		{
			if (!res[ii][0])
				continue;
			for (int j = Y1, jj = 1; j <= Y2 + Y1 - 1; j++, jj++)
				printf("%c", res[ii][jj]);
			printf("\n");
		}
		printf("\n");
	}
}

int main()
{
	int tcase = 1, T;
	cin >> T;
	while (T--)
	{
		init();
		printf("Case #%d:\n", tcase++);
		solve();
	}
}
