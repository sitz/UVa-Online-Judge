#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, h[100], cases = 1;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		cout << "Set #" << cases++ << endl;
		int i, total = 0, average, min = 0;
		for (i = 0; i < n; i++)
		{
			cin >> h[i];
			total += h[i];
		}
		average = total / n;
		for (i = 0; i < n; i++)
		{
			if (h[i] > average)
			{
				min += h[i] - average;
			}
		}
		cout << "The minimum number of moves is " << min << "." << endl;
		cout << endl;
	}
	return 0;
}
