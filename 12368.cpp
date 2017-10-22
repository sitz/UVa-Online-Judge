#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define nMAX (1 << 10 + 10)
#define mMAX 110

int ar[25], n;
int f[nMAX];
bool vis[nMAX][mMAX];

struct node
{
	int a, b, num;
};

void init()
{
	int a[100];
	node b[100];
	for (int x = 0; x < (1 << 10); x++)
	{
		int cnta = 0, cntb = 0;
		for (int i = 0; i < 10; i++)
			if (x & (1 << i))
			{
				a[cnta++] = i;
				vis[x][i] = true;
			}
		for (int i = 0; i < cnta; i++)
			for (int j = 0; j < cnta; j++)
				if (i != j)
				{
					int num = a[i] * 10 + a[j];
					b[cntb].a = i, b[cntb].b = j, b[cntb++].num = num;
					vis[x][num] = true;
				}
		for (int i = 0; i < cnta; i++)
			for (int j = 0; j < cnta; j++)
				if (i != j)
				{
					int num = a[i] + a[j];
					if (num <= 100)
					{
						vis[x][num] = true;
					}
				}
		for (int i = 0; i < cnta; i++)
			for (int j = 0; j < cntb; j++)
				if (i != b[j].a && i != b[j].b)
				{
					int num = a[i] + b[j].num;
					if (num <= 100)
					{
						vis[x][num] = true;
					}
				}
		for (int i = 0; i < cntb; i++)
			for (int j = 0; j < cntb; j++)
				if (b[i].a != b[j].a && b[i].a != b[j].b && b[i].b != b[j].a && b[i].b != b[j].b)
				{
					int num = b[i].num + b[j].num;
					if (num <= 100)
					{
						vis[x][num] = true;
					}
				}
	}
}

bool ok(int x)
{
	for (int i = 0; i < n; i++)
		if (!vis[x][ar[i]])
		{
			return false;
		}
	return true;
}

int number(int x)
{
	int sum = 0, p = 1;
	for (int i = 0; i < 10; i++)
		if ((1 << i) & x)
		{
			sum += i * p;
			p *= 10;
		}
	return sum;
}

int main()
{
	int T = 1;
	init();
	for (int i = 0; i < (1 << 10); i++)
		for (int j = 0; j < 10; j++)
			if (i & (1 << j))
			{
				f[i]++;
			}
	f[nMAX - 1] = 111;
	while (scanf("%d", &n) && n)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &ar[i]);
		}
		int k = 0, ans = nMAX - 1;
		for (int i = 0; i < (1 << 10); i++)
		{
			if (ok(i) && f[ans] >= f[i])
			{
				if (f[ans] == f[i] && number(ans) > number(i))
				{
					ans = i;
				}
				else if (f[ans] != f[i])
				{
					ans = i;
				}
			}
		}
		printf("Case %d: %d\n", T++, number(ans));
	}
	return 0;
}
