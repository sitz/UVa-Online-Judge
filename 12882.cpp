#include <bits/stdc++.h>

using namespace std;

#define print1(a) cout << a << endl
#define print2(a, b) cout << a << " " << b << endl
#define print3(a, b, c) cout << a << " " << b << " " << c << endl
#define oo (1 << 30)
#define PI 3.141592653589793
#define pi (2.0 * acos(0.0))
#define ERR 1e-5
#define PRE 1e-8
#define SZ(s) ((int)s.size())
#define LL long long
#define ISS istringstream
#define OSS ostringstream
#define VS vector<string>
#define VI vector<int>
#define VD vector<double>
#define VLL vector<long long>
#define SII set<int>::iterator
#define SI set<int>
#define mem(a, b) memset(a, b, sizeof(a))
#define fr(i, a, b) for (i = a; i <= b; i++)
#define frn(i, a, b) for (i = a; i >= b; i--)
#define fri(a, b) for (i = a; i <= b; i++)
#define frin(a, b) for (i = a; i >= b; i--)
#define frj(a, b) for (j = a; j <= b; j++)
#define frjn(a, b) for (j = a; j >= b; j--)
#define frk(a, b) for (k = a; k <= b; k++)
#define frkn(a, b) for (k = a; k >= b; k--)
#define frl(a, b) for (l = a; l <= b; l++)
#define frln(a, b) for (l = a; l >= b; l--)
#define REP(i, n) for (i = 0; i < n; i++)
#define EQ(a, b) (fabs(a - b) < ERR)
#define all(a, b, c)          \
	for (int I = 0; I < b; I++) \
	a[I] = c
#define CROSS(a, b, c, d) ((b.x - a.x) * (d.y - c.y) - (d.x - c.x) * (b.y - a.y))
#define sqr(a) ((a) * (a))
#define FORE(i, a) for (typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define typing(j, b) typeof((b).begin()) j = (b).begin();
#define BE(a) a.begin(), a.end()
#define rev(a) reverse(BE(a));
#define sorta(a) sort(BE(a))
#define pb push_back
#define popb pop_back
#define mp make_pair
#define round(i, a) i = (a < 0) ? a - 0.5 : a + 0.5;
#define makeint(n, s) istringstream(s) >> n
#define inpow(a, x, y) \
	int i;               \
	a = x;               \
	fri(2, y) a *= x
#define cntbit(mask) __builtin_popcountll(mask)
//0 based print
#define debug_array(a, n)     \
	for (int i = 0; i < n; i++) \
		cerr << a[i] << " ";      \
	cerr << endl;
#define debug_matrix(mat, row, col) \
	for (int i = 0; i < row; i++)     \
	{                                 \
		for (int j = 0; j < col; j++)   \
			cerr << mat[i][j] << " ";     \
		cerr << endl;                   \
	}

#define csprnt printf("Case %d: ", ++cas);
#define mod 1000000007
#define eulerconstant 0.5772156649

