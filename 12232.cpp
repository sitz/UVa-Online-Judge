#include <bits/stdc++.h>

using namespace std;

#define MX 100005
#define REP(i, n) for (int i = 0; i < (n); i++)
#define OREP(i, n) for (int i = 1; i <= (n); i++)

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UINT;

int n, m, k, t;

char cmd[10];
inline void Getline(char *input)
{
	scanf("%[^\n]s", input);
	getchar();
}
bool ok;
char input[MX * 10];
int a, b;
int pa[MX], dis[MX], key[MX];
int find(int a)
{
	if (a == pa[a])
	{
		return a;
	}
	int par = find(pa[a]);
	dis[a] = dis[a] ^ dis[pa[a]];
	pa[a] = par;
	return par;
}
bool got[MX];
void query(stringstream &sin)
{
	memset(got, false, sizeof got);
	if (!ok)
	{
		return;
	}
	sin >> k;
	int a;
	int ret = 0;
	REP(i, k)
	{
		sin >> a;
		int p_a = find(a);
		got[p_a] ^= true;
		ret ^= dis[a];
	}
	REP(i, n)
	{
		if (got[i])
		{
			if (key[i] == -1)
			{
				ret = -1;
				break;
			}
			ret ^= key[i];
		}
	}
	if (ret == -1)
	{
		printf("I don't know.\n");
	}
	else
	{
		printf("%d\n", ret);
	}
}
bool insert(int a, int b, int c)
{
	int p_a = find(a), p_b = find(b);
	if (p_a == p_b)
	{
		return (dis[a] ^ dis[b]) == c;
	}
	dis[p_a] = (dis[a] ^ c);
	pa[p_a] = b;
	if (key[p_a] != -1 && key[p_b] != -1)
	{
		return (key[p_a] ^ key[p_b]) == (dis[p_a] ^ dis[b]);
	}
	else if (key[p_a] != -1)
	{
		key[p_b] = (dis[b] ^ dis[p_a] ^ key[p_a]);
	}
	return true;
}
bool insert(int a, int b)
{
	if (key[a] != -1)
	{
		return key[a] == b;
	}
	int p = find(a);
	if (p != a)
	{
		if (key[p] != -1)
		{
			return (key[p] ^ b) == dis[a];
		}
		else
		{
			key[p] = (dis[a] ^ b);
		}
	}
	key[a] = b;
	return true;
}
bool insert(stringstream &sin)
{
	int a, b, c;
	if (!ok)
	{
		return ok;
	}
	sin >> a;
	sin >> b;
	if (sin >> c)
	{
		return insert(a, b, c);
	}
	else
	{
		return insert(a, b);
	}
}
void init()
{
	REP(i, n)
	{
		pa[i] = i;
		dis[i] = 0;
		key[i] = -1;
	}
}
int main()
{
	int c = 1;
	while (1)
	{
		int cl = 0;
		ok = true;
		Getline(input);
		stringstream sin(input);
		sin >> n >> m;
		init();
		if (!n)
		{
			break;
		}
		printf("Case %d:\n", c++);
		REP(i, m)
		{
			Getline(input);
			stringstream sin2(input);
			sin2 >> cmd;
			if (cmd[0] == 'Q')
			{
				if (ok)
				{
					query(sin2);
				}
			}
			else if (cmd[0] != 'I')
			{
				continue;
			}
			else if (ok)
			{
				cl++;
				ok = insert(sin2);
				if (!ok)
				{
					printf("The first %d facts are conflicting.\n", cl);
				}
			}
		}
		printf("\n");
	}
	return 0;
}
