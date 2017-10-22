#include <bits/stdc++.h>

using namespace std;

struct point
{
	long x, y;
};
struct rect
{
	point lefttop, rightbottom;
	void normalize()
	{
		long minx = min(lefttop.x, rightbottom.x), maxx = max(lefttop.x, rightbottom.x);
		long miny = min(lefttop.y, rightbottom.y), maxy = max(lefttop.y, rightbottom.y);
		lefttop.x = minx;
		lefttop.y = miny;
		rightbottom.x = maxx;
		rightbottom.y = maxy;
	}
	static bool overlap(rect a, rect b)
	{
		return a.lefttop.x <= b.rightbottom.x && b.lefttop.x <= a.rightbottom.x &&
					 a.lefttop.y <= b.rightbottom.y && b.lefttop.y <= a.rightbottom.y;
	}
};

#define MAXMONSTERS 100
#define MAXVERTICES (4 * (MAXMONSTERS) + 2)
#define MINX -1000000000
#define MAXX 1000000000
#define MINY -1000000000
#define MAXY 1000000000
#define ULLMAX ((unsigned long long)(-1LL))

rect monsters[MAXMONSTERS];
point vertices[MAXVERTICES];
unsigned long long dist[MAXVERTICES][MAXVERTICES];
bool opened[MAXVERTICES];
unsigned long long fromsource[MAXVERTICES];

void gen()
{
	printf("100\n");
	for (int i = 0; i < 100; i++)
	{
		printf("-1000000000 -1000000000 1000000000 1000000000\n");
		printf("0 100 0\n");
		for (int j = 0; j < 100; j++)
			if (j & 1)
			{
				printf("%d -999999999 %d 1000000000\n", 2 * j, 2 * j);
			}
			else
			{
				printf("%d -1000000000 %d 999999999\n", 2 * j, 2 * j);
			}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		long sourceX, sourceY, destinationX, destinationY;
		scanf("%ld %ld %ld %ld", &sourceX, &sourceY, &destinationX, &destinationY);
		vertices[0].x = sourceX;
		vertices[0].y = sourceY;
		vertices[1].x = destinationX;
		vertices[1].y = destinationY;
		int nv = 2;
		int M, N, Q;
		scanf("%d %d %d", &M, &N, &Q);
		for (int i = 0; i < M; i++)
		{
			long u, v;
			scanf("%ld %ld", &u, &v);
			monsters[i].lefttop.x = u;
			monsters[i].lefttop.y = v;
			monsters[i].rightbottom.x = u;
			monsters[i].rightbottom.y = v;
		}
		for (int i = 0; i < N + Q; i++)
		{
			long u1, v1, u2, v2;
			scanf("%ld %ld %ld %ld", &u1, &v1, &u2, &v2);
			monsters[i + M].lefttop.x = u1;
			monsters[i + M].lefttop.y = v1;
			monsters[i + M].rightbottom.x = u2;
			monsters[i + M].rightbottom.y = v2;
		}
		int nm = N + M + Q;
		for (int i = 0; i < nm; i++)
		{
			monsters[i].normalize();
			point corners[] =
					{
							{monsters[i].lefttop.x - 1, monsters[i].lefttop.y - 1},
							{monsters[i].rightbottom.x + 1, monsters[i].lefttop.y - 1},
							{monsters[i].rightbottom.x + 1, monsters[i].rightbottom.y + 1},
							{monsters[i].lefttop.x - 1, monsters[i].rightbottom.y + 1}};
			for (int j = 0; j < 4; j++)
				if (corners[j].x >= MINX && corners[j].x <= MAXX && corners[j].y >= MINY && corners[j].y <= MAXY)
				{
					vertices[nv].x = corners[j].x;
					vertices[nv].y = corners[j].y;
					nv++;
				}
		}
		for (int i = 0; i < nv - 1; i++)
			for (int j = i + 1; j < nv; j++)
			{
				rect a = {vertices[i].x, vertices[i].y, vertices[j].x, vertices[j].y};
				a.normalize();
				bool freeway = true;
				for (int k = 0; k < nm && freeway; k++)
					if (rect::overlap(a, monsters[k]))
					{
						freeway = false;
					}
				dist[i][j] = dist[j][i] = !freeway ? ULLMAX : (unsigned long long)abs(vertices[i].x - vertices[j].x) + (unsigned long long)abs(vertices[i].y - vertices[j].y);
			}
		memset(opened, 0, sizeof(opened));
		fromsource[0] = 0;
		for (int i = 1; i < nv; i++)
		{
			fromsource[i] = ULLMAX;
		}
		int toopen = 0;
		while (toopen != 1 /*dest*/ && toopen != -1 /*all accessible opened*/)
		{
			opened[toopen] = true;
			for (int i = 0; i < nv; i++)
				if (dist[toopen][i] != ULLMAX && !opened[i])
				{
					fromsource[i] = min(fromsource[i], fromsource[toopen] + dist[toopen][i]);
				}
			toopen = -1;
			unsigned long long nearest = ULLMAX;
			for (int i = 0; i < nv; i++)
				if (!opened[i] && fromsource[i] < nearest)
				{
					nearest = fromsource[i];
					toopen = i;
				}
		}
		if (fromsource[1] != ULLMAX)
		{
			printf("Case %d: %llu\n", t + 1, fromsource[1]);
		}
		else
		{
			printf("Case %d: Impossible\n", t + 1);
		}
	}
	return 0;
}
