#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, d;
	while (scanf("%d %d", &a, &b) == 2 && a >= 0 && b >= 0)
	{
		d = abs(b - a);
		if (d > 50)
		{
			printf("%d\n", 100 - d);
		}
		else
		{
			printf("%d\n", d);
		}
	}
	return 0;
}
