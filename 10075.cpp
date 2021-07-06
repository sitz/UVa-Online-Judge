#include <bits/stdc++.h>

using namespace std;

#define pi 3.141592653589793
#define R 6378
#define MAX 110
#define INF 2147483647

int N, M, Q, index1, index2;

struct node
{
	double lat, lon;
	char name[100];
};
long long data[MAX][MAX];
node store[MAX];

double distance(double a_lat, double b_lat, double a_long, double b_long)
{
	return R * acos(cos(a_lat) * cos(b_lat) * cos(a_long - b_long) + sin(a_lat) * sin(b_lat));
}

int index(char *name)
{
	int i = 0;
	for (; i < N; i++)
		if (!strcmp(name, store[i].name))
		{
			return i;
		}
	return -1;
}

int main()
{
	char temp[100], temp2[100];
	bool next_line = false;
	int times = 1;
	while (scanf("%d %d %d", &N, &M, &Q))
	{
		if (N == 0 && M == 0 && Q == 0)
		{
			return 0;
		}
		if (next_line)
		{
			printf("\n");
		}
		next_line = true;
		printf("Case #%d\n", times++);
		//initial
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				data[i][j] = INF;
			}
			data[i][i] = 0;
		}
		//
		for (int i = 0; i < N; i++)
		{
			scanf("%99s %lf %lf", store[i].name, &store[i].lat, &store[i].lon);
			store[i].lat = store[i].lat * pi / 180.0;
			store[i].lon = store[i].lon * pi / 180.0;
		}
		for (int k = 0; k < M; k++)
		{
			scanf("%99s %99s", temp, temp2);
			index1 = index(temp);
			index2 = index(temp2);
			if (index1 == index2)
			{
				data[index1][index2] = 0;
			}
			else
			{
				data[index1][index2] = (long long)(distance(store[index1].lat, store[index2].lat, store[index1].lon, store[index2].lon) + 0.5);
			}
		}
		//APSP
		for (int k = 0; k < N; k++)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (data[i][k] + data[k][j] < data[i][j])
					{
						data[i][j] = data[i][k] + data[k][j];
					}
				}
			}
		}
		for (int i = 0; i < Q; i++)
		{
			scanf("%99s %99s", temp, temp2);
			index1 = index(temp);
			index2 = index(temp2);
			if (data[index1][index2] != INF)
			{
				printf("%lld km\n", data[index1][index2]);
			}
			else
			{
				printf("no route exists\n");
			}
		}
	}
	return 0;
}
