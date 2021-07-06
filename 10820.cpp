#include <bits/stdc++.h>

using namespace std;

/*
10820
Send a Table
*/
#define MAXN 50002
int R[MAXN];
int RP(int n)
{
	int sum = n;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			sum -= sum / i;
		}
		while (n % i == 0)
		{
			n /= i;
		}
	}
	if (n > 1)
	{
		sum -= sum / n;
	}
	return sum;
}
void Gen()
{
	int i;
	R[1] = 1;
	for (i = 2; i + 1 < MAXN; i++)
	{
		R[i] = RP(i) * 2;
		R[i] += R[i - 1];
	}
}
int main()
{
	int n;
	Gen();
	while (scanf("%d", &n) && n)
	{
		printf("%d\n", R[n]);
	}
	return 0;
}
