#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	char p[20][30];
	int cnt[20], sum, min;
	while (cin >> N)
	{
		if (N == 0)
		{
			break;
		}
		int i, j;
		for (i = 0; i <= N; i++)
		{
			cin.getline(p[i], 30);
		}
		for (i = 0; i <= N; i++)
		{
			cnt[i] = 0;
		}
		sum = 0;
		min = 10000;
		for (i = 1; i <= N; i++)
			for (j = 0; j < 25; j++)
				if (p[i][j] == ' ')
				{
					cnt[i]++;
				}
		for (i = 1; i <= N; i++)
			if (cnt[i] < min)
			{
				min = cnt[i];
			}
		for (i = 1; i <= N; i++)
		{
			sum += cnt[i];
		}
		cout << sum - N * min << endl;
	}
	return 0;
}
