#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf
#define wh while
#define st struct
#define ma malloc
#define me memset
#define spf sprintf
#define ssf sscanf
#define inf 2147483647
#define ll long long

const int maxl = 1000007;
const int maxz = 1007;

bool maz[maxz][maxz];
char in[maxl];
int t, n, m, i, j, k, u, cas, ilen, plen, nlen;

bool ch(int n)
{
	wh(n != 1)
	{
		if (n % 2)
			return 0;
		n /= 2;
	}
	return 1;
}

void init()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			maz[i][j] = 0;
	ilen = strlen(in);
}

void rec(int plen, int k, int posx, int posy)
{
	for (int i = posx; i < posx + plen; i++)
		for (int j = posy; j < posy + plen; j++)
			maz[i][j] = k;
}

int dfs(int j, int plen, int posx, int posy)
{
	if (j >= ilen)
		return 0;
	int i;
	for (i = 0; i < 4 && j + i < ilen; i++)
		if (in[j + i] != '*')
		{
			if (i == 0)
				rec(plen, in[j + i] - '0', posx, posy);
			else if (i == 1)
				rec(plen, in[j + i] - '0', posx, posy + plen);
			else if (i == 2)
				rec(plen, in[j + i] - '0', posx + plen, posy);
			else if (i == 3)
				rec(plen, in[j + i] - '0', posx + plen, posy + plen);
		}
		else
		{
			if (i == 0)
				j = dfs(i + j + 1, plen / 2, posx, posy);
			else if (i == 1)
				j = dfs(i + j + 1, plen / 2, posx, posy + plen);
			else if (i == 2)
				j = dfs(i + j + 1, plen / 2, posx + plen, posy);
			else if (i == 3)
				j = dfs(i + j + 1, plen / 2, posx + plen, posy + plen);
			j -= (i + 1);
		}
	return j + i;
}

void output()
{
	bool flag = 0;
	int p;
	for (int i = 1; i <= n; i++)
	{
		int j = 0;
		wh(j <= n)
		{
			wh(j <= n && maz[i][j] == 0) j++;
			if (j <= n)
			{
				if (flag)
					pf(",");
				pf("(%d", j);
				p = j;
			}
			else
				break;
			wh(j <= n && maz[i][j] == 1) j++;
			if (p != j - 1)
				pf("-%d", j - 1);
			pf(",%d)", i);
			flag = 1;
		}
	}
	puts("");
}

int main()
{
	sf("%d", &t);
	wh(t--)
	{
		sf("%d", &n);
		sf("%s", in);
		if (!ch(n))
		{
			puts("Invalid length");
			continue;
		}
		init();
		dfs(0, n, 1, 1);
		output();
	}
	return 0;
}
