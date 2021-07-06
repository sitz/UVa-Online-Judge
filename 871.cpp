#include <bits/stdc++.h>

using namespace std;

#define MAXN 30

char MZ[MAXN][MAXN], input[100];
int R, max_, C;

int isEmpty()
{
	int i, k;
	for (i = 0; input[i]; i++)
	{
		if (input[i] == '\n')
		{
			input[i] = NULL;
			break;
		}
	}
	k = strlen(input);
	if (k > C)
		C = k;
	if (k == 0)
		return 1;
	return 0;
}
int sss;
void Fill(int r, int c)
{
	int i, j, nr, nc;
	MZ[r][c] = '0';
	for (i = -1; i < 2; i++)
	{
		for (j = -1; j < 2; j++)
		{
			if (!i && !j)
				continue;
			nr = r + i;
			nc = c + j;
			if (nr >= R || nr < 0 || nc >= C || nc < 0)
				continue;
			if (MZ[nr][nc] == '1')
			{
				sss++;
				Fill(nr, nc);
			}
		}
	}
}
void Cal()
{
	int i, j;
	max_ = 0;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			if (MZ[i][j] == '1')
			{
				sss = 1;
				Fill(i, j);
				if (sss > max_)
					max_ = sss;
			}
		}
	}
	printf("%d\n", max_);
}

int main()
{
	int i, kase;
	gets(input);
	sscanf(input, "%d", &kase);
	gets(input);
	while (kase--)
	{
		R = C = 0;
		while (gets(input))
		{
			if (isEmpty())
			{
				break;
			}
			strcpy(MZ[R++], input);
		}
		Cal();
		if (kase)
			printf("\n");
	}
	return 0;
}
