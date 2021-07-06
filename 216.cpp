#include <bits/stdc++.h>

using namespace std;

/**
216
**/
#define MAXN 10
double Dis[MAXN][MAXN];
double Point[MAXN][2];
double MAX, Temp;
int N, Kase;
int A[MAXN];
char F[MAXN];
char Record[MAXN];
char as[] = "**********************************************************";
double DD(int p, int q)
{
	double x, y, z;
	x = pow((Point[p][0] - Point[q][0]), 2);
	y = pow((Point[p][1] - Point[q][1]), 2);
	z = sqrt((x + y));
	return z;
}
void Set_dis()
{
	int i, j;
	double k;
	for (i = 0; i < N - 1; i++)
		for (j = i + 1; j < N; j++)
		{
			k = DD(i, j) + 16.0;
			Dis[i][j] = Dis[j][i] = k;
		}
}
void Recur(int level, int m)
{
	int x;
	if (level >= 2)
	{
		x = A[level - 2];
		Temp += Dis[x][m];
	}
	if (Temp >= MAX)
	{
		return;
	}
	if (level == N)
	{
		if (Temp < MAX)
		{
			MAX = Temp;
			for (x = 0; x < N; x++)
			{
				Record[x] = A[x];
			}
		}
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (F[i] == 0)
		{
			F[i] = 1;
			A[level] = i;
			Recur(level + 1, i);
			F[i] = 0;
			if (level)
			{
				x = A[level - 1];
				Temp -= Dis[x][i];
			}
		}
	}
}
void Cal()
{
	int i, j, k;
	Temp = 0.0;
	Recur(0, 0);
	printf("%s\n", as);
	printf("Network #%d\n", Kase++);
	for (i = 0; i < N - 1; i++)
	{
		j = Record[i];
		k = Record[i + 1];
		printf("Cable requirement to connect (%.lf,%.lf) to (%.lf,%.lf) is %.2lf feet.\n", Point[j][0], Point[j][1], Point[k][0], Point[k][1], Dis[j][k]);
	}
	printf("Number of feet of cable required is %.2lf.\n", MAX);
}
int main()
{
	int i;
	Kase = 1;
	while (scanf("%d", &N) == 1)
	{
		if (!N)
		{
			break;
		}
		MAX = 2147483647;
		for (i = 0; i < N; i++)
		{
			scanf("%lf%lf", &Point[i][0], &Point[i][1]);
		}
		Set_dis();
		Cal();
	}
	return 0;
}
