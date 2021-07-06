#include <bits/stdc++.h>

using namespace std;

main()
{
	int te, tc = 1;
	cin >> te;
	while (te--)
	{
		int m[100][100] = {0}, ans[3] = {0};
		for (int l = 0; l < 2; l++)
		{
			int x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			for (int i = y1; i < y2; i++)
				for (int j = x1; j < x2; j++)
				{
					m[i][j]++;
				}
		}
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
			{
				ans[m[i][j]]++;
			}
		cout << "Night " << tc++ << ": " << ans[2] << " " << ans[1] << " " << ans[0] << endl;
	}
}
