#include <bits/stdc++.h>

using namespace std;

const int MM = 111111;

char ch[MM];
int N, num[MM], sum[MM], ans[22], cnt, d[11111][10], g = 1;

void printcase()
{
	printf("Case %d:", g++);
}

void checkmin(int &x, int y)
{
	if (x == -1 || x > y)
		x = y;
}

void get_data()
{
	int i, j, k;
	scanf("%d", &N);
	sum[N] = -1;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
		sum[N - i - 1] = sum[N - i] + 1;
	}
}

void solve()
{
	int i, j, k;
	printcase();
	if (N < 11)
		puts(" go home!");
	else
	{
		int pos = -1, mx = -1, id = 0;
		cnt = 0;
		while (cnt < 11)
		{
			mx = -1;
			id = pos + 1;
			while (id < N && sum[id] >= (10 - cnt))
			{
				if (mx == -1 || mx < num[id])
				{
					mx = num[id];
					pos = id;
				}
				id++;
			}
			ans[cnt++] = mx;
		}
		for (i = 0; i < cnt; i++)
			printf(" %d", ans[i]);
		printf("\n");
	}
}

int main()
{
	int ca;
	scanf("%d", &ca);
	while (ca--)
	{
		get_data(), solve();
	}
	return 0;
}
