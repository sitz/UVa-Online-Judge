#include <bits/stdc++.h>

using namespace std;

const long maxnum = 2000000001;

int p[1000010];
int prime[100000];

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

void get_prime()
{
	int i, j;
	compute_prime_table();
	for (i = 0, j = 0; i < 50000; i++)
	{
		if (p[i] != 0)
		{
			prime[j] = i;
			j++;
		}
	}
}

bool judge_prime(int x)
{
	int i;
	for (i = 2; i <= sqrt(x); i++)
		if (x % i == 0)
		{
			return false;
		}
	return true;
}

void process(int n)
{
	int i = 0, num = 0, j;
	int array[1000];
	while (n)
	{
		if (n < prime[i])
		{
			break;
		}
		if (n % prime[i] == 0)
		{
			array[num++] = prime[i];
			n /= prime[i];
		}
		else
		{
			i++;
		}
	}
	for (j = 0; j < num - 1; j++)
	{
		cout << array[j] << " x ";
	}
	cout << array[j] << endl;
}

int main()
{
	get_prime();
	int n;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		if (n < 0)
		{
			cout << n << " = -1 x ";
			n *= -1;
			if (judge_prime(n) == true)
			{
				cout << n << endl;
			}
			else
			{
				process(n);
			}
		}
		else
		{
			cout << n << " = ";
			if (judge_prime(n) == true)
			{
				cout << n << endl;
			}
			else
			{
				process(n);
			}
		}
	}
	return 0;
}
