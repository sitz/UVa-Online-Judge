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
#define __(args...) \
	{                 \
		dbg, args;      \
		cerr << endl;   \
	}
struct debugger
{
	template <typename T>
	debugger &operator,(const T &v)
	{
		cerr << v << "\t";
		return *this;
	}
} dbg;
#define __1D(a, n) \
	rep(i, n)        \
	{                \
		if (i)         \
			printf(" "); \
		cout << a[i];  \
	}
#define __2D(a, r, c, f) \
	forab(i, f, r - !f)    \
	{                      \
		forab(j, f, c - !f)  \
		{                    \
			if (j != f)        \
				printf(" ");     \
			cout << a[i][j];   \
		}                    \
		cout << endl;        \
	}

template <class A, class B>
ostream &operator<<(ostream &o, const pair<A, B> &p)
{
	return o << "(" << p.ff << ", " << p.ss << ")";//Pair print
}
template <class T>
ostream &operator<<(ostream &o, const vector<T> &v)
{
	o << "[";//Vector print
	forstl(it, v) o << *it << ", ";
	return o << "]";
}
template <class T>
ostream &operator<<(ostream &o, const set<T> &v)
{
	o << "[";//Set print
	forstl(it, v) o << *it << ", ";
	return o << "]";
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

const int NX = 1e5 + 10;

int inp[2][2][NX];

int main()
{

	int cs, t = II;
	for (cs = 1; cs <= t; cs++)
	{

		int idx = II;
		int sv = idx;
		int idx1 = 0;
		bool update = 1;
		set<int> s;
		rep(i, idx)
		{
			inp[0][0][i] = II;
			s.insert(inp[0][0][i]);
			inp[0][1][i] = inp[0][0][i];// 0 for min 1 for max
		}
		if (s.size() != idx)
		{
			puts("no");
			continue;
		}
		idx--;
		int prv = 0, cur = 1;
		int total = 0;
		while (update && idx != 0 && total++ <= 1000)
		{
			update = 0;
			idx1 = 0;
			inp[cur][0][idx1] = inp[prv][0][0];
			inp[cur][1][idx1] = inp[prv][1][0];
			for (int i = 1; i <= idx; i++)
			{
				// same
				if (inp[cur][0][idx1] == inp[prv][0][i] && inp[cur][1][idx1] == inp[prv][1][i])
					continue;
				if (inp[prv][1][i] + 1 == inp[cur][0][idx1])
				{
					inp[cur][0][idx1] = min(inp[cur][0][idx1], inp[prv][0][i]);
					inp[cur][1][idx1] = max(inp[cur][1][idx1], inp[prv][1][i]);
					update = 1;
				}
				else if (inp[prv][0][i] - 1 == inp[cur][1][idx1])
				{
					inp[cur][0][idx1] = min(inp[cur][0][idx1], inp[prv][0][i]);
					inp[cur][1][idx1] = max(inp[cur][1][idx1], inp[prv][1][i]);
					update = 1;
				}
				else if (inp[cur][0][idx1] <= inp[prv][0][i] && inp[cur][1][idx1] >= inp[prv][1][i])
				{
					update = 1;
				}
				else if (inp[cur][0][idx1] <= inp[prv][0][i] && inp[prv][0][i] <= inp[cur][1][idx1] && inp[prv][1][i] > inp[cur][1][idx1])
				{
					inp[cur][1][idx1] = inp[prv][1][i];
					update = 1;
				}
				else if (inp[cur][0][idx1] > inp[prv][0][i] && inp[prv][1][i] >= inp[cur][0][idx1] && inp[prv][1][i] <= inp[cur][1][idx1])
				{
					inp[cur][0][idx1] = inp[prv][0][1];
					update = 1;
				}
				// here
				else if (inp[prv][0][i] <= inp[cur][0][idx1] && inp[cur][1][idx1] >= inp[prv][0][1] && inp[cur][1][idx1] <= inp[prv][1][i])
				{
					inp[cur][0][idx1] = inp[prv][0][i];
					inp[cur][1][idx1] = inp[prv][1][i];
					update = 1;
				}
				// now
				else if (inp[cur][0][idx1] <= inp[prv][0][i] && inp[prv][0][i] <= inp[cur][1][idx1] && inp[prv][1][i] > inp[cur][1][idx1])
				{
					inp[cur][1][idx1] = inp[prv][1][i];
					update = 1;
				}
				// update
				else if (inp[cur][0][idx1] > inp[prv][0][i] && inp[cur][0][idx1] <= inp[prv][1][i] && inp[cur][1][idx1] >= inp[prv][1][i])
				{
					inp[cur][0][idx1] = inp[prv][0][i];
					update = 1;
				}

				else
				{
					++idx1;
					inp[cur][0][idx1] = inp[prv][0][i];
					inp[cur][1][idx1] = inp[prv][1][i];
				}
			}
			swap(idx1, idx);
			swap(cur, prv);
		}
		/*cout << idx << endl ;
        rep( i , idx + 1 )
        {
            printf("min :: %d mx :: %d\n " , inp[ prv ][ 0 ][ i ] , inp[prv][1][i] );
        } */
		if (total >= 1000 || (idx == 0 && inp[prv][0][0] == 1 && inp[prv][1][0] == sv))
			puts("yes");
		else
			puts("no");
	}
}
/*

4
4
1 2 4 3
4
1 2 4 4
4
1 1 1 1
2
1 1

*/
