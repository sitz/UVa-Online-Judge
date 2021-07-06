#include <bits/stdc++.h>

using namespace std;

typedef struct
{
	char used;
	short key[4];
	char data[25][25];
} PIECE;

PIECE piece[100];
int n_piece, dim;
char table[10][10];

int Recur(int n)
{
	int i, y, x;
	short mask[4] = {-10, -10, -10, -10};
	if (n == -1)
	{
		return 0;
	}
	y = n / dim, x = n % dim;
	if (x == 0)
	{
		mask[1] = 0;//left
	}
	else if (x == dim - 1)
	{
		mask[3] = 0;//right
	}
	else
	{
		mask[3] = -(piece[(int)table[y][x + 1]].key[1]);//left of right
	}
	if (y == 0)
	{
		mask[0] = 0;//up
	}
	else if (y == dim - 1)
	{
		mask[2] = 0;//down
	}
	else
	{
		mask[2] = -(piece[(int)table[y + 1][x]].key[0]);//up of down
	}
	for (i = 0; i < n_piece; i++)
	{
		if (piece[i].used)
		{
			continue;
		}
		if ((mask[0] != -10 && mask[0] != piece[i].key[0]) ||
				(mask[1] != -10 && mask[1] != piece[i].key[1]) ||
				(mask[2] != -10 && mask[2] != piece[i].key[2]) ||
				(mask[3] != -10 && mask[3] != piece[i].key[3]))
		{
			continue;
		}
		piece[i].used = 1;
		table[y][x] = i;
		if (Recur(n - 1) == 0)
		{
			return 0;
		}
		piece[i].used = 0;
	}
	return -1;
}

void MyGets(char *s)
{
	do
		if (gets(s) == 0)
		{
			exit(0);
		}
	while (*s == 0);
}

int main()
{
	int n;
	char line[128];
	gets(line);
	n = atoi(line);
	while (--n >= 0)
	{
		int i, j, wid, hei;
		memset(table, 0x77, sizeof(char));
		MyGets(line);
		sscanf(line, "%d %d %d", &dim, &hei, &wid);
		n_piece = dim * dim;
		for (i = n_piece; --i >= 0;)
		{
			for (j = 0; j < hei; j++)
			{
				MyGets(line);
				memset(piece[i].data[j], ' ', wid);
				memcpy(piece[i].data[j], line, strlen(line));
			}
			MyGets(line);
			sscanf(line, "%hd %hd %hd %hd",
						 &piece[i].key[0], &piece[i].key[1],
						 &piece[i].key[2], &piece[i].key[3]);
			piece[i].used = 0;
		}
		Recur(n_piece - 1);
		for (i = 0; i < dim; i++)
		{
			int k, a;
			for (j = 0; j < hei; j++, printf("\n"))
				for (k = 0; k < dim; k++)
					for (a = 0; a < wid; a++)
					{
						printf("%c", piece[(int)table[i][k]].data[j][a]);
					}
		}
		if (n)
		{
			printf("\n");
		}
	}
	return 0;
}
