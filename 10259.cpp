#include <bits/stdc++.h>

using namespace std;

#define MAXN 103
#define MAX(a, b) (a > b ? a : b)

int N, B[MAXN][MAXN], maximum, K, large, Or[MAXN][MAXN];

void BFS()
{
	int i, nx, ny, pos, j, k;
	B[1][1] = Or[1][1];
	maximum = B[1][1];
	for (k = B[1][1]; k <= 100; k++)
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				if (Or[i][j] != k)
					continue;
				for (pos = -K; pos <= K; pos++)
				{
					ny = j + pos;
					if (ny > 0 && ny <= N && Or[i][j] < Or[i][ny])
					{
						B[i][ny] = MAX(B[i][ny], B[i][j] + Or[i][ny]);
						maximum = MAX(B[i][ny], maximum);
					}
					nx = i + pos;
					if (nx < 1 || nx > N)
						continue;
					if (Or[i][j] < Or[nx][j])
					{
						B[nx][j] = MAX(B[nx][j], B[i][j] + Or[nx][j]);
						maximum = MAX(B[nx][j], maximum);
					}
				}
			}
		}
	}
}

int main()
{
	int ks, i, j;
	cin >> ks;
	while (ks--)
	{
		cin >> N >> K;
		large = -1;
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				cin >> Or[i][j];
				large = MAX(large, Or[i][j]);
				B[i][j] = -1000000;
			}
		}
		BFS();
		cout << maximum << endl;
		if (ks)
		{
			cout << "\n";
		}
	}
	return 0;
}
