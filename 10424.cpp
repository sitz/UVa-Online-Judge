#include <bits/stdc++.h>

using namespace std;

double getdigit(char *p)
{
	int i, n = 0, sum;
	for (i = 0; p[i]; i++)
	{
		if (islower(p[i]))
		{
			n += p[i] - 'a' + 1;
		}
		if (isupper(p[i]))
		{
			n += p[i] - 'A' + 1;
		}
	}
	while (1)
	{
		if (n / 10 == 0)
		{
			double tmp = n;
			return tmp;
		}
		sum = 0;
		while (n)
		{
			sum += n % 10;
			n /= 10;
		}
		n = sum;
	}
}

int main()
{
	char p1[50], p2[50];
	double m, n;
	while (cin.getline(p1, 50))
	{
		cin.getline(p2, 50);
		m = getdigit(p1);
		n = getdigit(p2);
		if (m >= n)
		{
			printf("%.2lf %%\n", n * 100 / m);
		}
		else
		{
			printf("%.2lf %%\n", m * 100 / n);
		}
	}
	return 0;
}
