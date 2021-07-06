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

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */

const int NX = 5005;

int ans[NX], from[NX], Q[NX], vis[NX], n, m, inp[NX];

void print(int u)
{
	if (u == -1)
		return;
	print(from[u]);
	printf("%d", ans[u]);
}
int main()
{
	// I will always use scanf and printf
	// May be i won't be a good  programmer but i will be a good human being
	while (scanf("%d", &n) == 1)
	{
		m = II;
		rep(i, m) inp[i] = II;
		if (!n)
		{
			printf("0\n");
			continue;
		}
		//  printf("here\n");
		sort(inp, inp + m);
		ms(vis, 0);
		int head = 0, rear = 0;
		rep(i, m)
		{
			if (inp[i] == 0)
				continue;
			int tmp = inp[i] % n;
			ans[rear] = inp[i];
			from[rear] = -1;
			Q[rear++] = tmp;
			vis[tmp] = 1;
		}
		bool flag = 1;
		while (head < rear)
		{
			int u = Q[head];
			// printf(" u :: %d\n" , u );
			if (u == 0)
			{
				print(head);
				flag = 0;
				printf("\n");
				break;
			}
			rep(i, m)
			{
				int tmp = (u * 10 + inp[i]) % n;
				if (vis[tmp] == 0)
				{
					vis[tmp] = 1;
					Q[rear] = tmp;
					from[rear] = head;
					ans[rear++] = inp[i];
				}
			}
			head++;
		}
		if (flag)
			printf("0\n");
	}
	return 0;
}
