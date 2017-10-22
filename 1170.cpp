#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt", "r", stdin);

#define CLR(arr) memset((arr), 0, sizeof(arr));
#define NEG(arr) memset((arr), -1, sizeof(arr));

typedef pair<int, int> pint;
typedef map<int, int> mint;

#define SIZE 305

int row, col;

int board[SIZE][SIZE];

bool vis[SIZE][SIZE][7][6];

int num[SIZE][SIZE];

struct node
{
	int r, c, p, left;
	int move;
	int prv;
};

int a, b, c, d;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

int bfs()
{

	node start, tmp;
	start.r = a;
	start.c = b;
	start.move = 0;
	if (board[start.r][start.c] > 1)
	{
		start.p = board[start.r][start.c] % 10;
		start.left = board[start.r][start.c] / 10;
		start.prv = num[start.r][start.c];
	}
	else if (board[start.r][start.c] == 1)
	{
		start.p = 1;
		start.left = 0;
		start.prv = 0;
	}
	else
	{
		return -1;
	}

	CLR(vis);

	queue<node> q;

	q.push(start);

	while (!q.empty())
	{
		node f = q.front();
		q.pop();
		//cout<<f.r<<' '<<f.c<<' '<<f.move<<' '<<f.p<<' '<<f.left<<endl;
		if (f.r == c && f.c == d)
			return f.move;

		for (int i = 0; i < 4; ++i)
		{
			tmp.r = f.r + dr[i] * f.p;
			tmp.c = f.c + dc[i] * f.p;

			if (tmp.r >= 0 && tmp.r < row && tmp.c >= 0 && tmp.c < col && board[tmp.r][tmp.c] > 0)
			{
				tmp.move = f.move + 1;
				if (board[tmp.r][tmp.c] > 1 && num[tmp.r][tmp.c] != tmp.prv)
				{
					tmp.p = board[tmp.r][tmp.c] % 10;
					tmp.left = board[tmp.r][tmp.c] / 10;
					tmp.prv = num[tmp.r][tmp.c];
				}
				else
				{
					if (f.p != 1 && f.left > 1)
					{
						tmp.p = f.p;
						tmp.left = f.left - 1;
						tmp.prv = f.prv;
					}
					else
					{
						tmp.p = 1;
						tmp.left = 0;
						tmp.prv = 0;
					}
				}
				if (!vis[tmp.r][tmp.c][tmp.p][tmp.left])
				{
					q.push(tmp);
					vis[tmp.r][tmp.c][tmp.p][tmp.left] = true;
				}
			}
		}
	}
	return -1;
}

int main()
{
	//FRO

	int kase;
	scanf("%d", &kase);

	while (kase--)
	{
		scanf("%d %d", &row, &col);

		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				scanf("%d", &board[i][j]);
			}
		}

		int total = 1;
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (board[i][j] > 1)
				{
					num[i][j] = total++;
				}
				else
				{
					num[i][j] = 0;
				}
			}
		}

		scanf("%d %d %d %d", &a, &b, &c, &d);

		int ans = bfs();

		if (ans != -1)
			printf("%d\n", ans);
		else
			printf("IMPOSSIBLE\n");

		if (kase)
			printf("\n");
	}

	return 0;
}
