#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define eps 1e-9
#define pi acos(-1.0)
#define ff first
#define ss second
#define re return
#define QI queue<int>
#define SI stack<int>
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define sq(a) ((a) * (a))
#define distance(a, b) (sq(a.x - b.x) + sq(a.y - b.y))
#define iseq(a, b) (fabs(a - b) < eps)
#define eq(a, b) iseq(a, b)
#define ms(a, b) memset((a), (b), sizeof(a))
#define G() getchar()
#define MAX3(a, b, c) max(a, max(b, c))
#define II ({ int a ; read(a) ; a; })
#define LL ({ Long a ; read(a) ; a; })
#define DD ({double a; scanf("%lf", &a); a; })

double const EPS = 3e-8;

typedef long long Long;
typedef long long int64;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
typedef vector<Long> vl;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<Long, Long> pll;
typedef pair<double, double> pdd;
typedef vector<pii> vpii;

// For loop

#define forab(i, a, b) for (__typeof(b) i = (a); i <= b; ++i)
#define rep(i, n) forab(i, 0, (n)-1)
#define For(i, n) forab(i, 1, n)
#define rofba(i, a, b) for (__typeof(b) i = (b); i >= a; --i)
#define per(i, n) rofba(i, 0, (n)-1)
#define rof(i, n) rofba(i, 1, n)
#define forstl(i, s) for (__typeof((s).end()) i = (s).begin(); i != (s).end(); ++i)

template <class T>
T gcd(T a, T b)
{
	return (b != 0 ? gcd<T>(b, a % b) : a);
}
template <class T>
T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

//Fast Reader
template <class T>
inline bool read(T &x)
{
	int c = getchar();
	int sgn = 1;
	while (~c && c < '0' || c > '9')
	{
		if (c == '-')
			sgn = -1;
		c = getchar();
	}
	for (x = 0; ~c && '0' <= c && c <= '9'; c = getchar())
		x = x * 10 + c - '0';
	x *= sgn;
	return ~c;
}

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};//4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */

const int maxn = 1e5 + 10;
const int MX = 1e3 + 10;
const int NIL = 0;
const int INF = (1 << 29);

vector<int> g[maxn];
int match[maxn], dist[maxn], inf_size, sz, n, m, k, idx;

int Idx, Val[MX][MX];
char inp[MX][MX];
bool ok(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m)
		return 0;
	return 1;
}

bool bfs()
{
	int x, y, i;
	queue<int> q;
	for (i = 1; i <= Idx; i++)
	{
		if (match[i] == NIL)
		{
			dist[i] = 0;
			q.push(i);
		}
		else
			dist[i] = INF;
	}
	dist[NIL] = INF;
	while (!q.empty())
	{
		x = q.front();
		q.pop();
		if (x != NIL)
		{
			int sz = g[x].size();
			rep(i, sz)
			{
				y = g[x][i];
				if (dist[match[y]] == INF)
				{
					dist[match[y]] = dist[x] + 1;
					q.push(match[y]);
				}
			}
		}
	}
	return dist[NIL] != INF;
}
bool dfs(int x)
{

	if (x != NIL)
	{
		int i;
		int sz = g[x].size();
		rep(i, sz)
		{
			int y = g[x][i];

			if (dist[match[y]] == dist[x] + 1 && dfs(match[y]))
			{
				match[x] = y;
				match[y] = x;
				return 1;
			}
		}
		dist[x] = INF;
		return 0;
	}
	return 1;
}
int Hopcropt()
{
	int matching = 0, i;
	for (int i = 1; i <= Idx; i++)
	{
		match[i] = 0;
	}

	while (bfs())
	{
		for (i = 1; i <= Idx; i++)
		{
			if (match[i] == 0 && dfs(i))
			{
				matching++;
			}
		}
	}
	//printf("matching:: %d\n",matching);
	return matching;
}

void clearkori()
{
	for (int i = 0; i <= Idx + 2; i++)
		g[i].clear();
}
int main()
{
	// I will always use scanf and printf
	// May be i won't be a good programmer but i will be a good human being

	int cs = 1;
	while (scanf("%d %d", &n, &m) == 2)
	{
		if (n == 0 && m == 0)
			break;

		Idx = 0;
		rep(i, n) scanf("%s", inp[i]);
		rep(i, n)
		{
			rep(j, m) if (inp[i][j] == '.') Val[i][j] = ++Idx;
		}
		rep(i, n)
		{
			rep(j, m)
			{
				if (inp[i][j] != '.')
					continue;
				int x = Val[i][j];
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (ok(nx, ny) && inp[nx][ny] == '.')
					{
						int y = Val[nx][ny];
						g[x].pb(y);
						//   printf(" x :: %d y :: %d\n" , x , y );
					}
				}
			}
		}
		if (Idx == 0)
		{
			printf("Case #%d: 0\n", cs++);
			continue;
		}
		if (Idx == 1)
		{
			printf("Case #%d: 1\n", cs++);
			continue;
		}
		int hc = Hopcropt();
		int ans = Idx - hc - hc;
		// printf(" Idx :: %d hc :: %d\n" , Idx , hc );
		ans = (ans + 1) / 2;
		printf("Case #%d: %d\n", cs++, ans);

		clearkori();
	}

	return 0;
}
