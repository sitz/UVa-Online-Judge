#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n) && n)
	{
		if (n == 1 || n % 3 == 2)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
	return 0;
}
