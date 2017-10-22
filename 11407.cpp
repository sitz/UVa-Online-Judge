#include <bits/stdc++.h>

using namespace std;

#define min(a, b) (a < b) ? a : b
int n[10005];
int main()
{
	int i, j;
	for (i = 0; i < 10005; i++)
	{
		n[i] = 4;
	}
	for (i = 1; i * i <= 10000; i++)
	{
		n[i * i] = 1;
	}
	n[0] = 0;
	for (i = 1; i <= 10000; i++)
		for (j = 1; j <= i; j++)
			if (n[j] == 1)
			{
				n[i] = min(n[i], 1 + n[i - j]);
			}
	scanf("%d\n", &i);
	while (scanf("%d", &i) == 1)
	{
		printf("%d\n", n[i]);
	}
	return 0;
}
