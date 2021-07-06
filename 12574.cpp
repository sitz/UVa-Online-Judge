#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;
int a[5000];

int main()
{
	int T, n, i;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		long long J = 1, S = 1;
		for (i = 0; i < n; i++)
		{
			scanf("%d", a + i), S += a[i], J *= (a[i] + 1);
			if (S >= M)
				S -= M;
			J %= M;
		}
		printf("%d\n", (J - S + M) % M);
	}
	return 0;
}
