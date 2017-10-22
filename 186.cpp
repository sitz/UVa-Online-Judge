#include <bits/stdc++.h>

using namespace std;

#define INF 500000000
#define MAXN 501

char s[80];
int n, c[MAXN][MAXN], Trace[MAXN][MAXN], namelen[MAXN];
string route[MAXN][MAXN], name1, name2;
map<string, int> idx;
vector<string> name;

void init()
{
	for (int i = 1; i < MAXN; i++)
	{
		for (int j = i + 1; j < MAXN; j++)
		{
			c[i][j] = c[j][i] = INF;
			Trace[i][j] = j;
			Trace[j][i] = i;
			route[i][j] = route[j][i] = "";
		}
		Trace[i][i] = i;
		c[i][i] = 0;
	}
	name.clear();
	name.push_back("");
	idx.clear();
	n = 0;
}

bool read_ln()
{
	int len, k = 0, w, u, v;
	gets(s);
	len = strlen(s);
	if (len == 0)
	{
		return false;
	}
	string r = "";
	name1 = name2 = "";
	while (s[k] != ',')
	{
		name1 += s[k++];
	}
	k++;
	while (s[k] != ',')
	{
		name2 += s[k++];
	}
	k++;
	while (s[k] != ',')
	{
		r += s[k++];
	}
	k++;
	sscanf(s + k, "%d", &w);
	u = idx[name1];
	if (u == 0)
	{
		u = idx[name1] = ++n;
		name.push_back(name1);
		namelen[n] = name[n].length();
	}
	v = idx[name2];
	if (v == 0)
	{
		v = idx[name2] = ++n;
		name.push_back(name2);
		namelen[n] = name[n].length();
	}
	if (w < c[u][v])
	{
		c[u][v] = c[v][u] = w;
		route[u][v] = route[v][u] = r;
	}
	return true;
}

void floyd()
{
	for (int k = 1; k < n; k++)
	{
		for (int u = 1; u < n; u++)
		{
			for (int v = 1; v < n; v++)
			{
				if (c[u][v] > c[u][k] + c[k][v])
				{
					c[u][v] = c[u][k] + c[k][v];
					Trace[u][v] = Trace[u][k];
				}
			}
		}
	}
}

void disp(int s, int f)
{
	printf("\n\n");
	printf("From                 To                   Route      Miles\n");
	printf("-------------------- -------------------- ---------- -----\n");
	int u, v = s;
	do
	{
		cout << name[v];
		for (int i = namelen[v]; i < 21; i++)
		{
			printf(" ");
		}
		u = Trace[v][f];
		cout << name[u];
		for (int i = namelen[u]; i < 21; i++)
		{
			printf(" ");
		}
		cout << route[u][v];
		for (int i = route[u][v].length(); i < 11; i++)
		{
			printf(" ");
		}
		printf("%5d\n", c[u][v]);
		v = u;
	} while (v != f);
	printf("                                                     -----\n");
	printf("                                          Total      ");
	printf("%5d\n", c[s][f]);
}

int main()
{
	init();
	while (read_ln())
		;
	floyd();
	while (gets(s))
	{
		name1 = name2 = "";
		int len = strlen(s), k = 0, u, v;
		while (s[k] != ',')
		{
			name1 += s[k++];
		}
		k++;
		while (k < len)
		{
			name2 += s[k++];
		}
		u = idx[name1];
		v = idx[name2];
		disp(u, v);
	}
	return 0;
}
