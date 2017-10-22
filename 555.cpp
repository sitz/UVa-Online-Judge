#include <bits/stdc++.h>

using namespace std;

/**
555
**/
#define MAXN 53
char Cards[MAXN][3] = {"C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "CT", "CJ", "CQ", "CK", "CA",
											 "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "DT", "DJ", "DQ", "DK", "DA",
											 "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "ST", "SJ", "SQ", "SK", "SA",
											 "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "HT", "HJ", "HQ", "HK", "HA"};
char Side[4][2] = {"S", "W", "N", "E"};
int Player[5][15];
char Deal[3][55];
int com(const void *a, const void *s)
{
	return *(int *)a - *(int *)s;
}
int Search(char ss[])
{
	int i;
	for (i = 0; i < 52; i++)
		if (!strcmp(ss, Cards[i]))
		{
			break;
		}
	return i;
}
void ReadCase()
{
	scanf("%s", Deal[0]);
	scanf("%s", Deal[1]);
}
void SolvedCase(char St[])
{
	int i, j, StP, k, p, m = 0, c = 0;
	char Temp[5];
	for (i = 0; i < 4; i++)
		if (!strcmp(St, Side[i]))
		{
			break;
		}
	StP = i + 1;
	StP %= 4;
	for (i = 0; i < 2; i++)
	{
		k = 0;
		for (j = 0; Deal[i][j]; j++)
		{
			Temp[k++] = Deal[i][j];
			if (k == 2)
			{
				Temp[k] = NULL;
				k = 0;
				p = Search(Temp);
				Player[StP][m] = p;
				StP++;
				StP %= 4;
				c++;
				if (c % 4 == 0)
				{
					m++;
				}
			}
		}
	}
}
void Print()
{
	int i, j, m;
	for (i = 0; i < 4; i++)
	{
		qsort(Player[i], 13, sizeof(int), com);
		printf("%s:", Side[i]);
		for (j = 0; j < 13; j++)
		{
			m = Player[i][j];
			printf(" %s", Cards[m]);
		}
		putchar('\n');
	}
}
int main()
{
	char input[10];
	while (1)
	{
		scanf("%s", input);
		if (!strcmp("#", input))
		{
			break;
		}
		ReadCase();
		SolvedCase(input);
		Print();
	}
	return 0;
}
