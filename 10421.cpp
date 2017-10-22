#include <bits/stdc++.h>

using namespace std;

#define maxn 1001
#define Cst 32767

struct ss
{
	int x, y;
};
ss Point[maxn];
ss LIS[maxn];
vector<int> V[65700];
int N, Max;

int com(const void *a, const void *b)
{
	ss *p = (ss *)a;
	ss *q = (ss *)b;
	return p->x - q->x;
}
int FindUp(int key, int x)
{
	int max = 0, i, l, ind;
	l = V[key].size();
	for (i = 0; i < l; i++)
	{
		ind = V[key][i];
		if (Point[ind].x >= x)
			break;
		if (LIS[ind].x > max)
			max = LIS[ind].x;
	}
	return max;
}
int FindD(int key, int x)
{
	int max = 0, i, l, ind;
	l = V[key].size();
	for (i = 0; i < l; i++)
	{
		ind = V[key][i];
		if (Point[ind].x >= x)
			break;
		if (LIS[ind].y > max)
			max = LIS[ind].y;
	}
	return max;
}
void Lis()
{
	int i, up, down;
	Max = 1;
	LIS[0].x = LIS[0].y = 1;
	for (i = 1; i < N; i++)
	{
		up = Point[i].y + 2;
		down = Point[i].y - 2;
		LIS[i].y = FindUp(up + Cst, Point[i].x) + 1;
		LIS[i].x = FindD(down + Cst, Point[i].x) + 1;
		if (Max < LIS[i].x)
			Max = LIS[i].x;
		if (Max < LIS[i].y)
			Max = LIS[i].y;
	}
}
void Setting()
{
	int i, d;
	qsort(Point, N, sizeof(ss), com);
	for (i = 0; i < N; i++)
	{
		d = Point[i].y + Cst;
		V[d].push_back(i);
	}
}
void Free()
{
	int i, d;
	for (i = 0; i < N; i++)
	{
		d = Point[i].y + Cst;
		V[d].clear();
	}
}

int main()
{
	int i;
	while (cin >> N)
	{
		for (i = 0; i < N; i++)
			cin >> Point[i].x >> Point[i].y;
		if (N == 0)
		{
			cout << 0 << endl;
			continue;
		}
		Setting();
		Lis();
		cout << Max << endl;
		Free();
	}
	return 0;
}
