#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, w, y1, y2, t;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> w;
		bool c = 1;
		cin >> y1 >> y2;
		t = y2 - y1;
		for (int j = 2; j <= w; j++)
		{
			cin >> y1 >> y2;
			if (t != y2 - y1)
			{
				c = 0;
			}
		}
		if (c == 1)
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}
		if (i != n)
		{
			cout << '\n';
		}
	}
	return 0;
}
