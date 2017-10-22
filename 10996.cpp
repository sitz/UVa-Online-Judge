#include <bits/stdc++.h>

using namespace std;

int board[200][200];
int visit[200][200];
#define b(i, j) board[(i) + 100][(j) + 100]
#define v(i, j) visit[(i) + 100][(j) + 100]
int i, j, k, m, n, x, y, z, cookie = 1;
char P;
int dofilled(int x, int y, int c, int B)
{
	if (v(x, y) == cookie)
	{
		return 1;
	}
	if (b(x, y) == -1)
	{
		return 1;
	}
	if (b(x, y) == B)
	{
		return 1;
	}
	if (b(x, y) != c)
	{
		return 0;
	}
	v(x, y) = cookie;
	return dofilled(x + 1, y, c, B) && dofilled(x - 1, y, c, B) && dofilled(x, y + 1, c, B) && dofilled(x, y - 1, c, B);
}
int dofill(int x, int y, int d)
{
	if (v(x, y) != cookie)
	{
		return 0;
	}
	if (b(x, y) == d)
	{
		return 0;
	}
	b(x, y) = d;
	v(x, y) = 0;
	return 1 + dofill(x + 1, y, d) + dofill(x - 1, y, d) + dofill(x, y + 1, d) + dofill(x, y - 1, d);
}

int reach(int x, int y, int c, int B, int d)
{
	cookie++;
	if (!dofilled(x, y, c, B))
	{
		return 0;
	}
	return dofill(x, y, d);
}
int owns[256], caps[256];
int update(int x, int y, int P, int Q)
{
	int cap = reach(x, y, Q, P, 0);
	caps[P] += cap;
	return cap;
}
void final()
{
	int x, y;
	for (x = -z; x <= z; x++)
	{
		for (y = -z; y <= z; y++)
		{
			owns['W'] += reach(x, y, 0, 'W', 'w');
			owns['B'] += reach(x, y, 0, 'B', 'b');
		}
	}
}
int main()
{
	while (2 == scanf("%d%d", &n, &m) && n)
	{
		z = (n - 1) / 2;
		memset(board, 0, sizeof(board));
		memset(owns, 0, sizeof(owns));
		memset(caps, 0, sizeof(owns));
		for (i = -z; i <= z; i++)
		{
			b(i, -z - 1) = b(i, z + 1) = b(-z - 1, i) = b(z + 1, i) = -1;
		}
		for (i = 0; i < m; i++)
		{
			scanf(" %c ( %d , %d )", &P, &x, &y);
			assert(x >= -z && y >= -z && x <= z && y <= z);
			if (b(x, y))
			{
				printf("board occupied %d %d\n", x, y);
			}
			b(x, y) = P;
			update(x + 1, y, P, 'B' + 'W' - P);
			update(x - 1, y, P, 'B' + 'W' - P);
			update(x, y + 1, P, 'B' + 'W' - P);
			update(x, y - 1, P, 'B' + 'W' - P);
			if (update(x, y, 'B' + 'W' - P, P))
			{
				printf("bad move!");
			}
		}
		final();
		printf("%d %d\n", owns['B'] + caps['B'], owns['W'] + caps['W']);
	}
}
