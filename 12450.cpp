#include <bits/stdc++.h>

using namespace std;

struct play
{
	char c[22];
	int mat;
} p[1111];

bool cmp1(play a, play b)
{
	return a.mat > b.mat;
}

bool cmp2(play a, play b)
{
	return strcmp(a.c, b.c) < 0;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		n = 1 << n;
		for (int i = 0; i < n; i++)
		{
			memset(p[i].c, 0, sizeof(p[i].c));
			scanf("%s %d", p[i].c, &p[i].mat);
		}
		sort(p, p + n, cmp1);
		printf("%s\n%s\n", p[0].c, p[1].c);
		int nn = 2;
		int now = 2;
		while (now < n)
		{
			sort(p + now, p + now + nn, cmp2);
			now += nn;
			nn *= 2;
		}
		for (int i = 2; i < n; i++)
		{
			printf("%s\n", p[i].c);
		}
	}
	return 0;
}
