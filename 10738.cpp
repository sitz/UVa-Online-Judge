#include <bits/stdc++.h>

using namespace std;

#define N 1000005

bool p[N];
int m[N], M[N], prime[N / 10], factor[32], top;

void sieve()
{
	memset(p, 1, sizeof(p));
	p[0] = p[1] = top = 0;
	m[1] = 1;
	for (int i = 2; i < 1001; i++)
	{
		if (p[i])
		{
			m[i] = -1;
			prime[top++] = i;
			for (int j = i * i; j < N; j += i)
				p[j] = 0;
		}
	}
	for (int i = 4; i < N; i++)
	{
		if (p[i])
		{
			m[i] = -1;
			continue;
		}
		int t = i, k = 0, mk = 0;
		for (int j = 0; prime[j] < t && j < top; j++)
		{
			while (t % prime[j] == 0)
			{
				factor[k++] = prime[j];
				t /= prime[j];
			}
		}
		if (t != 1)
			factor[k++] = t;
		for (int j = 1; j < k; j++)
		{
			if (factor[j] == factor[j - 1])
			{
				mk = 1;
				break;
			}
		}
		if (mk)
			continue;
		if (k & 1)
			m[i] = -1;
		else
			m[i] = 1;
	}
	for (int i = 1; i < N; i++)
		M[i] = M[i - 1] + m[i];
}

int main()
{
	sieve();
	int n;
	while (scanf("%d", &n), n)
		printf("%8d%8d%8d\n", n, m[n], M[n]);
	return 0;
}
