#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

#define nmax 41

i64 n, k, c;
i64 a[nmax], b[nmax];
int f;

void out(int i, int zf)
{
	if (f)
	{
		f = 0;
	}
	else
	{
		if (zf == 1)
		{
			cout << "+";
		}
		else
		{
			cout << "-";
		}
	}
	cout << b[i];
}
void done(i64 c)
{
	int i;
	while (c)
	{
		if (c > 0)
		{
			for (i = 0; i < nmax; ++i)
			{
				if ((a[i] > 0 && a[i] >= c))//|| (a[i]>0 && a[i]<=c)) {
				{
					c -= b[i];
					out(i, 1);
					break;
				}
			}
		}
		else
		{
			c = -c;
			for (i = 0; i < nmax; ++i)
			{
				if ((a[i] > 0 && a[i] >= c))//|| (a[i]>0 && a[i]<=c)) {
				{
					c -= b[i];
					out(i, -1);
					break;
				}
			}
			c = -c;
		}
	}
	cout << endl;
}
/*
12157665459056928801  3^40
9223372036854775808   2^63
36472996377170786403  3^41
*/
int main()
{
	int i;
	a[0] = b[0] = 1;
	for (i = 1; i < nmax; ++i)
		b[i] = b[i - 1] * 3,
		a[i] = a[i - 1] + b[i];
	while (cin >> n >> k && n && k)
	{
		for (i = 0; i < nmax; ++i)
		{
			if (a[i] >= n)
			{
				cout << i + 1;
				for (int j = 0; j <= i; ++j)
				{
					cout << " " << b[j];
				}
				cout << endl;
				break;
			}
		}
		for (i = 0; i < k; ++i)
		{
			cin >> c;
			f = 1;
			done(c);
		}
	}
	return 0;
}
