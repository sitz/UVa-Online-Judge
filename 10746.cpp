#include <bits/stdc++.h>

using namespace std;

#define maxn 20
#define oo 1000000000

double c[maxn][maxn], fx[maxn], fy[maxn];
int mx[maxn], my[maxn], trace[maxn];
int n, m, k, start, finish;

void input()
{
	k = m;// as it is given n <= m otherwise, k = max(n, m)
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
			c[i][j] = oo;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> c[i][j];
}

void init()
{
	memset(mx, 0xFF, sizeof(mx));
	memset(my, 0xFF, sizeof(my));
	memset(fx, 0, sizeof(fx));
	memset(fy, 0, sizeof(fy));
}

int getC(int i, int j)
{
	return c[i][j] - fx[i] - fy[j];
}

void findAugmentingPath()
{
	memset(trace, 0xFF, sizeof(trace));
	queue<int> q;
	q.push(start);
	while (!q.empty())
	{
		int i = q.front();
		q.pop();
		for (int j = 0; j < k; j++)
			if (trace[j] == -1 && getC(i, j) == 0)
			{
				trace[j] = i;
				if (my[j] == -1)
				{
					finish = j;
					return;
				}
				q.push(my[j]);
			}
	}
}

void subX_AddY()
{
	bool visitedX[maxn], visitedY[maxn];
	memset(visitedX, false, sizeof(visitedX));
	memset(visitedY, false, sizeof(visitedY));
	visitedX[start] = true;
	for (int j = 0; j < k; j++)
		if (trace[j] != -1)
		{
			visitedX[my[j]] = true;
			visitedY[j] = true;
		}
	// Tính Delta := min(GetC(i, j)|i ∈ VisitedX và j ∉ VisitedY)
	int delta = oo;
	for (int i = 0; i < k; i++)
		if (visitedX[i])
			for (int j = 0; j < k; j++)
				if ((!visitedY[j]) && (delta > getC(i, j)))
				{
					delta = getC(i, j);
				}
	for (int t = 0; t < k; t++)
	{
		if (visitedX[t])
			fx[t] += delta;
		if (visitedY[t])
			fy[t] -= delta;
	}
}

void enlarge()
{
	do
	{
		int i = trace[finish];
		int next = mx[i];
		mx[i] = finish;
		my[finish] = i;
		finish = next;
	} while (finish != -1);
}

void process()
{
	init();
	for (int i = 0; i < k; i++)
	{
		start = i;
		finish = -1;
		do
		{
			findAugmentingPath();
			if (finish == -1)
				subX_AddY();
		} while (finish == -1);
		enlarge();
	}
}

void output()
{
	double result = 0;
	for (int i = 0; i < n; i++)
	{
		int j = mx[i];
		if (c[i][j] < oo)
			result += c[i][j];
	}
	printf("%.2f\n", result / n);
}

int main()
{
	while (cin >> n >> m)
	{
		if ((n == 0) && (m == 0))
		{
			break;
		}
		input();
		process();
		output();
	}
	return 0;
}
