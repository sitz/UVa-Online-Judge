#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long fac[20];
	int i, n;
	fac[0] = 1;
	for (i = 1; i <= 13; i++)
	{
		fac[i] = fac[i - 1] * i;
	}
	while (cin >> n)
	{
		if (n >= 0)
		{
			if (n > 13)
			{
				cout << "Overflow!" << endl;
			}
			else if (n < 8)
			{
				cout << "Underflow!" << endl;
			}
			else
			{
				cout << fac[n] << endl;
			}
		}
		else
		{
			if ((n * -1) % 2 == 1)
			{
				cout << "Overflow!" << endl;
			}
			else
			{
				cout << "Underflow!" << endl;
			}
		}
	}
	return 0;
}
