#include <bits/stdc++.h>

using namespace std;

#define deb 0

typedef string board;

#define B(b, i, j) b[((i)*4) + (j)]

typedef struct
{
	board b;
	int moves;
} mboard;

int bad(board b)
{
	int j;
	for (int i = 0; i < 3; i++)
		for (j = 0; j < 4; j++)
		{
			if (B(b, i, j) == 'R' || B(b, i, j) == 'B')
				if (B(b, i + 1, j) == 'R' || B(b, i + 1, j) == 'B')
				{
					return 1;
				}
		}
	for (int i = 0; i < 4; i++)
		for (j = 0; j < 3; j++)
		{
			if (B(b, i, j) == 'R' || B(b, i, j) == 'B')
				if (B(b, i, j + 1) == 'R' || B(b, i, j + 1) == 'B')
				{
					return 1;
				}
		}
	return 0;
}

queue<mboard> q;
set<board> seen;

void print(board b)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%c", B(b, i, j));
		}
		printf("\n");
	}
	printf("\n");
}

void attempt(board b, int moves)
{
	if (seen.count(b) > 0)
	{
		return;
	}
	if (deb)
	{
		puts("not seen");
	}
	seen.insert(b);
	int s = seen.size();
	if (deb)
		if ((s % 1000) == 0)
		{
			printf("seen: %u q: %u\n", (unsigned int)seen.size(), (unsigned int)q.size());
		}
	if (deb)
	{
		print(b);
	}
	if (bad(b))
	{
		return;
	}
	if (deb)
	{
		puts("not bad");
	}
	mboard m;
	m.b = b;
	m.moves = moves;
	q.push(m);
	if (deb)
	{
		puts("pushed");
	}
}

int badd(int i, int di)
{
	if (i + di > 3)
	{
		return 1;
	}
	if (i + di < 0)
	{
		return 1;
	}
	return 0;
}
void move(board b, int i, int j, int di, int dj, int moves)
{
	if (badd(i, di * 2))
	{
		return;
	}
	if (badd(j, dj * 2))
	{
		return;
	}
	if (B(b, i, j) == '.')
	{
		return;
	}
	if (B(b, i + di, j + dj) == '.')
	{
		return;
	}
	if (B(b, i + di + di, j + dj + dj) != '.')
	{
		return;
	}
	B(b, i + di + di, j + dj + dj) = B(b, i, j);
	B(b, i, j) = '.';
	attempt(b, moves + 1);
}
void move2(board b, int i, int j, int di, int dj, int moves)
{
	if (badd(i, di * 3))
	{
		return;
	}
	if (badd(j, dj * 3))
	{
		return;
	}
	if (B(b, i, j) == '.')
	{
		return;
	}
	if (B(b, i + di, j + dj) == '.')
	{
		return;
	}
	if (B(b, i + di + di, j + dj + dj) == '.')
	{
		return;
	}
	if (B(b, i + di + di + di, j + dj + dj + dj) != '.')
	{
		return;
	}
	B(b, i + di + di + di, j + dj + dj + dj) = B(b, i, j);
	B(b, i, j) = '.';
	attempt(b, moves + 1);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cc = 0; cc < T; ++cc)
	{
		int i, j;
		int pos = 0;
		int mb = 0;
		char line[100];
		q = queue<mboard>();
		seen.clear();
		board b = "................";
		for (i = 0; i < 4; i++)
		{
			scanf("%s", line);
			//        fgets(line, 100, stdin);
			for (j = 0; j < 4; j++)
			{
				B(b, i, j) = line[j];
			}
		}
		attempt(b, 0);
		while (q.size() > 0)
		{
			pos++;
			mboard m = q.front();
			q.pop();
			board b = m.b;
			if (deb)
				if (m.moves > mb)
				{
					mb = m.moves;
					printf("moves: %u\n", mb);
				}
			if (B(b, 0, 0) == 'R')
			{
				printf("%u\n", m.moves);
				break;
			}
			for (i = 0; i < 4; i++)
				for (j = 0; j < 4; j++)
				{
					move(b, i, j, 0, 1, m.moves);
					move(b, i, j, 0, -1, m.moves);
					move(b, i, j, 1, 0, m.moves);
					move(b, i, j, -1, 0, m.moves);
					move2(b, i, j, 0, 1, m.moves);
					move2(b, i, j, 0, -1, m.moves);
					move2(b, i, j, 1, 0, m.moves);
					move2(b, i, j, -1, 0, m.moves);
				}
		}
		if (deb)
		{
			printf("done %u\n", pos);
		}
	}
	return 0;
}
