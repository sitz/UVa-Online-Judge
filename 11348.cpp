#include <bits/stdc++.h>

using namespace std;

int Count[10001];
int Stamps[50][50], own[50], n;
template <typename T>
void Swap(T &a, T &b)
{
	T t = a;
	a = b;
	b = t;
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int cases = 1; cases <= t; cases++)
	{
		memset(Count, 0, sizeof(Count));
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", own + i);
			for (int j = 0; j < own[i]; j++)
			{
				scanf("%d", &Stamps[i][j]);
			}
			for (int j = 0; j < own[i]; j++)
				for (int k = j + 1; k < own[i]; k++)
					if (Stamps[i][j] > Stamps[i][k])
					{
						Swap(Stamps[i][j], Stamps[i][k]);
					}
			int loc = 0, x, y;
			for (x = 0; x < own[i]; x = y)
			{
				for (y = x + 1; y < own[i] && Stamps[i][x] == Stamps[i][y]; y++)
					;
				Stamps[i][loc++] = Stamps[i][x];
			}
			own[i] = loc;
			for (int j = 0; j < own[i]; j++)
			{
				Count[Stamps[i][j]]++;
			}
		}
		printf("Case %d:", cases);
		int total = 0;
		for (int i = 0; i <= 10000; i++)
			if (Count[i] == 1)
			{
				total++;
			}
		for (int i = 0; i < n; i++)
		{
			int owns = 0;
			for (int j = 0; j < own[i]; j++)
				if (Count[Stamps[i][j]] == 1)
				{
					owns++;
				}
			printf(" %.6lf%%", (double)(owns * 100) / (double)(total));
		}
		puts("");
	}
}
