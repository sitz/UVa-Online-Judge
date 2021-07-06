#include <bits/stdc++.h>

using namespace std;

#define mem(name, value) memset(name, value, sizeof(name))
#define FOR(i, n) for (int i = 1; i <= n; i++)

const int maxn = 40;

char s[maxn];

int v[maxn], x, y;

void init()
{
	mem(v, 0);
	for (int i = 0; i < 6; i++)
	{
		scanf("%s", s);
		int u = s[0] - 'A' + 1;
		int k = s[1] - 'A' + 1;
		if (v[u])
		{
			continue;
		}
		v[u] = k;
	}
	if (v[2] != 1 && v[3] != 1)
	{
		x = 3;
		y = 0;
	}
	else if (v[v[1]] == 1)
	{
		x = 3;
		y = 2;
	}
	else
	{
		x = 2;
		y = 1;
	}
}

long long d[maxn];

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		init();
		d[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			d[i] = d[i - 1] * x + y;
		}
		printf("%lld\n", d[n]);
	}
	return 0;
}
