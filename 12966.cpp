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
T lcm(T a, T b)
{
	return (a / gcd<T>(a, b) * b);
}

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

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */

const int NX = 55;

int inp[NX][NX], n, m, r, c, mv;

int MX[NX][NX];
vector<int> adj[(NX * NX) + 10];
int dp[(NX * NX)][NX], vis[(NX * NX)][NX], cs;
int Ase[(NX * NX) + 10];

int mxi(int x, int y)
{
	int svx = x, svy = y;
	int mx = -1;
	int tx, ty;
	int idx = (x * n) + y;
	Ase[idx] = inp[x][y];
	adj[idx].clear();
	while (x + 1 < n && y + 1 < n)
	{
		x += 1;
		y += 1;
		if (mx < inp[x][y])
		{
			mx = inp[x][y];
			adj[idx].clear();
			adj[idx].pb((x * n) + y);
		}
		else if (mx == inp[x][y])
		{
			adj[idx].pb((x * n) + y);
		}
	}
	x = svx, y = svy;
	while (x + 1 < n && y - 1 >= 0)
	{
		x += 1;
		y -= 1;
		if (mx < inp[x][y])
		{
			mx = inp[x][y];
			adj[idx].clear();
			adj[idx].pb((x * n) + y);
		}
		else if (mx == inp[x][y])
		{
			adj[idx].pb((x * n) + y);
		}
	}
	x = svx, y = svy;
	while (x - 1 >= 0 && y + 1 < n)
	{
		x -= 1;
		y += 1;
		if (mx < inp[x][y])
		{
			mx = inp[x][y];
			adj[idx].clear();
			adj[idx].pb((x * n) + y);
		}
		else if (mx == inp[x][y])
		{
			adj[idx].pb((x * n) + y);
		}
	}
	x = svx, y = svy;
	while (x - 1 >= 0 && y - 1 >= 0)
	{
		x -= 1;
		y -= 1;
		if (mx < inp[x][y])
		{
			mx = inp[x][y];
			adj[idx].clear();
			adj[idx].pb((x * n) + y);
		}
		else if (mx == inp[x][y])
		{
			adj[idx].pb((x * n) + y);
		}
	}
	Ase[idx] = mx;
}

int DP(int idx, int mv)
{
	if (mv == 0)
		return 0;
	int &v = vis[idx][mv];
	int &ret = dp[idx][mv];
	if (v == cs)
		return ret;
	v = cs;
	ret = 0;
	int sz = adj[idx].size();
	rep(i, sz)
	{
		int u = adj[idx][i];
		ret = max(ret, DP(u, mv - 1) + Ase[idx]);
	}
	return ret;
}

int main()
{
	// I will always use scanf and printf
	// May be i won't be a good programmer but i will be a good human being

	int t = II;
	for (cs = 1; cs <= t; cs++)
	{
		n = II, mv = II;
		c = II, r = II;
		//go.clear();
		int idx = (r * n) + c;
		rep(i, n)
		{
			rep(j, n) inp[i][j] = II;
		}
		rep(i, n)
		{
			rep(j, n) mxi(i, j);
		}
		/*
        int mx = 0 ;
        int x = r , y = c ;
        int svx = x , svy = y ;
        while( x + 1 < n &&  y + 1< n )
        {
            x += 1 ;
            y += 1 ;
            int tmp = ( inp[ x ][ y ] * ( mv / 2 ) ) + ( mv % 2 ? inp[ x ][ y ] : 0 );
            tmp += ( MX[ x ][ y ] * ( mv/2 ) );
            mx = max( mx , tmp );
        }
        x = svx , y = svy ;
        while( x + 1 < n && y - 1 >= 0 )
        {
            x += 1 ;
            y -= 1 ;
          int tmp = ( inp[ x ][ y ] * ( mv / 2 ) ) + ( mv % 2 ? inp[ x ][ y ] : 0 );
            tmp += ( MX[ x ][ y ] * ( mv/2 ) );
            mx = max( mx , tmp );
        }
        x = svx , y = svy ;
        while( x - 1 >= 0 && y + 1 < n )
        {
            x -= 1 ;
            y += 1 ;
           int tmp = ( inp[ x ][ y ] * ( mv / 2 ) ) + ( mv % 2 ? inp[ x ][ y ] : 0 );
            tmp += ( MX[ x ][ y ] * ( mv/2 ) );
            mx = max( mx , tmp );
        }
        x = svx , y = svy ;
        while( x - 1 >= 0 && y - 1 >= 0 )
        {
            x -= 1 ;
            y -= 1 ;
             int tmp = ( inp[ x ][ y ] * ( mv / 2 ) ) + ( mv % 2 ? inp[ x ][ y ] : 0 );
            tmp += ( MX[ x ][ y ] * ( mv/2 ) );
            mx = max( mx , tmp );
        } */

		printf("%d\n", DP(idx, mv));
	}
	return 0;
}
/*
9
1 2 3 2 3 4
2 1 0
3 0 2 5 6
4 1 3 7 8 9
5 3 0
6 0 0
7 0 0
8 2 0
9 0 0
9
1 0 3 2 3 4
2 0 0
3 0 2 5 6
4 9 3 7 8 9
5 0 0
6 0 0
7 0 0
8 0 0
9 0 0
9
1 0 3 2 3 4
2 9 0
3 0 2 5 6
4 0 3 7 8 9
5 0 0
6 0 0
7 0 0
8 0 0
9 0 0
0
*/
