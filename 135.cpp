#include <bits/stdc++.h>

using namespace std;

int k, rows[33][33];

inline int mv_row(int r, int idx)
{
	return rows[r][idx % (k - 1)];
}

int main()
{
	bool fst = true;
	while (cin >> k)
	{
		if (fst)
		{
			fst = false;
		}
		else
		{
			printf("\n");
		}
		int c = 0;
		for (int i = 0; i < k - 1; ++i)
		{
			cout << ++c << ' ';
		}
		cout << ++c << endl;
		for (int i = 0; i < k - 1; ++i)
			for (int j = 0; j < k - 1; ++j)
			{
				rows[i + 1][j] = ++c;
			}
		for (int i = 0; i < k - 1; ++i)
		{
			cout << 1 << ' ';
			for (int j = 0; j < k - 2; ++j)
			{
				cout << rows[i + 1][j] << ' ';
			}
			cout << rows[i + 1][k - 2] << endl;
		}
		for (int i = 0; i < k - 1; ++i)
		{
			for (int r = 0; r < k - 1; ++r)
			{
				cout << i + 2 << ' ';
				for (int v = 1; v < k - 1; ++v)
				{
					cout << mv_row(v, r + i * (v - 1)) << ' ';
				}
				cout << mv_row(k - 1, r + i * (k - 2)) << endl;
			}
		}
	}
	return 0;
}
