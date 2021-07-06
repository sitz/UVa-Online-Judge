#include <bits/stdc++.h>

using namespace std;

//#pragma comment(linker, "/STACK:60000000")

//Type Definition
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef map<string, int> msi;
typedef map<int, int> mii;

#define ERR 1e-9
#define PI 3.141592653589793

#define REP(i, n) for (i = 0; i < n; i++)
#define FOR(i, p, k) for (i = p; i < k; i++)
#define FOREACH(it, x) for (__typeof((x).begin()) it = (x.begin()); it != (x).end(); ++it)

#define Sort(x) sort(x.begin(), x.end())
#define Reverse(x) reverse(x.begin(), x.end())
#define MP(a, b) make_pair(a, b)
#define Clear(x, with) memset(x, with, sizeof(x))
#define SZ(x) (int)x.size()
#define pb push_back
#define popcount(i) __builtin_popcountll(i)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a) * ((b) / gcd(a, b)))
#define two(X) (1 << (X))
#define twoL(X) (((ll)(1)) << (X))
#define setBit(mask, i) (mask | two(i))
#define contain(S, X) (((S)&two(X)) != 0)
#define fs first
#define sc second
#define CS c_str()
#define EQ(a, b) (fabs((a) - (b)) < ERR)
#define Unique(store) store.resize(unique(store.begin(), store.end()) - store.begin());
#define Find(x, y) ((int)x.find(y))
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

//For debugging
#define debug_array(a, n)    \
	for (ll i = 0; i < n; i++) \
		cerr << a[i] << " ";     \
	cerr << endl;
#define debug_matrix(mat, row, col) \
	for (ll i = 0; i < row; i++)      \
	{                                 \
		for (ll j = 0; j < col; j++)    \
			cerr << mat[i][j] << " ";     \
		cerr << endl;                   \
	}
