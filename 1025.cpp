#include <bits/stdc++.h>

using namespace std;

#define mem(name, value) memset(name, value, sizeof(name))
#define FOR(i, n) for (int i = 1; i <= n; i++)

const int MAXN = 60;
const int MAXM = 200 + 10;
const int INF = 0x3f3f3f3f;

int d[MAXN][MAXM], has_train[MAXN][MAXM][2], time_[MAXN], N, T, M1, M2;

void init()
{
	mem(d, 0);
	mem(has_train, 0);
	scanf("%d", &T);
	FOR(i, N - 1)
	scanf("%d", time_ + i);
	scanf("%d", &M1);
	int a;
	for (int i = 0; i < M1; i++)
	{
		scanf("%d", &a);
		has_train[1][a][0] = 1;
		for (int j = 1; j < N; j++)
		{
			a += time_[j];
			has_train[j + 1][a][0] = 1;
		}
	}
	scanf("%d", &M2);
	for (int i = 0; i < M2; i++)
	{
		scanf("%d", &a);
		has_train[N][a][1] = 1;
		for (int j = N; j > 1; j--)
		{
			a += time_[j - 1];
			has_train[j - 1][a][1] = 1;
		}
	}
	FOR(i, N - 1)
	d[i][T] = INF;
}

int main()
{
	int kase = 0;
	while (~scanf("%d", &N) && N)
	{
		init();
		for (int i = T - 1; i >= 0; i--)
		{
			for (int j = 1; j <= N; j++)
			{
				d[j][i] = d[j][i + 1] + 1;
				if (j + 1 <= N && i + time_[j] <= T && has_train[j][i][0])
				{
					d[j][i] = min(d[j][i], d[j + 1][i + time_[j]]);
				}
				if (j - 1 >= 1 && i + time_[j - 1] <= T && has_train[j][i][1])
				{
					d[j][i] = min(d[j][i], d[j - 1][i + time_[j - 1]]);
				}
			}
		}
		printf("Case Number %d: ", ++kase);
		if (d[1][0] >= INF)
		{
			printf("impossible\n");
		}
		else
		{
			printf("%d\n", d[1][0]);
		}
	}
	return 0;
}
