#include <bits/stdc++.h>

using namespace std;

/*
Nature
10685
*/

#define MAXN 5002
struct Friends
{
	int parent;
	int rank;
	int count;
} F[MAXN];
int N, M, MAX;
map<string, int> mp;
int Find(int n)
{
	if (n != F[n].parent)
	{
		F[n].parent = Find(F[n].parent);
	}
	return F[n].parent;
}
void Link(int x, int y)
{
	if (F[x].rank > F[y].rank)
	{
		F[y].parent = x;
		F[x].count += F[y].count;
		if (MAX < F[x].count)
		{
			MAX = F[x].count;
		}
	}
	else
	{
		F[x].parent = y;
		F[y].count += F[x].count;
		if (MAX < F[y].count)
		{
			MAX = F[y].count;
		}
		if (F[x].rank == F[y].rank)
		{
			F[y].rank++;
		}
	}
}
void Cal()
{
	int i, a, b, x, y;
	char ss[40], sss[40];
	MAX = 0;
	for (i = 1; i <= N; i++)
	{
		F[i].parent = i;
		F[i].rank = 0;
		F[i].count = 1;
	}
	for (i = 1; i <= M; i++)
	{
		scanf("%s%s", ss, sss);
		a = mp[ss];
		b = mp[sss];
		x = Find(a);
		y = Find(b);
		if (x != y)
		{
			Link(x, y);
		}
	}
	if (!MAX)
	{
		MAX++;
	}
	printf("%d\n", MAX);
}
int main()
{
	int i;
	char sss[100];
	while (scanf("%d%d", &N, &M) == 2)
	{
		if (!N && !M)
		{
			break;
		}
		for (i = 1; i <= N; i++)
		{
			scanf("%s", sss);
			mp[sss] = i;
		}
		Cal();
	}
	return 0;
}
