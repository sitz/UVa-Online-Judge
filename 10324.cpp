#include <bits/stdc++.h>

using namespace std;

int main()
{
	char buf[1000001];
	int table[1000001];
	int i, j, n, t, kase = 1;
	while (cin >> buf)
	{
		cout << "Case " << kase++ << ":" << endl;
		memset(table, 0, sizeof(table));
		for (i = 1; buf[i]; i++)
		{
			if (buf[i] == buf[i - 1])
			{
				table[i] = table[i - 1];
			}
			else
			{
				table[i] = table[i - 1] + 1;
			}
		}
		cin >> n;
		for (t = 0; t < n; t++)
		{
			cin >> i >> j;
			if (table[i] == table[j])
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
		}
	}
	return 0;
}
