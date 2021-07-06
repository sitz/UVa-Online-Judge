#include <bits/stdc++.h>

using namespace std;

int main()
{
	int cases;
	int n;
	int shops[21];
	cin >> cases;
	while (cases--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> shops[i];
		}
		sort(shops, shops + n);
		cout << (shops[0] + shops[n - 1]) / 2 - shops[0] + shops[n - 1] - shops[0] + shops[n - 1] - (shops[0] + shops[n - 1]) / 2 << endl;
	}
	return 0;
}
