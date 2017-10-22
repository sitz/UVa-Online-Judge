#include <bits/stdc++.h>

using namespace std;

/*
10714
Ants
*/
#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a > b ? b : a)
int main()
{
	int i, max, min, n, m, kases, k;
	scanf("%d", &kases);
	while (kases--)
	{
		scanf("%d%d", &n, &m);
		max = 0;
		min = 0;
		for (i = 0; i < m; i++)
		{
			scanf("%d", &k);
			min = MAX(min, MIN(k, n - k));
			max = MAX(max, MAX(k, n - k));
		}
		printf("%d %d\n", min, max);
	}
	return 0;
}
