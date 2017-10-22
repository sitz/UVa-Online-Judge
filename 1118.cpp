#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, m;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		printf("%d\n", !((n - m) & ((m - 1) / 2)));
	}
	return 0;
}
