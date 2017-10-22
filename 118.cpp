#include <bits/stdc++.h>

using namespace std;

#define MAXN 52

char Grid[MAXN][MAXN];
char Cmd[110];
char Side[] = "WNES";
int X[] = {0, -1, 0, 1};
int Y[] = {-1, 0, 1, 0};
int D[5];
int R, C;

void Ini()
{
	int i;
	for (i = 0; Side[i]; i++)
	{
		D[Side[i]] = i;
	}
}

void Move(int r, int c, int dir)
{
	int i, tr, tc;
	for (i = 0; Cmd[i]; i++)
	{
		if (Cmd[i] == 'R')
		{
			dir++;
		}
		else if (Cmd[i] == 'L')
		{
			dir--;
		}
		dir += 4;
		dir %= 4;
		if (Cmd[i] == 'F')
		{
			tc = Y[dir] + c;
			tr = X[dir] + r;
			if (tr > R || tc > C || tr < 0 || tc < 0)
			{
				if (Grid[r][c] != 1)
				{
					printf("%d %d %c LOST\n", c, R - r, Side[dir]);
					Grid[r][c] = 1;
					return;
				}
			}
			else
			{
				r = tr;
				c = tc;
			}
		}
	}
	printf("%d %d %c\n", c, R - r, Side[dir]);
}

int main()
{
	int sr, sc, dir;
	char input[100], ss[10];
	Ini();
	gets(input);
	sscanf(input, "%d%d", &C, &R);
	while (gets(input))
	{
		gets(Cmd);
		sscanf(input, "%d%d%s", &sc, &sr, ss);
		dir = D[ss[0]];
		Move(R - sr, sc, dir);
	}
	return 0;
}
