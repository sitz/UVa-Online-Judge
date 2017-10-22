#include <bits/stdc++.h>

using namespace std;

class BigInt
{
public:
	void ComputeSum();
	int p[3000];
	int len, sum;
} test[1010];

void BigInt::ComputeSum()
{
	sum = 0;
	int i;
	for (i = 0; i < len; i++)
	{
		sum += p[i];
	}
}

void Compute(BigInt *f, int x)
{
	int i, k, g = 0;
	for (i = 0; i < f[x - 1].len; i++)
	{
		k = f[x - 1].p[i] * x + g;
		f[x].p[i] = k % 10;
		g = k / 10;
	}
	if (g > 0)
		while (g)
		{
			f[x].p[i] = g % 10;
			g /= 10;
			i++;
		}
	f[x].len = i;
}

int main()
{
	test[0].p[0] = 1;
	test[0].len = 1;
	test[0].ComputeSum();
	int i, n;
	for (i = 1; i <= 1002; i++)
	{
		Compute(test, i);
		test[i].ComputeSum();
	}
	while (cin >> n)
	{
		cout << test[n].sum << endl;
	}
	return 0;
}
