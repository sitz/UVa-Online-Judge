#include <bits/stdc++.h>

using namespace std;

#pragma comment(linker, "/STACK:102400000,102400000")

#define ll __int64
#define ull unsigned long long
#define eps 1e-8
#define NMAX 1000000000
#define MOD 1000000
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
#define PI acos(-1)
#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.end())
template <class T>
inline void scan_d(T &ret)
{
	char c;
	int flag = 0;
	ret = 0;
	while (((c = getchar()) < '0' || c > '9') && c != '-')
		;
	if (c == '-')
	{
		flag = 1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		ret = ret * 10 + (c - '0'), c = getchar();
	}
	if (flag)
	{
		ret = -ret;
	}
}
template <class T>
inline T Max(T a, T b)
{
	return a > b ? a : b;
}
template <class T>
inline T Min(T a, T b)
{
	return a < b ? a : b;
}
const int maxn = 50000 + 10;
char ch[maxn * 10];
int lch[maxn], rch[maxn], nct, pos;
char op[maxn][6];
struct node
{
	char s[6];
	int l, r, wei;
	bool operator<(const node &t) const
	{
		int p = strcmp(s, t.s);
		if (p == 0)
		{
			return l == t.l ? r < t.r : l < t.l;
		}
		return p > 0 ? 0 : 1;
	}
};
map<node, int> mp;
vector<node> v;
int flag[maxn], ji;
bool pp;
int ID(node x)
{
	if (mp.find(x) != mp.end())
	{
		pp = 1;
		return mp[x];
	}
	v.push_back(x);
	return mp[x] = v.size() - 1;
}

node make_node(char *s, int l, int r, int wei)
{
	node t;
	strcpy(t.s, s);
	t.l = l;
	t.r = r;
	t.wei = wei;
	return t;
}

int build(int u)
{
	int i = 0;
	while (ch[pos] >= 'a' && ch[pos] <= 'z')
	{
		op[u][i++] = ch[pos++];
	}
	int qi = ++ji;
	op[u][i] = '\0';
	//    cout<<op[u]<<" "<<pos<<endl;
	if (ch[pos] == '(')
	{
		pos++;
		lch[u] = ++nct;
		int ID1 = build(lch[u]);
		pos++;
		rch[u] = ++nct;
		int ID2 = build(rch[u]);
		pos++;
		pp = 0;
		int ret = ID(make_node(op[u], ID1, ID2, qi));
		if (pp)
		{
			flag[u] = v[ret].wei;
			ji--;
		}
		return ret;
	}
	pp = 0;
	int ret = ID(make_node(op[u], -1, -1, qi));
	if (pp)
	{
		flag[u] = v[ret].wei;
		ji--;
	}
	//    if(pos == 21) cout<<op[u]<<" "<<flag[u]<<" "<<qi<<endl;
	return ret;
}

void dfs(int u)
{
	if (flag[u])
	{
		printf("%d", flag[u]);
		return;
	}
	printf("%s", op[u]);
	if (lch[u] != 0)
	{
		printf("(");
		dfs(lch[u]);
		printf(",");
		dfs(rch[u]);
		printf(")");
	}
}

int main()
{
#ifdef GLQ
	freopen("input.txt", "r", stdin);
//    freopen("o.txt","w",stdout);
#endif
	int cas;
	scanf("%d\n", &cas);
	while (cas--)
	{
		scanf("%s", ch);
		nct = 1;
		pos = ji = 0;
		mp.clear();
		v.clear();
		memset(flag, 0, sizeof(flag));
		memset(lch, 0, sizeof(lch));
		memset(rch, 0, sizeof(rch));
		build(1);
		dfs(1);
		printf("\n");
	}
	return 0;
}
