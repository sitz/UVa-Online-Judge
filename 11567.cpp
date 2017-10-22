#include <bits/stdc++.h>

using namespace std;

long long S;
int p[6] = {0, 1, 2, 3, 3, 4};

void solve()
{
	int step = 0;
	while (S)
	{
		if (S < 6)
		{
			step += p[S];
			break;
		}
		if (S % 2 == 0)
		{
			S /= 2;
		}
		else
		{
			int dec = (S - 1) / 2;
			if (dec % 2)
			{
				S++;
			}
			else
			{
				S--;
			}
		}
		step++;
	}
	cout << step << endl;
}

int main()
{
	while (cin >> S)
	{
		solve();
	}
	return 0;
}
