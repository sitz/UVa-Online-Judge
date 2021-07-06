#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, a, b, x, i, j, count = 1, flag, aa, bb, temp;
	int map[502][502], hash[502], now;
	double dis[502];
	double length, mmax, mmin, max;
	while (scanf("%d %d", &n, &m) && n)//如果写成&&n&&m 那么1 0 这组数据过不去咧。。
	{
		memset(hash, 0, sizeof(hash));
		for (i = 1; i <= n; i++)//初始化邻接矩阵，对角线上距离都为0
		{
			for (j = 1; j <= n; j++)
			{
				map[i][j] = INT_MAX;
			}
			map[i][i] = 0;
			dis[i] = INT_MAX;
		}
		for (i = 1; i <= m; i++)//输入邻接矩阵，map[a][b] == map[b][a]
		{
			scanf("%d %d %d", &a, &b, &x);
			map[a][b] = x;
			map[b][a] = x;
		}
		now = 1;
		dis[now] = 0;
		hash[1] = 1;
		for (i = 1; i <= n; i++)//Dijkstra 算法
		{
			max = INT_MAX;
			for (j = 1; j <= n; j++)
				if (dis[j] - dis[now] - map[now][j] > 0.000001 && map[now][j] != INT_MAX)
				{
					dis[j] = dis[now] + map[now][j];
				}
			for (j = 1; j <= n; j++)
				if (!hash[j] && max - dis[j] > 0.000001)
				{
					max = dis[j];
					now = j;
				}
			hash[now] = 1;
		}
		mmax = 0;
		temp = 1;
		for (i = 1; i <= n; i++)//找最短路径的最大值
			if (dis[i] > mmax)
			{
				mmax = dis[i];
				temp = i;
			}
		mmin = 0;
		flag = 1;
		for (i = 1; i <= n; i++)//寻找从1出发的两条最短路径到达的点以及这两点之间的距离的和的最大值
			for (j = 1; j <= n; j++)
			{
				if (!fabs(dis[i] - map[i][j] - dis[j]) < 0.0000001)
					if (dis[i] + map[i][j] - mmax > 0.0000001 && map[i][j] != INT_MAX)
					{
						flag = 0;//标记是否在key点停止还是在边上停止
						if (dis[i] + map[i][j] + dis[j] > mmin)
						{
							mmin = dis[i] + map[i][j] + dis[j];
							aa = i;
							bb = j;
						}
					}
			}
		if (flag == 0 && (dis[aa] + dis[bb] + map[aa][bb]) / 2 < mmax)
		//如果找到最长距离的时间比最短路径的时间小，则最终在key点停止
		{
			flag = 1;
		}
		printf("System #%d\n", count++);
		if (flag)
		{
			printf("The last domino falls after %.1lf seconds, at key domino %d.\n", mmax, temp);
		}
		else
		{
			length = (dis[aa] + dis[bb] + map[aa][bb]) / 2;
			printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n", length, aa < bb ? aa : bb, aa > bb ? aa : bb);
		}//这个输出我是按从小点到大点输出的，不按这个顺序也可以。
		printf("\n");
	}
	return 0;
}
