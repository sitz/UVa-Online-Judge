#include <bits/stdc++.h>

using namespace std;

#define MAX 30

typedef long long sss;
char Link[MAX][MAX];
sss Path[MAX];
char F[MAX], str[MAX];
sss N, E;

sss Mark(sss n)
{
	sss i, j = 1;
	if (Path[n])
		return Path[n];
	for (i = 0; i < N; i++)
	{
		if (Link[n][i])
		{
			j = 0;
			Path[n] += Mark(i);
		}
	}
	if (j)
		Path[n] = 1;
	return Path[n];
}
void Reset()
{
	sss i, j;
	for (i = 0; i <= N; i++)
	{
		Path[i] = 0;
		for (j = 0; j <= N; j++)
			Link[i][j] = 0;
	}
}
sss Find(sss sum, sss c, sss level, sss len)
{
	sss i, j = 1, k;
	if (len == level)
	{
		printf("%lld\n", sum + 1);
		return 1;
	}
	k = str[level + 1] - 'A';
	for (i = 0; i < N; i++)
	{
		if (!Link[c][i])
			continue;
		if (i == k)
			if (Find(sum, i, level + 1, len))
				return 1;
		sum += Path[i];
	}
	return 1;
}
void Cal()
{
	int q, len;
	scanf("%d", &q);
	while (q--)
	{
		scanf("%s", str);
		len = strlen(str);
		printf("%s: ", str);
		Find(0, str[0] - 'A', 0, len - 1);
	}
}

int main()
{
	int i, u, v, kases;
	char ss[4];
	scanf("%d", &kases);
	while (kases--)
	{
		scanf("%lld%lld", &N, &E);
		for (i = 0; i < E; i++)
		{
			scanf("%s", ss);
			u = ss[0] - 'A';
			v = ss[1] - 'A';
			Link[u][v] = 1;
		}
		Mark(0);
		Cal();
		Reset();
	}
	return 0;
}
