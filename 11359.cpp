#include <bits/stdc++.h>

using namespace std;

#define pode(a, b) (a >= 0 && a < N && m[b][a] != '#')

int casos;
char m[20][20];
int N;
int marcado[12][12][20][20][20];
int caso;

struct state
{
	int x, y;
	int x1, x2, x3;
	int time;
	int d1, d2, d3;

	state(int x, int y, int x1, int x2, int x3, int d1, int d2, int d3, int time) : x(x), y(y), x1(x1), x2(x2), x3(x3), d1(d1), d2(d2), d3(d3), time(time) {}
};

int readdata()
{
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%s", m[i]);
	}
	return 1;
}

int process()
{
	queue<state> pq;
	while (!pq.empty())
	{
		pq.pop();
	}
	memset(marcado, 0, sizeof(marcado));
	int i, j;
	int g1 = -1, g2 = -1, g3 = -1;
	int R1, R2, R3;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (m[i][j] == 'X')
			{
				if (g1 == -1)
				{
					g1 = j;
					R1 = i;
				}
				else if (g2 == -1)
				{
					g2 = j;
					R2 = i;
				}
				else
				{
					g3 = j;
					R3 = i;
				}
			}
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (m[i][j] == 'S')
			{
				pq.push(state(i, j, g1, g2, g3, 1, 1, 1, 0));
				i = N;
				break;
			}
		}
	}
	printf("Case %d: ", caso++);
	while (!pq.empty())
	{
		state top = pq.front();
		pq.pop();
		int x = top.x;
		int y = top.y;
		int x1 = top.x1;
		int x2 = top.x2;
		int x3 = top.x3;
		if (x1 == -1)
		{
			x1 = 19;
		}
		if (x2 == -1)
		{
			x2 = 19;
		}
		if (x3 == -1)
		{
			x3 = 19;
		}
		if (marcado[x][y][x1][x2][x3])
		{
			continue;
		}
		marcado[x][y][x1][x2][x3] = 1;
		//  printf("%d %d %d %d %d\n",x,y,x1,x2,top.time);
		if (m[top.x][top.y] == 'T')
		{
			printf("%d\n", top.time);
			return 0;
		}
		if (x1 != 19)
		{
			if (pode(x1 + top.d1, R1))
			{
				x1 += top.d1;
			}
			else
			{
				top.d1 *= -1;
				if (pode(x1 + top.d1, R1))
				{
					x1 += top.d1;
				}
			}
		}
		if (x2 != 19)
		{
			if (pode(x2 + top.d2, R2))
			{
				x2 += top.d2;
			}
			else
			{
				top.d2 *= -1;
				if (pode(x2 + top.d2, R2))
				{
					x2 += top.d2;
				}
			}
		}
		if (x3 != 19)
		{
			if (pode(x3 + top.d3, R3))
			{
				x3 += top.d3;
			}
			else
			{
				top.d3 *= -1;
				if (pode(x3 + top.d3, R3))
				{
					x3 += top.d3;
				}
			}
		}
		if (top.x1 == -1)
		{
			x1 = -1;
		}
		if (top.x2 == -1)
		{
			x2 = -1;
		}
		if (top.x3 == -1)
		{
			x3 = -1;
		}
		if ((y == x1 && x == R1) ||
				(y == x2 && x == R2) ||
				(y == x3 && x == R3))
		{
		}
		else
		{
			pq.push(state(x, y, x1, x2, x3, top.d1, top.d2, top.d3, top.time + 1));
		}
		if (x > 0)
		{
			if (m[x - 1][y] != '#')
			{
				if ((x - 1 == R1 && y == x1) ||
						(x - 1 == R2 && y == x2) ||
						(x - 1 == R3 && y == x3))
				{
				}
				else
				{
					pq.push(state(x - 1, y, x1, x2, x3, top.d1, top.d2, top.d3, top.time + 1));
				}
			}
		}
		if (y > 0)
		{
			if (m[x][y - 1] != '#')
			{
				if ((x == R1 && y - 1 == x1) ||
						(x == R2 && y - 1 == x2) ||
						(x == R3 && y - 1 == x3))
				{
				}
				else if ((x == R1 && y == x1 && top.d1 == 1) ||
								 (x == R2 && y == x2 && top.d2 == 1) ||
								 (x == R3 && y == x3 && top.d3 == 1))
				{
				}
				else
				{
					pq.push(state(x, y - 1, x1, x2, x3, top.d1, top.d2, top.d3, top.time + 1));
				}
			}
		}
		if (x < N - 1)
		{
			if (m[x + 1][y] != '#')
			{
				if ((x + 1 == R1 && y == x1) ||
						(x + 1 == R2 && y == x2) ||
						(x + 1 == R3 && y == x3))
				{
				}
				else
				{
					pq.push(state(x + 1, y, x1, x2, x3, top.d1, top.d2, top.d3, top.time + 1));
				}
			}
		}
		if (y < N - 1)
		{
			if (m[x][y + 1] != '#')
			{
				if ((x == R1 && y + 1 == x1) ||
						(x == R2 && y + 1 == x2) ||
						(x == R3 && y + 1 == x3))
				{
				}
				else if ((x == R1 && y == x1 && top.d1 == -1) ||
								 (x == R2 && y == x2 && top.d2 == -1) ||
								 (x == R3 && y == x3 && top.d3 == -1))
				{
				}
				else
				{
					pq.push(state(x, y + 1, x1, x2, x3, top.d1, top.d2, top.d3, top.time + 1));
				}
			}
		}
	}
	printf("-1\n");
	return 0;
}

int main()
{
	int casos;
	scanf("%d", &casos);
	caso = 1;
	while (casos--)
	{
		readdata();
		process();
	}
	return 0;
}
