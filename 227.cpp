#include <bits/stdc++.h>

using namespace std;

char B[7][7], com[1000];
int er, ec, F;

void Above()
{
	char tc;
	if (er == 0)
	{
		F = 1;
		return;
	}
	tc = B[er - 1][ec];
	B[er][ec] = tc;
	B[er - 1][ec] = ' ';
	er--;
}
void Right()
{
	char tc;
	if (ec == 4)
	{
		F = 1;
		return;
	}
	tc = B[er][ec + 1];
	B[er][ec + 1] = ' ';
	B[er][ec] = tc;
	ec++;
}
void Below()
{
	char tc;
	if (er == 4)
	{
		F = 1;
		return;
	}
	tc = B[er + 1][ec];
	B[er + 1][ec] = ' ';
	B[er][ec] = tc;
	er++;
}
void Left()
{
	char tc;
	if (ec == 0)
	{
		F = 1;
		return;
	}
	tc = B[er][ec - 1];
	B[er][ec - 1] = ' ';
	B[er][ec] = tc;
	ec--;
}
void Print()
{
	int i, j;
	if (F)
	{
		printf("This puzzle has no final configuration.\n");
		return;
	}
	for (i = 0; i < 5; i++)
	{
		printf("%c", B[i][0]);
		for (j = 1; j < 5; j++)
			printf(" %c", B[i][j]);
		printf("\n");
	}
}
void Cal()
{
	int i;
	F = 0;
	while (1)
	{
		gets(com);
		for (i = 0; com[i]; i++)
		{
			if (com[i] == '\n')
			{
				com[i] = '\0';
			}
		}
		for (i = 0; com[i]; i++)
		{
			if (com[i] == '0')
			{
				return;
			}
			if (F)
			{
				continue;
			}
			switch (com[i])
			{
			case 'A':
				Above();
				break;
			case 'R':
				Right();
				break;
			case 'B':
				Below();
				break;
			case 'L':
				Left();
				break;
			default:
				F = 1;
			}
		}
	}
}

int main()
{
	int i, j, f, kase = 0;
	while (1)
	{
		gets(B[0]);
		if (!strcmp(B[0], "Z"))
		{
			break;
		}
		f = 1;
		for (i = 0; B[0][i]; i++)
		{
			if (B[0][i] == ' ')
			{
				f = 0;
				er = 0;
				ec = i;
				break;
			}
		}
		for (i = 1; i < 5; i++)
		{
			gets(B[i]);
			if (!f)
			{
				continue;
			}
			for (j = 0; B[i][j]; j++)
			{
				if (B[i][j] == ' ')
				{
					f = 0;
					er = i;
					ec = j;
				}
			}
		}
		if (kase++)
		{
			printf("\n");
		}
		Cal();
		printf("Puzzle #%d:\n", kase);
		Print();
	}
	return 0;
}
