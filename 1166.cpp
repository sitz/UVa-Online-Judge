#include <bits/stdc++.h>

using namespace std;

#pragma comment(linker, "/STACK:102400000,102400000")

#define ll long long
#define clr(x, c, n) memset(x, c, sizeof(x[0]) * (n))
#define clr_all(x, c) memset(x, c, sizeof(x))
#define IT iterator
#define ls rt << 1
#define rs ls | 1
#define lson l, mid, ls
#define rson mid + 1, r, rs
#define middle l + r >> 1
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define eps (1e-8)
#define PI 3.1415926535897932384626433832795
#define E 2.7182818284590452353602874713527

template <class T>
T _min(T a, T b)
{
	return a < b ? a : b;
}
template <class T>
T _max(T a, T b)
{
	return a > b ? a : b;
}
template <class T>
T _abs(T a)
{
	return a > 0 ? a : -a;
}
template <class T>
T _mod(T a, T m)
{
	return a < m ? (a < 0 ? (a % m + m) % m : a) : a % m;
}
template <class T>
T _gcd(T a, T b)
{
	while (b)
	{
		T t = b;
		b = a % b;
		a = t;
	}
	return a;
}
template <class T>
void _swap(T &a, T &b)
{
	T t = b;
	b = a;
	a = t;
}
template <class T>
void getmax(T &a, T b)
{
	a = a > b ? a : b;
}
template <class T>
void getmin(T &a, T b)
{
	a = (a != -1 && a < b) ? a : b;
}

const int M = 40000 + 5;

int TS, cas = 1, n;
map<string, int> mp;
char s1[M << 5], s2[M << 5], tmp[444], id[33];
int l1, l2, len[M], tot;
set<int> pos[M];
int fa[M << 5];
string ans[M];

void getStr(char *s, int &l, int m)
{
	int i, j, k, c;
	for (i = 0, l = 0; i < m; i++)
	{
		gets(tmp);
		for (j = 0; tmp[j]; j++)
		{
			if (tmp[j] == '<')
			{
				for (j++, k = 0; tmp[j] != ':'; j++, id[k] = 0)
				{
					id[k++] = tmp[j];
				}
				for (j++, c = 0; tmp[j] != '>'; j++)
				{
					c *= 10, c += tmp[j] - '0';
				}
				if ((k = mp[id]) == 0)
				{
					mp[id] = (k = ++tot);
					pos[k].clear();
					len[k] = c;
				}
				pos[k].insert(l);
				for (k = len[k]; k >= 1; k--)
				{
					s[l++] = '*';
				}
			}
			else
			{
				s[l++] = tmp[j];
			}
		}
	}
	s[l] = 0;
}

int Find(int x)
{
	return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

bool Union(int x, int y)
{
	int xf = Find(x), yf = Find(y);
	if (s1[xf] != '*' && s1[yf] != '*')
	{
		if (s1[xf] != s1[yf])
		{
			return false;
		}
		fa[xf] = yf;
	}
	else if (s1[xf] != '*')
	{
		fa[yf] = xf;
	}
	else
	{
		fa[xf] = yf;
	}
	return true;
}

bool check()
{
	if (l1 != l2)
	{
		return false;
	}
	int i, j, k;
	for (i = 0; i < l1; i++)
	{
		fa[i] = i;
		if (s1[i] == '*' && s2[i] != '*')
		{
			s1[i] = s2[i];
		}
		else if (s2[i] == '*' && s1[i] != '*')
		{
			s2[i] = s1[i];
		}
		if (s1[i] != s2[i])
		{
			return false;
		}
	}
	for (i = 1; i <= tot; i++)
		for (set<int>::IT it = pos[i].begin(); it != pos[i].end(); it++)
			for (j = 0; j < len[i]; j++)
				if (!Union((*it) + j, (*pos[i].begin()) + j))
				{
					return false;
				}
	for (i = 0; i < l1; i++)
		if (s1[i] == '*')
		{
			s2[i] = s1[i] = s1[Find(i)];
		}
	//if(strcmp(s1,s2)) while(1);
	for (i = 1; i <= tot; i++)
	{
		ans[i].clear();
		for (j = 0, k = *pos[i].begin(); j < len[i]; j++)
		{
			ans[i] += s1[k + j];
		}
	}
	return true;
}

void run()
{
	int i, j;
	tot = 0;
	mp.clear();
	getchar();
	getStr(s1, l1, n);
	scanf("%d", &n);
	getchar();
	getStr(s2, l2, n);
	if (cas > 1)
	{
		cout << endl;
	}
	else
	{
		cas++;
	}
	if (check())
	{
		cout << "yes" << endl;
		for (map<string, int>::IT it = mp.begin(); it != mp.end(); it++)
		{
			cout << it->first << ' ' << ans[it->second] << endl;
		}
	}
	else
	{
		cout << "no" << endl;
	}
}

void presof()
{
}

int main()
{
	presof();
	while (~scanf("%d", &n))
	{
		run();
	}
	return 0;
}
