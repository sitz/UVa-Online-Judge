#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, m;
	while (cin >> t)
	{
		while (t--)
		{
			cin >> n >> m;
			long long int Ans = 1;
			int item[33] = {0}, num[32][32];
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
				{
					cin >> num[i][j];
					if (num[i][j] == 1)
					{
						item[j]++;
					}
				}
			for (int i = 0; i < n; i++)
				if (item[i])
				{
					Ans *= item[i];
				}
			cout << Ans << endl;
		}
	}
	return 0;
}
