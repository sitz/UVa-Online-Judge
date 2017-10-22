#include <bits/stdc++.h>

using namespace std;

const int MAX = 4000100;
typedef long long int ll;
ll eulerphi[MAX], G[MAX];
void precompute()
{
	for (int i = 0; i < MAX; i++)
	{
		eulerphi[i] = i;
	}
	for (int i = 2; i < MAX; i++)
	{
		if (eulerphi[i] == i)
		{
			eulerphi[i]--;
			for (int j = 2 * i; j < MAX; j += i)
			{
				eulerphi[j] *= (i - 1);
				eulerphi[j] /= i;
			}
		}
	}
}
int main()
{
	precompute();
	for (ll k = 1; k <= MAX; k++)
	{
		G[k] = 0;
	}
	for (ll k = 1; k <= MAX; k++)
		for (ll n = 2 * k; n <= MAX; n += k)
		{
			G[n] += k * eulerphi[n / k];
		}
	for (ll k = 2; k <= MAX; k++)
	{
		G[k] += G[k - 1];
	}
	int num;
	while (scanf("%d", &num) == 1)
	{
		if (num == 0)
		{
			break;
		}
		printf("%lld\n", G[num]);
	}
}