template <class T1>
void debug(T1 e)
{
	cout << e << endl;
}
template <class T1, class T2>
void debug(T1 e1, T2 e2)
{
	cout << e1 << "\t" << e2 << endl;
}
template <class T1, class T2, class T3>
void debug(T1 e1, T2 e2, T3 e3)
{
	cout << e1 << "\t" << e2 << "\t" << e3 << endl;
}
template <class T1, class T2, class T3, class T4>
void debug(T1 e1, T2 e2, T3 e3, T4 e4)
{
	cout << e1 << "\t" << e2 << "\t" << e3 << "\t" << e4 << endl;
}
template <class T1, class T2, class T3, class T4, class T5>
void debug(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5)
{
	cout << e1 << "\t" << e2 << "\t" << e3 << "\t" << e4 << "\t" << e5 << endl;
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void debug(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6)
{
	cout << e1 << "\t" << e2 << "\t" << e3 << "\t" << e4 << "\t" << e5 << "\t" << e6 << endl;
}
template <class T>
void debug(vector<vector<T>> e, int row, int col)
{
	int i, j;
	REP(i, row)
	{
		REP(j, col)
				cout << e[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}
template <class T>
void debug(vector<basic_string<T>> e, int row, int col)
{
	int i, j;
	REP(i, row)
	{
		REP(j, col)
				cout << e[i][j];
		cout << endl;
	}
	cout << endl;
}
template <class T>
void debug(T e[110][110], int row, int col)
{
	int i, j;
	REP(i, row)
	{
		REP(j, col)
				cout << e[i][j] << " ";
		cout << endl;
	}
}
template <class T>
string toString(T n)
{
	ostringstream oss;
	oss << n;
	oss.flush();
	return oss.str();
}
int toInt(string s)
{
	int r = 0;
	istringstream sin(s);
	sin >> r;
	return r;
}
bool isVowel(char ch)
{
	ch = tolower(ch);
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
	{
		return true;
	}
	return false;
}
bool isUpper(char c)
{
	return c >= 'A' && c <= 'Z';
}
bool isLower(char c)
{
	return c >= 'a' && c <= 'z';
}
//*************************************************My Code Starts Here*********************************************************************************
#define lim 151000
int xlow[lim], xhigh[lim], ylow[lim], yhigh[lim];
struct node
{
	int val, st;
	int op;
	int in;
};
VI adj[lim];
LL area[lim];
bool col[lim];
map<int, int> mapofst;

LL dfs(int node)
{
	col[node] = true;
	LL ret = area[node];
	for (int i = 0; i < SZ(adj[node]); i++)
	{
		int tem = adj[node][i];
		if (col[tem])
		{
			continue;
		}
		ret += dfs(tem);
	}
	return ret;
}
int n;
stack<int> stck[2 * lim];//index stack
node arr[2 * lim];

bool comp(node p, node q)
{
	if (p.val != q.val)
	{
		return p.val < q.val;
	}
	return p.op < q.op;
}

void makeEdge()
{
	mem(col, false);
	sort(arr + 1, arr + 4 * n + 1, comp);
	int i;
	for (i = 1; i <= 4 * n; i++)
		while (!stck[i].empty())
		{
			stck[i].pop();
		}
	mapofst.clear();
	int in = 0;
	for (i = 1; i <= 4 * n; i++)
	{
		if (arr[i].op == 1)
		{
			col[arr[i].in] = true;
			continue;
		}
		if (mapofst.find(arr[i].st) == mapofst.end())//notun
		{
			mapofst[arr[i].st] = (++in);
		}
		int now = mapofst[arr[i].st];
		while (!stck[now].empty() && col[stck[now].top()])
		{
			stck[now].pop();
		}
		if (!stck[now].empty())
		{
			adj[arr[i].in].pb(stck[now].top());
			adj[stck[now].top()].pb(arr[i].in);
			// print2(stck[now].top(),arr[i].in);
		}
		stck[now].push(arr[i].in);
	}
}

int main()
{
	//srand(time(NULL));
	//freopen("A.txt","r",stdin);
	//freopen("B.txt","w",stdout);
	while (cin >> n)
	{
		int i;
		for (i = 1; i <= n; i++)
		{
			scanf("%d %d %d %d", &xlow[i], &ylow[i], &xhigh[i], &yhigh[i]);
			area[i] = xhigh[i] * yhigh[i];
			xhigh[i] += xlow[i];
			yhigh[i] += ylow[i];
			adj[i].clear();
		}
		for (i = 1; i <= n; i++)
		{
			arr[4 * i - 1].in = i;
			arr[4 * i - 1].op = 0;
			arr[4 * i - 1].val = xlow[i];
			arr[4 * i - 1].st = ylow[i];
			arr[4 * i - 2].in = i;
			arr[4 * i - 2].op = 0;
			arr[4 * i - 2].val = xlow[i];
			arr[4 * i - 2].st = yhigh[i];
			arr[4 * i - 3].in = i;
			arr[4 * i - 3].op = 1;
			arr[4 * i - 3].val = xhigh[i];
			arr[4 * i - 3].st = ylow[i];
			arr[4 * i].in = i;
			arr[4 * i].op = 1;
			arr[4 * i].val = xhigh[i];
			arr[4 * i].st = yhigh[i];
		}
		makeEdge();
		for (i = 1; i <= n; i++)
		{
			arr[4 * i - 1].in = i;
			arr[4 * i - 1].op = 0;
			arr[4 * i - 1].val = ylow[i];
			arr[4 * i - 1].st = xlow[i];
			arr[4 * i - 2].in = i;
			arr[4 * i - 2].op = 0;
			arr[4 * i - 2].val = ylow[i];
			arr[4 * i - 2].st = xhigh[i];
			arr[4 * i - 3].in = i;
			arr[4 * i - 3].op = 1;
			arr[4 * i - 3].val = yhigh[i];
			arr[4 * i - 3].st = xlow[i];
			arr[4 * i].in = i;
			arr[4 * i].op = 1;
			arr[4 * i].val = yhigh[i];
			arr[4 * i].st = xhigh[i];
		}
		makeEdge();
		mem(col, false);
		LL ans = 0;
		for (i = 1; i <= n; i++)
			if (!col[i])
			{
				ans = max(ans, dfs(i));
			}
		print1(ans);
	}
	return 0;
}
