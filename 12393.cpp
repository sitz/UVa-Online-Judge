#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000

static int a[MAXN];

int filter(int &n, int sum = 0)
{
	int l = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += a[i];
		if (sum >= 0)
		{
			a[l++] = sum;
			sum = 0;
		}
	}
	n = l;
	return sum;
}

int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n)
	{
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		reverse(a, a + n);
		filter(n, filter(n));
		printf("%d\n", n);
	}
	return 0;
}
