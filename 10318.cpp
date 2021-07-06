#include <bits/stdc++.h>

using namespace std;

int button[6][6];  // [1~5][1~5] : 1 -> light
int patt[4][4]; // [1~3][1~3]
int Prs[26];
int tmp[26]; //1 ~25 : 1 -> press
int r, c, flag, Case, min_;

void initial();
void Panel(int);
void Press(int, int);
int Unlock();

int main()
{
	char patn[4];
	Case = 0;
	while (1)
	{
		scanf("%d %d\n", &r, &c);
		if (r == 0 && c == 0)
		{
			break;
		}
		initial();
		for (int i = 1; i <= 3; i++)
		{
			scanf("%s", patn);
			for (int j = 1; j <= 3; j++)
			{
				if (patn[j - 1] == '*')
				{
					patt[i][j] = 1;
				}
			}
		}
		Panel(1);
		// output
		printf("Case #%d\n", ++Case);
		if (min_ < r * c + 1)
		{
			for (int i = 1; i <= r * c; i++)
			{
				if (Prs[i] == 1 && min_ > 0)
				{
					printf("%d", i);
					min_--;
					if (min_ > 0)
					{
						printf(" ");
					}
				}
			}
			printf("\n");
		}
		else
		{
			printf("Impossible.\n");
		}
	}//while(1)
	return 0;
}

void Panel(int depth)
{
	int i, j, total;
	for (int k = 0; k <= 1; k++)
	{
		flag = 0;
		Press(depth, k);
		i = (depth - 1) / c + 1;
		j = (depth - 1) % c + 1;
		if (depth >= 2 * c + 1)
		{
			for (int m = 1; m <= i - 2; m++)
				for (int n = 1; n <= c; n++)
					if (button[m][n] == 0)
					{
						flag = 1;
					}
		}
		if (depth == r * c && flag == 0)
		{
			if (Unlock() == 1)
			{
				total = 0;
				for (int m = 1; m <= r * c; m++)
				{
					total += tmp[m];
				}
				if (total < min_)
				{
					min_ = total;
					for (int m = 1; m <= r * c; m++)
					{
						Prs[m] = tmp[m];
					}
					flag = 1;
				}
			}
		}
		else if (flag == 0)
		{
			Panel(depth + 1);
		}
		Press(depth, k);
	}//for(k) 按或不按
}

void Press(int depth, int k)
{
	int i, j;
	if (k == 1)
	{
		tmp[depth] = 1 - tmp[depth];
		i = (depth - 1) / c + 1;
		j = (depth - 1) % c + 1;
		for (int m = i - 1; m <= i + 1; m++)
		{
			for (int n = j - 1; n <= j + 1; n++)
			{
				if ((1 <= m && m <= r) && (1 <= n && n <= c))
				{
					button[m][n] = button[m][n] + patt[2 + m - i][2 + n - j];
					if (button[m][n] == 2)
					{
						button[m][n] = 0;
					}
				}
			}
		}
	}//if
}

int Unlock()
{
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			if (button[i][j] == 0)
			{
				return 0;
			}
	return 1;
}

void initial()
{
	flag = 0;
	min_ = r * c + 1;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			button[i][j] = 0;
		}
	}
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			patt[i][j] = 0;
		}
	}
	for (int i = 1; i <= 25; i++)
	{
		Prs[i] = 0;
		tmp[i] = 0;
	}
}
