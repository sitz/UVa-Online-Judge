#include <bits/stdc++.h>

using namespace std;

int main()
{
	int s, p, y, j;
	while (cin >> s >> p >> y >> j)
	{
		int x = (12 + j - (y + p)) / 3;
		int z = (12 + j) - (3 * x + y + p);
		if (z == 2)
		{
			cout << x + y + 1 << " " << x + p + 1 << " " << x << endl;
		}
		else if (z == 0)
		{
			cout << x + y << " " << x + p << " " << x << endl;
		}
		else
		{
			if (s + p == y)
			{
				cout << x + y + 1 << " " << x + p << " " << x << endl;
			}
			else
			{
				cout << x + y << " " << x + p + 1 << " " << x << endl;
			}
		}
	}
	return 0;
}
