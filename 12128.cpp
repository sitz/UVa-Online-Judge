#include <bits/stdc++.h>

using namespace std;




int grid[1010][1010], rep[1010][1010];
int p[] = {-1, 0, 1, 0};
int q[] = {0, 1, 0, -1};
int T, N, X, Y, x, y, xi, yi, xf, yf;

struct abc
{
	int x, y, min;

	abc() {}
	abc(int x, int y, int min = 0) : x(x), y(y), min(min) {}

	bool operator<(const abc &lhs) const
	{
		return min < lhs.min;
	}
} aux;

int getId(int x, int y)
{
	return y * X + x;
}

pair<int, int> getPos(int id)
{
	return make_pair(id % X, id / X);
}

bool isInside(int x, int y)
{
	return (y >= 0 && y < Y && x >= 0 && x < X);
}

int find_set(int x, int y)
{
	if (rep[y][x] != getId(x, y))
		rep[y][x] = find_set(getPos(rep[y][x]).first, getPos(rep[y][x]).second);
	return rep[y][x];
}

void link(int xA, int yA, int xB, int yB)
{
	int idRepA = find_set(xA, yA);
	int idRepB = find_set(xB, yB);
	if (idRepA != idRepB)
		rep[getPos(idRepA).second][getPos(idRepA).first] = rep[getPos(idRepB).second][getPos(idRepB).first];
}

bool isConnected(int xA, int yA, int xB, int yB)
{
	if (rep[yA][xA] == -1 || rep[yB][xB] == -1)
		return false;
	int idRepA = find_set(xA, yA);
	int idRepB = find_set(xB, yB);

	return (idRepA == idRepB);
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &N, &X, &Y);
		scanf("%d%d%d%d", &xi, &yi, &xf, &yf);
		memset(grid, -1, sizeof(grid));
		queue<abc> fila;
		priority_queue<abc> heap;
		for (int i = 0; i < N; i++)
		{
			scanf("%d%d", &x, &y);
			grid[y][x] = 0;
			fila.push(abc(x, y));
			heap.push(abc(x, y, 0));
		}
		while (!fila.empty())
		{
			y = fila.front().y;
			x = fila.front().x;
			fila.pop();
			for (int i = 0; i < 4; i++)
			{
				if (isInside(x + q[i], y + p[i]) && grid[y + p[i]][x + q[i]] == -1)
				{
					grid[y + p[i]][x + q[i]] = grid[y][x] + 1;
					fila.push(abc(x + q[i], y + p[i]));
					heap.push(abc(x + q[i], y + p[i], grid[y][x] + 1));
				}
			}
		}
		memset(rep, -1, sizeof(rep));
		int m = 0;
		while (!heap.empty())
		{
			aux = heap.top();
			heap.pop();
			rep[aux.y][aux.x] = getId(aux.x, aux.y);
			for (int i = 0; i < 4; i++)
			{
				if (isInside(aux.x + q[i], aux.y + p[i]) && rep[aux.y + p[i]][aux.x + q[i]] != -1)
				{
					link(aux.x, aux.y, aux.x + q[i], aux.y + p[i]);
				}
			}
			if (isConnected(xi, yi, xf, yf))
			{
				m = aux.min;
				break;
			}
		}
		fila.push(abc(xi, yi, 0));
		while (!fila.empty())
		{
			aux = fila.front();
			fila.pop();
			if (aux.x == xf && aux.y == yf)
				break;
			for (int i = 0; i < 4; i++)
			{
				if (isInside(aux.x + q[i], aux.y + p[i]) && grid[aux.y + p[i]][aux.x + q[i]] >= m)
				{
					grid[aux.y + p[i]][aux.x + q[i]] = -1;
					fila.push(abc(aux.x + q[i], aux.y + p[i], aux.min + 1));
				}
			}
		}
		printf("%d %d\n", m, aux.min);
	}
}