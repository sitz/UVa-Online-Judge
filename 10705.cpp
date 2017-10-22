#include <bits/stdc++.h>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define maxN 70
#define MIN -9223372036854775807LL

typedef long long LL;
typedef unsigned long long ULL;

bool mark[maxN], solved;
char res[maxN];
int k;
LL n;
ULL pw[maxN];
string s;

void backTrack(int x, LL val)
{
	if (solved)
	{
		return;
	}
	if (x == k)
	{
		if (val == n)
		{
			solved = true;
		}
		return;
	}
	LL mn = val, mx = val;
	fr(i, x, k - 1)
	{
		if (s[i] == 'n')
		{
			mn -= pw[k - i - 1];
		}
		else if (s[i] == 'p')
		{
			mx += pw[k - i - 1];
		}
	}
	if (n < mn || mx < n)
	{
		return;
	}
	LL add = pw[k - x - 1];
	if (s[x] == 'n')
	{
		add = -add;
	}
	res[x] = 1 + '0';
	backTrack(x + 1, val + add);
	if (solved)
	{
		return;
	}
	res[x] = 0 + '0';
	backTrack(x + 1, val);
}

int main()
{
	pw[0] = 1LL;
	fr(i, 1, 63)
	{
		pw[i] = pw[i - 1] * 2LL;
	}
	int cases;
	for (scanf("%d", &cases); cases--;)
	{
		scanf(" %d ", &k);
		cin >> s >> n;
		fill(mark, false);
		solved = false;
		if (n < MIN)
		{
			if (k == 64 && s[0] == 'n')
			{
				rep(i, k)
				{
					res[i] = '0';
				}
				res[0] = '1';
				solved = true;
			}
		}
		else
		{
			backTrack(0, 0LL);
		}
		if (!solved)
		{
			printf("Impossible\n");
		}
		else
		{
			rep(i, k)
			{
				putchar(res[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
