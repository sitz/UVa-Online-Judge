#include <bits/stdc++.h>

using namespace std;

#define MAXN 2000000

typedef long long LL;

int ind, N, div_[MAXN];

LL gcd(LL a, LL b)
{
	return b ? gcd(b, a % b) : a;
}

void getdiv_()
{
	int i;
	ind = 0;
	for (i = 1; i * i <= N; i++)
	{
		if (N % i == 0)
		{
			div_[ind++] = i;
			if (N / i != i)
			{
				div_[ind++] = N / i;
			}
		}
	}
}

LL lcm(LL a, LL b)
{
	LL gc = gcd(a, b);
	LL lc = (a * b) / gc;
	return lc;
}

void cal()
{
	int i, j, total = 0;
	LL lcm_;
	if (N == 1)
	{
		printf("1\n");
		return;
	}
	for (i = 0; i + 1 < ind; i++)
	{
		for (j = i + 1; j < ind; j++)
		{
			lcm_ = lcm(div_[i], div_[j]);
			if (lcm_ == N)
			{
				total++;
			}
		}
	}
	printf("%d\n", total + 1);
}

int main()
{
	while (scanf("%d", &N) && N)
	{
		getdiv_();
		printf("%d ", N);
		cal();
	}
	return 0;
}
