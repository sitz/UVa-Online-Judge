#include <bits/stdc++.h>

using namespace std;

const int MAXRINGS = 101;
const int oo = 0x7fffffff;
const double delta = 0.0000001;

int numOfRings, maxRings;
bool visited[MAXRINGS];

struct Rings
{
	double x, y;
	double radius;
} rings[MAXRINGS];

void Input()
{
	int i;
	for (i = 0; i < numOfRings; i++)
	{
		scanf("%lf%lf%lf", &rings[i].x, &rings[i].y, &rings[i].radius);
	}
}

double distance(Rings a, Rings b)
{
	double xx = a.x - b.x;
	double yy = a.y - b.y;
	return sqrt(xx * xx + yy * yy);
}

bool isGlued(Rings a, Rings b)
{
	double d = distance(a, b);
	if (d <= fabs(a.radius + b.radius) + delta && d >= fabs(a.radius - b.radius) + delta)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void dfs(int index, int &count)
{
	count++;
	if (count > maxRings)
	{
		maxRings = count;
	}
	visited[index] = true;
	for (int w = 0; w < numOfRings; w++)
	{
		if (!visited[w] && isGlued(rings[w], rings[index]))
		{
			dfs(w, count);
		}
	}
}

void Solve()
{
	maxRings = 0;
	int root, cnt;
	for (root = 0; root < numOfRings; root++)
	{
		cnt = 0;
		memset(visited, 0, sizeof(visited));
		dfs(root, cnt);
	}
}

int main()
{
	while (scanf("%d", &numOfRings) == 1 && numOfRings >= 0)
	{
		Input();
		Solve();
		if (maxRings != 1)
		{
			printf("The largest component contains %d rings.\n", maxRings);
		}
		else
		{
			printf("The largest component contains %d ring.\n", maxRings);
		}
	}
	return 0;
}
