#include <bits/stdc++.h>

using namespace std;

/**
652
**/
#define MAXN 362880
char Board[12];
int Fac[10];
struct ss
{
	char command;
	int parent;
	char colour;
} V[MAXN + 2];
char Q[MAXN][1][11];
int QH, QT, SUM;
void Gen()
{
	int i, sum = 1;
	for (i = 1; i < 10; i++)
	{
		sum *= i;
		Fac[i] = sum;
	}
}
int Isvisit(char tt[], int x = 0)
{
	int i, j, l;
	int c;
	SUM = 0;
	l = strlen(tt);
	for (i = 0; i < l - 1; i++)
	{
		c = 0;
		for (j = i + 1; tt[j]; j++)
			if (tt[i] > tt[j])
			{
				c++;
			}
		SUM += c * Fac[l - i - 1];
	}
	SUM++;
	if (x == 1)
	{
		return 0;
	}
	if (V[SUM].colour == 1)
	{
		return 0;
	}
	V[SUM].colour = 1;
	return 1;
}
int Push(char tt[])
{
	int x;
	x = Isvisit(tt);
	if (x == 0)
	{
		return 0;
	}
	strcpy(Q[QH][0], tt);
	return 1;
}
char *Pop()
{
	QT++;
	return Q[QT - 1][0];
}
int IsEmpty()
{
	return QH == QT;
}
int GENPUSH(char aa[])
{
	int i, j, p;
	char temp[15];
	char c;
	Isvisit(aa);
	;
	i = SUM;
	strcpy(temp, aa);
	for (p = 0; aa[p] != '9'; p++)
		;
	if (p != 0 && p != 3 && p != 6)
	{
		c = temp[p - 1];
		temp[p - 1] = temp[p];
		temp[p] = c;
		j = Push(temp);
		if (j != 0)
		{
			if (SUM == 6)
			{
				j = 2;
			}
			V[SUM].parent = i;
			V[SUM].command = 'r';
			strcpy(Q[QH++][0], temp);
		}
	}
	strcpy(temp, aa);
	if (p + 1 != 3 && p + 1 != 6 && p + 1 != 9)
	{
		c = temp[p + 1];
		temp[p + 1] = temp[p];
		temp[p] = c;
		j = Push(temp);
		if (j != 0)
		{
			if (SUM == 6)
			{
				j = 2;
			}
			V[SUM].parent = i;
			V[SUM].command = 'l';
			strcpy(Q[QH++][0], temp);
		}
	}
	strcpy(temp, aa);
	if (p + 3 <= 8)
	{
		c = temp[p + 3];
		temp[p + 3] = temp[p];
		temp[p] = c;
		j = Push(temp);
		if (j != 0)
		{
			if (SUM == 6)
			{
				j = 2;
			}
			V[SUM].parent = i;
			V[SUM].command = 'u';
			strcpy(Q[QH++][0], temp);
		}
	}
	strcpy(temp, aa);
	if (p - 3 >= 0)
	{
		c = temp[p - 3];
		temp[p - 3] = temp[p];
		temp[p] = c;
		j = Push(temp);
		if (j != 0)
		{
			if (SUM == 6)
			{
				j = 2;
			}
			V[SUM].parent = i;
			V[SUM].command = 'd';
			strcpy(Q[QH++][0], temp);
		}
	}
	return 0;
}
int BFS()
{
	int i;
	char temp[19];
	for (i = 0; i <= MAXN; i++)
	{
		V[i].colour = 0;
	}
	QH = QT = 0;
	Push("123456789");
	QH++;
	while (!IsEmpty())
	{
		strcpy(temp, Pop());
		GENPUSH(temp);
	}
	return 0;
}
void Cal(int sum)
{
	if (V[sum].colour == 0)
	{
		printf("unsolvable\n");
		return;
	}
	while (sum != 1)
	{
		printf("%c", V[sum].command);
		sum = V[sum].parent;
	}
	putchar('\n');
}
int main()
{
	int kase, i, m;
	char input[100];
	Gen();
	BFS();
	gets(input);
	sscanf(input, "%d", &kase);
	gets(input);
	while (kase--)
	{
		gets(input);
		for (i = 0, m = 0; input[i]; i++)
		{
			if (input[i] != ' ' && input[i] != 'x')
			{
				Board[m++] = input[i];
			}
			else if (input[i] == 'x')
			{
				Board[m++] = '9';
			}
		}
		Board[m] = NULL;
		Isvisit(Board, 1);
		Cal(SUM);
		if (kase)
		{
			gets(input);
			putchar('\n');
		}
	}
	return 0;
}
