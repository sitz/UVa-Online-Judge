#include <bits/stdc++.h>

using namespace std;

struct Player
{
	int x, y, v;
} p[20];
int no, balls;

int main()
{
	char str[80];
	int i, j;
	gets(str);
	for (i = 0; !isdigit(str[i]); i++)
		;
	no = atoi(str + i);
	for (i = 0; i < no; i++)
	{
		gets(str);
		sscanf(str, "%d %d %d", &p[i].x, &p[i].y, &p[i].v);
	}
	gets(str);
	for (i = 0; !isdigit(str[i]); i++)
		;
	balls = atoi(str + i);
	for (i = 0; i < balls; i++)
	{
		int a, b, c, d, e, f, g;
		int x, y, tt;
		double t;
		gets(str);
		sscanf(str, "%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g);
		double D = sqrt(b * b - 4 * a * c);
		t = (-b - D) / 2 / (double)a;
		if (t < 0)
		{
			t = (-b + D) / 2 / (double)a;
		}
		tt = (int)t;
		if (a * tt * tt + b * tt + c > 0)
		{
			tt++;
		}
		printf("Ball %d was ", i + 1);
		x = d * tt + e;
		y = f * tt + g;
		if (x < 0 || y < 0)
		{
			printf("foul at (%d,%d)\n", x, y);
			continue;
		}
		for (j = 0; j < no; j++)
		{
			int dx = x - p[j].x, dy = y - p[j].y;
			if (dx * dx + dy * dy <= p[j].v * p[j].v * t * t)
			{
				break;
			}
		}
		if (j == no)
		{
			printf("safe at (%d,%d)\n", x, y);
		}
		else
		{
			printf("caught at (%d,%d)\n", x, y);
		}
	}
	return 0;
}
