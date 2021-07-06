#include <bits/stdc++.h>

using namespace std;

int n;
int p[1000010];
void compute_prime_table()
{
	int i, j;
	p[0] = p[1] = 0;
	for (i = 2; i <= 1000000; i++)
	{
		p[i] = 1;
	}
	for (i = 2; i <= 1000;)
	{
		for (j = i + i; j <= 1000000; j += i)
		{
			p[j] = 0;
		}
		for (i++; !p[i]; i++)
			;
	}
}
int read_case()
{
	scanf("%d", &n);
	if (n == 0)
	{
		return 0;
	}
	return 1;
}
void solve_case()
{
	int i, j;
	for (i = 3, j = n - 3; i <= j; i++, j--)
		if (p[i] && p[j])
		{
			break;
		}
	printf("%d = %d + %d\n", n, i, j);
}
int main()
{
	compute_prime_table();
	while (read_case())
	{
		solve_case();
	}
	return 0;
}
