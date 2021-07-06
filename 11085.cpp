#include <bits/stdc++.h>

using namespace std;

enum boolean
{
	False,
	True
};
enum boolean a[9], b[17], c[17];
int s[9];

int cnt = 0;

struct Queen
{
	int row[10], col[10];
} queen[100];

void print()
{
	for (int k = 1; k <= 8; k++)
	{
		queen[cnt].col[k] = k;
		queen[cnt].row[k] = s[k];
	}
	cnt++;
}

void movequeen(int i, int j)
{
	a[j] = True;
	b[i + j] = True;
	c[i - j + 9] = True;
}
void eightqueen()
{
	int i, j;
	for (i = 2; i <= 16; i++)
	{
		if (i >= 2 && i <= 9)
		{
			a[i - 1] = True;
		}
		b[i] = c[i] = True;
	}
	i = 1;
	j = 1;
	while (i >= 1)
	{
		while (j <= 8)
		{
			if (a[j] && b[i + j] && c[i - j + 9])
			{
				break;
			}
			j++;
		}
		if (j <= 8)
		{
			a[j] = b[i + j] = c[i - j + 9] = False;
			s[i] = j;
			if (i == 8)
			{
				print();
				movequeen(i, j);
				i = i - 1;
				j = s[i];
				movequeen(i, j);
				j++;
			}
			else
			{
				i++;
				j = 1;
			}
		}
		else
		{
			i--;
			if (i >= 1)
			{
				j = s[i];
				movequeen(i, j);
				j++;
			}
		}
	}
}

int main()
{
	eightqueen();
	int row[10], kase = 1;
	while (scanf("%d%d%d%d%d%d%d%d", &row[1], &row[2], &row[3], &row[4],
							 &row[5], &row[6], &row[7], &row[8]) == 8)
	{
		int min = 1000000;
		int i, j;
		for (i = 0; i < cnt; i++)
		{
			int step = 0;
			for (j = 1; j <= 8; j++)
				if (row[j] != queen[i].row[j])
				{
					step++;
				}
			if (step < min)
			{
				min = step;
			}
		}
		printf("Case %d: %d\n", kase++, min);
	}
	return 0;
}
