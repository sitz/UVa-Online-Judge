#include <bits/stdc++.h>

using namespace std;

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

int N, G, U, nodes;
vector<int> adj[110], store;
int color[110];
int dp[1 << 8][21][4];

struct Node
{
	char type;
	vector<int> in;
	int out;
};

Node Ele[100];

void dfs(int u)
{
	color[u] = 1;
	int i, v;
	REP(i, SZ(adj[u]))
	{
		v = adj[u][i];
		if (color[v] == 0)
		{
			dfs(v);
		}
	}
	store.pb(u);
}

vector<int> Topological(int nodes)
{
	int i;
	Clear(color, 0);
	store.clear();
	for (i = 1; i <= nodes; i++)
	{
		if (color[i] == 0)
		{
			dfs(i);
		}
	}
	Reverse(store);
	//    for(i=0;i<SZ(store);i++)
	//        cout<<store[i]<<" ";
	//    cout<<endl;
	return store;
}

//#include<conio.h>

void Simulate(int mask, int gateN, int type)
{
	int i, j, v;
	for (i = 0; i <= nodes; i++)
	{
		Ele[i].in.clear();
	}
	for (i = 0; i < N; i++)
		if (contain(mask, i))
		{
			Ele[i + 1].out = 1;
		}
		else
		{
			Ele[i + 1].out = 0;
		}
	for (i = 0; i < SZ(store); i++)
	{
		Node u = Ele[store[i]];
		if (u.type == 'a')
		{
			u.out = (u.in[0] & u.in[1]);
		}
		else if (u.type == 'o')
		{
			u.out = (u.in[0] | u.in[1]);
		}
		else if (u.type == 'x')
		{
			u.out = (u.in[0] ^ u.in[1]);
		}
		else if (u.type == 'n')
		{
			u.out = !(u.in[0]);
		}
		if (gateN && (u.type == 'a' || u.type == 'x' || u.type == 'n' || u.type == 'o') && gateN + N == store[i])
		{
			if (type == 1)
			{
				u.out = !u.out;
			}
			else if (type == 2)
			{
				u.out = 0;
			}
			else
			{
				u.out = 1;
			}
		}
		for (j = 0; j < SZ(adj[store[i]]); j++)
		{
			v = adj[store[i]][j];
			Ele[v].in.pb(u.out);
			//            debug(store[i],v,u.out);
			//            getch();
		}
	}
	int outMask = 0;
	for (i = N + G + 1, j = 0; i <= nodes; i++, j++)
	{
		if (Ele[i].in[0])
		{
			outMask |= two(j);
		}
	}
	dp[mask][gateN][type] = outMask;
}

int main()
{
	//    freopen("B.in","r",stdin);
	//freopen("out.out","w",stdout);
	int i, j, test, Case = 1, n, x, y, num, ind;
	char ch;
	char temp[110];
	string str;
	//    scanf("%d",&test);
	while (scanf("%d %d %d ", &N, &G, &U) == 3)
	{
		//        debug(N,G,U);
		if (!N && !G && !U)
		{
			break;
		}
		REP(i, 100)
		adj[i].clear();
		for (i = 1; i <= 100; i++)
		{
			Ele[i].in.clear();
		}
		for (i = 1; i <= N; i++)
		{
			Ele[i].type = 'i';
		}
		for (i = 1; i <= G; i++)
		{
			//ith gate
			gets(temp);
			str = temp;
			stringstream iss(str);
			while (iss >> str)
			{
				if (SZ(str) == 1)
				{
					Ele[i + N].type = str[0];
				}
				else
				{
					ch = str[0];
					num = toInt(str.substr(1));
					if (ch == 'g')
					{
						num += N;
					}
					adj[num].pb(i + N);
				}
			}
		}
		for (i = 1; i <= U; i++)
		{
			Ele[i + N + G].type = 'u';
			scanf("%d", &ind);
			adj[N + ind].pb(i + N + G);
		}
		nodes = N + G + U;
		//        for(i=1;i<=nodes;i++)
		//            debug("i: ",i,Ele[i].type);
		//        debug(N,G,U);
		//        debug("Complete\n\n");
		Topological(nodes);
		//        debug("Came Here:")
		int mask, type, g;
		for (mask = 0; mask < two(N); mask++)
		{
			Simulate(mask, 0, 0);
			//            debug(mask,dp[mask][0][0]);
			for (type = 1; type <= 3; type++)
			{
				for (g = 1; g <= G; g++)
				{
					Simulate(mask, g, type);
				}
			}
		}
		int B, val, outMask;
		scanf("%d", &B);
		vector<pii> obs;
		for (i = 1; i <= B; i++)
		{
			mask = 0;
			for (j = 1; j <= N; j++)
			{
				scanf("%d", &val);
				if (val)
				{
					mask |= two(j - 1);
				}
			}
			outMask = 0;
			for (j = 1; j <= U; j++)
			{
				scanf("%d", &val);
				if (val)
				{
					outMask |= two(j - 1);
				}
			}
			obs.pb(MP(mask, outMask));
		}
		//        debug("complete");
		bool check = true;
		for (i = 0; i < SZ(obs); i++)
		{
			val = dp[obs[i].fs][0][0];
			if (val != obs[i].sc)
			{
				check = false;
				break;
			}
		}
		if (check)
		{
			printf("Case %d: No faults detected\n", Case++);
			continue;
		}
		int cnt = 0, ansG, ansT;
		for (type = 1; type <= 3; type++)
		{
			for (g = 1; g <= G; g++)
			{
				bool check = true;
				for (i = 0; i < SZ(obs); i++)
				{
					val = dp[obs[i].fs][g][type];
					if (val != obs[i].sc)
					{
						check = false;
						break;
					}
				}
				if (check)
				{
					cnt++;
					ansG = g;
					ansT = type;
				}
			}
		}
		printf("Case %d: ", Case++);
		if (cnt == 1)
		{
			if (ansT == 1)
			{
				printf("Gate %d is failing; output inverted\n", ansG);
			}
			else if (ansT == 2)
			{
				printf("Gate %d is failing; output stuck at 0\n", ansG);
			}
			else
			{
				printf("Gate %d is failing; output stuck at 1\n", ansG);
			}
		}
		else
		{
			printf("Unable to totally classify the failure\n");
		}
	}
	return 0;
}
