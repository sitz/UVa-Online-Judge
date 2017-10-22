#include <bits/stdc++.h>

using namespace std;

/*
The dominoes solitaire
10503
*/
int space, spices, sp;
int sr, sc, tr, tc;
struct ss
{
	int r, c;
	int ind;
} point[30];
char fg[40];
int recur(int r, int c, int index, int level)
{
	int i, x, y;
	if (level == space)
	{
		if (c == tr)
		{
			return 1;
		}
		return 0;
	}
	fg[index] = 1;
	for (i = 0; i < sp; i++)
	{
		if (fg[point[i].ind])
		{
			continue;
		}
		if (c == point[i].r)
			if (recur(point[i].r, point[i].c, point[i].ind, level + 1))
			{
				return 1;
			}
	}
	fg[index] = 0;
	return 0;
}
void Cal()
{
	int x;
	x = recur(sr, sc, 30, 0);
	if (x)
	{
		puts("YES");
	}
	else
	{
		puts("NO");
	}
	for (x = 0; x < 35; x++)
	{
		fg[x] = 0;
	}
}
int main()
{
	int i;
	while (scanf("%d", &space), space)
	{
		scanf("%d", &spices);
		scanf("%d%d", &sr, &sc);
		scanf("%d%d", &tr, &tc);
		sp = spices;
		for (i = 0; i < spices; i++)
		{
			scanf("%d%d", &point[i].r, &point[i].c);
			point[i].ind = i;
			if (point[i].r == point[i].c)
			{
				continue;
			}
			point[sp].r = point[i].c;
			point[sp].c = point[i].r;
			point[sp++].ind = i;
		}
		Cal();
	}
	return 0;
}
