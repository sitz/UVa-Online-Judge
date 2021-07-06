#include <bits/stdc++.h>

using namespace std;

int prime[1000010];
int lcmtable[1000010];
int sublcm[1000010];
int flag[1000010];

void compute_prime_table()
{
	int i, j;
	prime[0] = prime[1] = 0;
	for (i = 2; i <= 1000000; i++)
	{
		prime[i] = 1;
	}
	for (i = 2; i <= 1000;)
	{
		for (j = i + i; j <= 1000000; j += i)
		{
			prime[j] = 0;
		}
		for (i++; !prime[i]; i++)
			;
	}
}

void get_flag_table()
{
	compute_prime_table();
	int pri, t;
	//init flag[]
	for (t = 0; t <= 1000000; t++)
	{
		flag[t] = 0;
	}
	//
	for (pri = 2; pri <= 1000000; pri++)
	{
		if (prime[pri] == 1)
		{
			int num = (int)(6 / log10(pri));
			int i;
			for (i = 1; i <= num; i++)
			{
				int tmp = ceil(pow(pri, i));
				flag[tmp] = pri;
			}
		}
	}
}

void get_lcm_table()
{
	int i;
	for (i = 3, lcmtable[2] = 2, sublcm[2] = 2; i <= 1000000; i++)
	{
		if (flag[i] == 0)
		{
			sublcm[i] = sublcm[i - 1];
			lcmtable[i] = lcmtable[i - 1];
		}
		else if (flag[i] == 5)
		{
			sublcm[i] = sublcm[i - 1] * flag[i];
			sublcm[i] %= 1000;
			while (sublcm[i] % 10 == 0)
			{
				sublcm[i] /= 10;
			}
			lcmtable[i] = sublcm[i] % 10;
		}
		else
		{
			sublcm[i] = sublcm[i - 1] * flag[i];
			sublcm[i] %= 1000;
			lcmtable[i] = sublcm[i] % 10;
		}
	}
}

int main()
{
	get_flag_table();
	get_lcm_table();
	int n;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		if (n == 1)
		{
			cout << 1 << endl;
		}
		else
		{
			cout << lcmtable[n] << endl;
		}
	}
	return 0;
}
