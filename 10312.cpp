#include <bits/stdc++.h>

using namespace std;

#define maxn 30

typedef long long ss;

ss B[maxn], BB[maxn];

void Brack()
{
	ss d;
	B[1] = B[2] = 1;
	B[3] = 3;
	B[4] = 11;
	for (ss i = 5; i <= 26; i++)
	{
		d = 3 * (2 * i - 3) * B[i - 1] - (i - 3) * B[i - 2];
		B[i] = d / i;
	}
}
void Binary()
{
	BB[1] = 1;
	ss n, k, sum;
	for (n = 2; n <= 26; n++)
	{
		sum = 0;
		for (k = 1; k < n; k++)
		{
			sum += BB[k] * BB[n - k];
		}
		BB[n] = sum;
	}
}

int main()
{
	ss n, k;
	Brack();
	Binary();
	while (scanf("%lld", &n) == 1)
	{
		printf("%lld\n", B[n] - BB[n]);
	}
	return 0;
}
