#include <bits/stdc++.h>

using namespace std;

char c5[26][31] =
		{
				".***..*...*.*****.*...*.*...*.",
				"****..*...*.****..*...*.****..",
				".****.*...*.*.....*......****.",
				"****..*...*.*...*.*...*.****..",
				"*****.*.....***...*.....*****.",
				"*****.*.....***...*.....*.....",
				".****.*.....*..**.*...*..***..",
				"*...*.*...*.*****.*...*.*...*.",
				"*****...*.....*.....*...*****.",
				"..***....*.....*..*..*...**...",
				"*...*.*..*..***...*..*..*...*.",
				"*.....*.....*.....*.....*****.",
				"*...*.**.**.*.*.*.*...*.*...*.",
				"*...*.**..*.*.*.*.*..**.*...*.",
				".***..*...*.*...*.*...*..***..",
				"****..*...*.****..*.....*.....",
				".***..*...*.*...*.*..**..****.",
				"****..*...*.****..*..*..*...*.",
				".****.*......***......*.****..",
				"*****.*.*.*...*.....*....***..",
				"*...*.*...*.*...*.*...*..***..",
				"*...*.*...*..*.*...*.*....*...",
				"*...*.*...*.*.*.*.**.**.*...*.",
				"*...*..*.*....*....*.*..*...*.",
				"*...*..*.*....*.....*.....*...",
				"*****....*....*....*....*****."};

char page[60][60];

void blank()
{
	int i, j;
	for (i = 0; i < 60; i++)
		for (j = 0; j < 60; j++)
		{
			page[i][j] = '.';
		}
}

void dump_page()
{
	int i, j;
	/* printf(" ");
	for (i = 1; i <= 60; i++)
	printf("%d", i % 10);
	printf("\n");*/
	for (i = 0; i < 60; i++)
	{
		// printf("%2d: ", i + 1); /* DEBUG: print the line number */
		for (j = 0; j < 60; j++)
		{
			fprintf(stdout, "%c", page[i][j]);
		}
		fprintf(stdout, "\n");
	}
	fprintf(stdout, "\n");
	for (i = 0; i < 60; i++)
	{
		fprintf(stdout, "-");
	}
	fprintf(stdout, "\n\n");
}

void print(int row, int column, int size, int align, char *text)
{
	int left, right, letter, i, k;
	char c;
	/* calculate the positions */
	if (!align || align == 1)
	{
		left = column - 1;
		if (size == 1)
		{
			right = left + strlen(text) - 1;
		}
		else
		{
			right = left + strlen(text) * 6 - 1;
		}
	}
	else if (align == 2)
	{
		right = column - 1;
		if (size == 1)
		{
			left = right - strlen(text) + 1;
		}
		else
		{
			left = right - strlen(text) * 6 + 1;
		}
	}
	else if (align == 3)
	{
		if (size == 1)
		{
			left = 29 - strlen(text) / 2 + strlen(text) % 2;
			right = left + strlen(text) - 1;
		}
		else
		{
			left = 30 - strlen(text) * 3;
			right = left + strlen(text) * 6 - 1;
		}
	}
	/* the actual printing */
	if (size == 1)
	{
		for (i = left; i <= right; i++)
		{
			if (i < 0 || i > 59)
			{
				continue;
			}
			if (text[abs(i - left)] != ' ')
			{
				page[row - 1][i] = text[abs(i - left)];
			}
		}
	}
	else
	{
		for (k = 0; k < 5; k++)
		{
			for (i = left; i <= right; i++)
			{
				if (i < 0 || i > 59)
				{
					continue;
				}
				letter = abs(i - left) / 6;
				if (toupper(text[letter]) - 'A' < 26 &&
						toupper(text[letter]) - 'A' >= 0)
				{
					c = c5[toupper(text[letter]) - 'A'][k * 6 + abs(i - left) % 6];
				}
				else
				{
					c = '.';
				}
				if (row + k - 1 < 60)
					if (c != '.')
					{
						page[row + k - 1][i] = c;
					}
			}
		}
	}
}

int main()
{
	blank();
	char cmd[5];
	while (scanf("%s", cmd) == 1)
	{
		char font[3], text[1024], tmp[1024];
		int row, column, fsize, i, align;
		if (strcmp(cmd, ".EOP"))
		{
			row = column = 1;
			scanf("%s", font);
			scanf("%d", &row);
			align = 0;
			if (!strcmp(cmd, ".P"))
			{
				scanf("%d", &column);
			}
			else if (!strcmp(cmd, ".L"))
			{
				column = 1;
				align = 1; /* left alignment */
			}
			else if (!strcmp(cmd, ".R"))
			{
				column = 60;
				align = 2; /* right alignment */
			}
			else if (!strcmp(cmd, ".C"))
			{
				align = 3;
			}
			fgets(tmp, 1024, stdin);
			tmp[strlen(tmp) - 1] = '\0';
			/* get rid of the delimiters */
			strcpy(text, tmp + 2);
			for (i = strlen(text) - 1; i >= 0; i--)
				if (text[i] == '|')
				{
					text[i] = '\0';
					break;
				}
			if (!strcmp(font, "C5"))
			{
				fsize = 5;
			}
			else
			{
				fsize = 1;
			}
			print(row, column, fsize, align, text);
		}
		else
		{
			dump_page();
			blank();
		}
	}
	return 0;
}
