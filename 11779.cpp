#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> paii;
typedef pair<ll, ll> pall;

#define PI (2.0 * acos(0))
#define ERR 1e-5
#define mem(a, b) memset(a, b, sizeof a)
#define pb push_back
#define popb pop_back
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define SZ(x) (int)x.size()
#define oo (1 << 25)
#define FOREACH(it, x) for (__typeof((x).begin()) it = (x.begin()); it != (x).end(); ++it)
#define Contains(X, item) ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcountll(i))
#define fs first
#define sc second
#define EQ(a, b) (fabs(a - b) < ERR)
#define MAX 55
#define twoL(X) (((ll)(1)) << (X))

template <class T1>
void deb(T1 e)
{
	cout << e << endl;
}
template <class T1, class T2>
void deb(T1 e1, T2 e2) { cout << e1 << " " << e2 << endl; }
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) { cout << e1 << " " << e2 << " " << e3 << endl; }
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4) { cout << e1 << " " << e2 << " " << e3 << " " << e4 << endl; }
template <class T1, class T2, class T3, class T4, class T5>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) { cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl; }
template <class T1, class T2, class T3, class T4, class T5, class T6>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) { cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6 << endl; }

template <class T>
T Abs(T x) { return x > 0 ? x : -x; }
template <class T>
inline T sqr(T x) { return x * x; }
ll Pow(ll B, ll P)
{
	ll R = 1;
	while (P > 0)
	{
		if (P % 2 == 1)
			R = (R * B);
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
}/// (B^P)%M

///int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

int dist[MAX][MAX];
vector<int> v[MAX];
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int cas, loop = 0, n, e, a, b, w;
	scanf("%d", &cas);
	while (cas--)
	{
		scanf("%d %d", &n, &e);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dist[i][j] = 0;
		for (int i = 0; i < e; i++)
		{
			scanf("%d %d %d", &a, &b, &w);
			dist[a][b] = w;
		}

		for (int i = 0; i < n; i++)
			v[i].clear();

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
				{
					dist[i][j] -= dist[i][k] * dist[k][j];
				}

		e = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				e += dist[i][j];
		printf("Case %d: %d %d\n", ++loop, n, e);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (dist[i][j])
					v[i].pb(j);

		for (int i = 0; i < n; i++)
		{
			printf("%d", SZ(v[i]));
			for (int j = 0; j < SZ(v[i]); j++)
				printf(" %d", v[i][j]);
			puts("");
		}
	}

	return 0;
}
