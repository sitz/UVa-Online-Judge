#include <bits/stdc++.h>

using namespace std;

int main()
{
	int s, d;
	while (cin >> s >> d)
	{
		int dnum;
		for (dnum = 1; dnum < 6; ++dnum)
		{
			if (s * (5 - dnum) - d * dnum < 0)
			{
				break;
			}
		}
		int sum = 0;
		for (int m = 0; m < 12; ++m)
		{
			if (m % 5 < 5 - dnum)
			{
				sum += s;
			}
			else
			{
				sum -= d;
			}
		}
		if (sum <= 0)
		{
			cout << "Deficit" << endl;
		}
		else
		{
			cout << sum << endl;
		}
	}
	return 0;
}
