#include <bits/stdc++.h>

using namespace std;

const int INF = 1<<30;

int a[10010], b[10010], d[2][10010][2];

// @ http://blog.csdn.net/dilemma729/article/details/43977237
// d[i][j][0] = min{d[i+1][j][0]+a[i+1]-a[i], d[i+1][j][1]+a[i+j]-a[i]}
// d[i][j][1] = min{d[i][j-1][0]+a[i+j]-a[i], d[i][j-1][1]+a[i+j]-a[i+j-1]}

int main()
{
	int i, j, n, curr, min_;
	while (scanf("%d", &n) == 1)
	{
		for (i = 1; i <= n; i++)
		{
			scanf("%d%d", &a[i], &b[i]);
		}
		curr = 0;
		for (j = 1; j <= n; j++)
		{
			d[0][j][0] = d[0][j][1] = (b[j] > 0) ? 0 : INF;
		}
		for (i = 1; i < n; i++)
		{
			curr ^= 1;
			for (j = 1; j <= n - i; j++)
			{
				d[curr][j][0] = d[curr ^ 1][j + 1][0] + a[j + 1] - a[j] > d[curr ^ 1][j + 1][1] + a[j + i] - a[j] ? d[curr ^ 1][j + 1][1] + a[j + i] - a[j] : d[curr ^ 1][j + 1][0] + a[j + 1] - a[j];
				d[curr][j][1] = d[curr ^ 1][j][0] + a[j + i] - a[j] > d[curr ^ 1][j][1] + a[j + i] - a[j + i - 1] ? d[curr ^ 1][j][1] + a[j + i] - a[j + i - 1] : d[curr ^ 1][j][0] + a[j + i] - a[j];
				d[curr][j][0] = d[curr][j][0] < b[j] ? d[curr][j][0] : INF;
				d[curr][j][1] = d[curr][j][1] < b[j + i] ? d[curr][j][1] : INF;
			}
		}
		min_ = d[curr][1][0] > d[curr][1][1] ? d[curr][1][1] : d[curr][1][0];
		if (min_ == INF)
		{
			printf("No solution\n");
		}
		else
		{
			printf("%d\n", min_);
		}
	}
	return 0;
}