#define deb(a) cout << #a << " #-> " << a << endl
#define debug(args...) \
	{                    \
		dbg, args;         \
		cerr << endl;      \
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

//Important Functions
template <class T>
void setmax(T &a, T b)
{
	if (a < b)
	{
		a = b;
	}
}
template <class T>
void setmin(T &a, T b)
{
	if (b < a)
	{
		a = b;
	}
}
template <class T>
T Abs(T x)
{
	return x > 0 ? x : -x;
}
template <class T>
inline T sqr(T x)
{
	return x * x;
}
template <class T>
inline T Mod(T n, T m)
{
	return (n % m + m) % m;//For Positive Negative No.
}
template <class T>
string toString(T n)
{
	ostringstream oss;
	oss << n;
	oss.flush();
	return oss.str();
}
ll toInt(string s)
{
	ll r = 0;
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
ll Pow(ll B, ll P)
{
	ll R = 1;
	while (P > 0)
	{
		if (P % 2 == 1)
		{
			R = (R * B);
		}
		P /= 2;
		B = (B * B);
	}
	return R;
}
ll BigMod(ll B, ll P, ll M)
{
	ll R = 1;
	while (P > 0)
	{
		if (P % 2 == 1)
		{
			R = (R * B) % M;
		}
		P /= 2;
		B = (B * B) % M;
	}
	return R;
}
void binprint(ll mask, ll n)
{
	ll i;
	string s = "";
	do
	{
		s += (mask % 2 + '0');
		mask /= 2;
	} while (mask);
	Reverse(s);
	s = string(max(n - SZ(s), 0LL), '0') + s;
	for (i = SZ(s) - n; i < SZ(s); i++)
	{
		printf("%c", s[i]);
	}
	printf("\n");
}
void ASCII_Chart()
{
	ll i, j;
	int k;
	printf("ASCII Chart:(30-129)\n");
	FOR(i, 30, 50)
	{
		REP(j, 5)
		{
			k = i + j * 20;
			printf("%3d---> '%c'   ", k, k);
		}
		printf("\n");
	}
}

//int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};  //Not Leap Year

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={-1,-1,+0,+1,+1,+0};int dy[]={-1,+1,+2,+1,-1,-2}; //Hexagonal Direction

//#include<conio.h> //for using getch();

//struct edge{ int cost,node; edge(int _cost=0,int _node=0){cost=_cost;node=_node;}bool operator<(const edge &b)const {return cost>b.cost;}}; // Min Priority Queue
//bool comp(edge a,edge b){ return a.cost < b.cost;} //Asc Sort by cost

struct P
{
	int x, y;
	P(int xi = 0, int yi = 0)
	{
		x = xi;
		y = yi;
	};
	void scan()
	{
		scanf("%d%d", &x, &y);
	}
};

P p[10], a[10], pvt;
int n, r;

double dis(P a, P b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
P MV(P a, P b)
{
	return P(b.x - a.x, b.y - a.y);
}
int CP(P a, P b)
{
	return a.x * b.y - a.y * b.x;
}

bool com(P a, P b)
{
	int c = CP(MV(pvt, a), MV(pvt, b));
	if (c == 0)
	{
		return dis(pvt, a) < dis(pvt, b);
	}
	return c > 0;
}

double calL(int msk)
{
	//    deb(msk);
	if (msk == 0)
	{
		return 0;
	}
	int i, c = 0;
	for (i = 0; i < n; i++)
		if (msk & (1 << i))
		{
			a[c++] = p[i];
		}
	if (c == 1)
	{
		return 2 * PI * r;
	}
	else if (c == 2)
	{
		return dis(a[0], a[1]) * 2 + 2 * PI * r;
	}
	pvt = a[0];
	for (i = 1; i < c; i++)
		if (pvt.y > a[i].y)
		{
			pvt = a[i];
		}
		else if (pvt.y == a[i].y && pvt.x > a[i].x)
		{
			pvt = a[i];
		}
	int sl = 2;
	for (i = 2; i < c; i++)
		if (CP(MV(a[0], a[1]), MV(a[0], a[i])) == 0)
		{
			sl++;
		}
	if (sl == c)
	{
		double d = 0;
		for (i = 0; i < c; i++)
		{
			d = max(d, dis(pvt, a[i]));
		}
		return d * 2 + 2 * PI * r;
	}
	sort(a, a + c, com);
	//    deb(c);
	int j = 1;
	for (i = 2; i < c; i++)
	{
		//        debug("paisi",msk,j);
		while (j > 1 && CP(MV(a[j - 1], a[j]), MV(a[j - 1], a[i])) <= 0)
		{
			j--;
			//            deb(j);
		}
		//        debug(i,j);
		//        deb(i);
		a[++j] = a[i];
	}
	a[++j] = a[0];
	double p = 0;
	for (i = 0; i < j; i++)
	{
		p += dis(a[i], a[i + 1]);
	}
	return p + 2 * PI * r;
}

double dp[5 + (1 << 9)];
double stor[5 + (1 << 9)];

double go(int msk)
{
	if (msk == 0)
	{
		return 0;
	}
	double &re = dp[msk];
	if (re > -1)
	{
		return re;
	}
	re = stor[msk];
	//    re=0;
	int a, b;
	a = msk;
	while (a)
	{
		a = (a - 1) & msk;
		b = msk ^ a;
		re = min(re, go(b) + stor[a]);
	}
	return re;
}

int main()
{
	int i, j, test, Case = 1, x, y;
	double ans;
	while (scanf("%d%d", &n, &r) == 2)
	{
		if (n == 0 && r == 0)
		{
			break;
		}
		REP(i, n)
		p[i].scan();
		ans = 0;
		for (i = 0; i < two(n); i++)
		{
			dp[i] = -3;
			stor[i] = calL(i);
		}
		//        cout<<"OK"<<endl;
		ans = go(two(n) - 1);
		printf("Case %d: length = %.2lf\n", Case++, ans);
	}
	return 0;
}
