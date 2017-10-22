#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, a, b;
	while (scanf("%d%d%d", &n, &a, &b) != EOF)
	{
		int k = 1;
		while (n--)
		{
			a = (a + 1) / 2;
			b = (b + 1) / 2;
			k++;
			if (a == b)
			{
				break;
			}
		}
		printf("%d\n", k - 1);
	}
	return 0;
}
