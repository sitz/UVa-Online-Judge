#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, t = 1;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		printf("Case %d: %d\n", t++, n / 2);
	}
	return 0;
}
