#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 254020;
int year;
double lg[MAXSIZE];

void init()
{
	for (int n = 1; n < MAXSIZE; n++)
	{
		lg[n] = lg[n - 1] + log(1.0 * n) / log(10.0);
	}
}

int find(double v)
{
	int i = 0;
	while (lg[i] < v)
	{
		i++;
	}
	i--;
	return i;
}

int main()
{
	init();
	while (cin >> year && year)
	{
		int x = (year - 1960) / 10 + 2;
		x = 1 << x;
		cout << find(log(2.0) * x / log(10.0)) << endl;
	}
	return 0;
}
