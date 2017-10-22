#include <bits/stdc++.h>

using namespace std;

struct Point
{
	int x, y;
};
double get_dis(Point a, Point b)
{
	return sqrt((1.0 * a.x - b.x) * (1.0 * a.x - b.x) + (1.0 * a.y - b.y) * (1.0 * a.y - b.y));
}
int N, Left[110];
bool S[110], T[110];
double W[110][110], LX[110], LY[110];
Point PX[110], PY[110];
bool match(int i)
{
	S[i] = true;
	for (int j = 1; j <= N; j++)
		if (fabs(LX[i] + LY[j] - W[i][j]) < 1e-7 && !T[j])
		{
			T[j] = true;
			if (Left[j] == 0 || match(Left[j]))
			{
				Left[j] = i;
				return true;
			}
		}
	return false;
}
void update()
{
	double a = 1 << 30;
	for (int i = 1; i <= N; i++)
		if (S[i])
		{
			for (int j = 1; j <= N; j++)
				if (!T[j])
				{
					a = min(a, LX[i] + LY[j] - W[i][j]);
				}
		}
	for (int i = 1; i <= N; i++)
	{
		if (S[i])
		{
			LX[i] -= a;
		}
		if (T[i])
		{
			LY[i] += a;
		}
	}
}
void KM()
{
	for (int i = 1; i <= N; i++)
	{
		Left[i] = LX[i] = LY[i] = 0;
		for (int j = 1; j <= N; j++)
		{
			if (j == 1)
			{
				LX[i] = W[i][j];
			}
			LX[i] = max(LX[i], W[i][j]);
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (;;)
		{
			for (int j = 1; j <= N; j++)
			{
				S[j] = T[j] = 0;
			}
			if (match(i) == true)
			{
				break;
			}
			else
			{
				update();
			}
		}
	}
}
int main()
{
	while (scanf("%d", &N) != EOF)
	{
		for (int i = 1; i <= N; i++)
		{
			scanf("%d%d", &PX[i].x, &PX[i].y);
		}
		for (int i = 1; i <= N; i++)
		{
			scanf("%d%d", &PY[i].x, &PY[i].y);
		}
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
				W[i][j] = -1.0 * get_dis(PX[i], PY[j]);
			}
		KM();
		int Right[110];
		for (int i = 1; i <= N; i++)
		{
			Right[Left[i]] = i;
		}
		for (int i = 1; i <= N; i++)
		{
			printf("%d\n", Right[i]);
		}
	}
	return 0;
}
