#include <bits/stdc++.h>

using namespace std;

/*
447
Population Explosion
*/
int Y;
char city[22][22];
char temp[22][22];
int cc[22][22];
int xx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int yy[] = {1, -1, 0, 0, -1, 1, 1, -1};
void Ini()
{
	int i, j;
	for (i = 0; i < 21; i++)
	{
		for (j = 0; j < 21; j++)
		{
			temp[i][j] = ' ';
			cc[i][j] = 0;
		}
	}
}
void ReadCase()
{
	char input[100];
	int r, c;
	for (r = 0; r < 20; r++)
	{
		for (c = 0; c < 20; c++)
		{
			city[r][c] = ' ';
		}
	}
	while (gets(input))
	{
		for (int i = 0; input[i]; i++)
		{
			if (input[i] == '\n')
			{
				input[i] = NULL;
			}
		}
		if (strlen(input) == 0)
		{
			break;
		}
		sscanf(input, "%d%d", &r, &c);
		r--;
		c--;
		city[r][c] = 'O';
	}
}
void Print()
{
	int i;
	for (i = 0; i < 20; i++)
	{
		printf("*");
		city[i][20] = NULL;
	}
	putchar('\n');
	for (i = 0; i < 20; i++)
	{
		printf("%s\n", city[i]);
	}
}
void Copy()
{
	int i;
	for (i = 0; i < 20; i++)
	{
		temp[i][20] = NULL;
		strcpy(city[i], temp[i]);
	}
}
void Mark(int r, int c)
{
	int i, nr, nc;
	for (i = 0; i < 8; i++)
	{
		nr = r + xx[i];
		nc = c + yy[i];
		if (nr > 20 || nr < 0 || nc > 20 || nc < 0)
		{
			continue;
		}
		cc[nr][nc]++;
	}
}
void Update()
{
	int i, j;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			if (city[i][j] == 'O')
			{
				if (cc[i][j] == 2 || cc[i][j] == 3)
				{
					temp[i][j] = 'O';
				}
			}
			else
			{
				if (cc[i][j] == 3)
				{
					temp[i][j] = 'O';
				}
			}
		}
	}
}
void Cal()
{
	int i, j;
	Print();
	Y--;
	while (Y--)
	{
		Ini();
		for (i = 0; i < 20; i++)
		{
			for (j = 0; j < 20; j++)
				if (city[i][j] == 'O')
				{
					Mark(i, j);
				}
		}
		Update();
		Copy();
		Print();
	}
	for (i = 0; i < 20; i++)
	{
		printf("*");
	}
	printf("\n");
}
int main()
{
	char input[100];
	int kase;
	gets(input);
	sscanf(input, "%d", &kase);
	gets(input);
	while (kase--)
	{
		gets(input);
		sscanf(input, "%d", &Y);
		Ini();
		ReadCase();
		Cal();
		if (kase)
		{
			printf("\n");
		}
	}
	return 0;
}
