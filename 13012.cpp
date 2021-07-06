#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		int x, res = 0;
		for (int i = 0; i < 5; i++)
		{
			scanf("%d", &x);
			res += n == x;
		}
		printf("%d\n", res);
	}
	return 0;
}
