#include <bits/stdc++.h>

using namespace std;

/* Prob 718 : Skyscraper Floors
STEP1 判斷兩電梯是否可連通
STEP2 找到開始樓層和目逼樓層的電梯
STEP3 將 w 丟給 Floyd-Warshall's Algorithm 去計算 -> 得到 Transitive Closure A*
STEP4 判斷開始樓層和目標樓層是否有電梯相通
PS.注意STEP1中，不得超過此測試資料的樓層數 F
*/
struct ELEVATOR
{
	long start;
	long step;
};
int MIN(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	return b;
}
ELEVATOR elevt[101];
int F, E, A, B;
int start, goal;
void find();
void Floyd();
int Connect(int, int);
int w[101][101];
int color[101][101];
int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d %d %d %d", &F, &E, &A, &B);
		for (int i = 1; i <= E; i++)
		{
			scanf("%ld %ld", &elevt[i].step, &elevt[i].start);
		}
		//initialization
		for (int i = 1; i <= E; i++)
			for (int j = 1; j <= E; j++)
			{
				w[i][j] = 0;
			}
		//connecting...
		for (int i = 1; i <= E; i++)
			for (int j = 1; j <= E; j++)
				if (Connect(i, j) == 1)
				{
					w[i][j] = 1;
					w[j][i] = 1;
				}
		// finding start to end
		find();
		Floyd();
		if (start != -1 && goal != -1)
		{
			if (w[start][goal] == 1 && w[goal][start] == 1)
			{
				printf("It is possible to move the furniture.\n");
			}
			else
			{
				printf("The furniture cannot be moved.\n");
			}
		}
		else
		{
			printf("The furniture cannot be moved.\n");
		}
	}
	return 0;
}
int Connect(int elev1, int elev2)
{
	int r1, r2, m, n;
	m = elevt[elev1].step;
	n = elevt[elev2].step;
	r1 = elevt[elev1].start;//r1
	r2 = elevt[elev2].start;//r2
	int flg = 0;						// flg = 1 -> connected
	for (int q = 0; q <= m; ++q)
	{
		if ((n * q + r2) % m == r1 && (n * q + r2 <= F))
		{
			flg = 1;
			break;
		}
	}
	if (flg == 1)
	{
		return 1;
	}
	return 0;
}
void find()
{
	start = -1;
	goal = -1;
	// find starting elevator
	for (int i = 1; i <= E; i++)
	{
		if (A - elevt[i].start == 0)
		{
			start = i;
		}
		else if (A - elevt[i].start > elevt[i].step)
			if ((A - elevt[i].start) % elevt[i].step == 0)
			{
				start = i;
				break;
			}
	}
	// find aim elevator
	for (int i = 1; i <= E; ++i)
	{
		if (B - elevt[i].start == 0)
		{
			goal = i;
		}
		else if (B - elevt[i].start > elevt[i].step)
			if ((B - elevt[i].start) % elevt[i].step == 0)
			{
				goal = i;
				break;
			}
	}
}
void Floyd()
{
	for (int k = 1; k <= E; k++)
		for (int i = 1; i <= E; i++)
			for (int j = 1; j <= E; j++)
				if (w[i][k] && w[k][j])
				{
					w[i][j] = 1;
				}
}
