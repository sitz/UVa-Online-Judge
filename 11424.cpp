#include <bits/stdc++.h>

using namespace std;

int phi[1000100];
long long a[1000100];
void phi_table(int n)
{
	for (int i = 2; i <= n; i++)
	{
		phi[i] = 0;
	}
	phi[1] = 1;
	for (int i = 2; i <= n; i++)
		if (!phi[i])
			for (int j = i; j <= n; j += i)
			{
				if (!phi[j])
				{
					phi[j] = j;
				}
				phi[j] = phi[j] / i * (i - 1);
			}
}
void gcd_sum(int n)
{
	for (int i = 2; i < n; i++)
	{
		a[i] = phi[i];
	}
	double k = sqrt(0.5 + n);
	for (int i = 2; i <= k; i++)
	{
		for (int j = i, bit = 1; j < n; j += i, bit++)
		{
			if (i < bit)
			{
				a[j] += phi[bit] * i + phi[i] * bit;
			}
			else if (i == bit)
			{
				a[j] += phi[i] * i;
			}
		}
	}
}
void gcd_sum_again(int n)
{
	for (int i = 1; i < n; i++)
	{
		a[i] += a[i - 1];
	}
}
int main()
{
	phi_table(1000100);
	gcd_sum(1000100);
	gcd_sum_again(1000100);
	int n;
	while (cin >> n && n)
	{
		cout << a[n] << endl;
	}
	return 0;
}
