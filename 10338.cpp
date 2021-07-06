#include <bits/stdc++.h>

using namespace std;

int main()
{
	int X[128], i, j, t, tt;
	long long int a, b;
	char in[30];
	scanf("%d", &tt);
	for (t = 1; t <= tt; t++)
	{
		scanf("%s", in);
		a = b = 1LL;
		for (i = 'A'; i <= 'Z'; i++)
		{
			X[i] = 0;
		}
		for (i = 0; in[i] != '\0'; i++)
		{
			a *= (i + 1);
			b *= (++X[in[i]]);
		}
		printf("Data set %d: %lld\n", t, a / b);
	}
	return 0;
}
