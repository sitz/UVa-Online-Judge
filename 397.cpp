#include <bits/stdc++.h>

using namespace std;

char input[400], Vary[10], op;
struct ss
{
	int opd;
	char opt;
} Eq[25];

void GetOperand(char dummy[], int len)
{
	int i = 0, j = 0, k = 0;
	char xx[15];
	op = 0;
	for (j = 0; !isdigit(dummy[j]); j++)
		;
	while (j < len)
	{
		for (i = j; i < len && isdigit(dummy[i]); i++)
			xx[k++] = dummy[i];
		xx[k] = NULL;
		Eq[op++].opd = atoi(xx);
		k = 0;
		for (j = i; j < len && !isdigit(dummy[j]); j++)
			;
	}
}
void GetOperator(char dummy[], int len)
{
	int i, j = 1, k = 0;
	if (!isdigit(dummy[0]))
		if (dummy[0] == '-')
			Eq[0].opd *= -1;
	for (i = 1; i < len; i++)
		if (!isdigit(dummy[i]))
			if (isdigit(dummy[i - 1]))
				Eq[k++].opt = dummy[i];
			else if (dummy[i] == '-')
				Eq[k].opd *= -1;
}
void Sep()
{
	char temp[400];
	int i, len = 0, k = 0;
	for (i = 0; input[i]; i++)
		if (input[i] != ' ')
			temp[len++] = input[i];
	temp[len] = NULL;
	for (i = len - 1; temp[i] != '='; i--)
		;
	for (i = i + 1; temp[i]; i++)
		Vary[k++] = temp[i];
	Vary[k] = NULL;
	GetOperand(temp, len);
	GetOperator(temp, len);
}
void Print()
{
	int i;
	if (op == 1)
	{
		printf("%d = %s\n", Eq[0].opd, Vary);
		return;
	}
	printf("%d ", Eq[0].opd);
	for (i = 0; i + 1 < op; i++)
		printf("%c %d ", Eq[i].opt, Eq[i + 1].opd);
	printf("= %s\n", Vary);
}
int DivMult()
{
	int i, j;
	for (i = 0; i + 1 < op; i++)
	{
		if (Eq[i].opt == '*' || Eq[i].opt == '/')
		{
			if (Eq[i].opt == '*')
				Eq[i].opd = Eq[i].opd * Eq[i + 1].opd;
			else
				Eq[i].opd = Eq[i].opd / Eq[i + 1].opd;
			for (j = i + 1; j + 1 < op; j++)
				Eq[j].opd = Eq[j + 1].opd;
			for (j = i; j + 2 < op; j++)
				Eq[j].opt = Eq[j + 1].opt;
			op--;
			Print();
			return 1;
		}
	}
	return 0;
}
int AddSub()
{
	int i, j;
	for (i = 0; i + 1 < op; i++)
	{
		if (Eq[i].opt == '+' || Eq[i].opt == '-')
		{
			if (Eq[i].opt == '+')
				Eq[i].opd = Eq[i].opd + Eq[i + 1].opd;
			else
				Eq[i].opd = Eq[i].opd - Eq[i + 1].opd;
			for (j = i + 1; j + 1 < op; j++)
				Eq[j].opd = Eq[j + 1].opd;
			for (j = i; j + 2 < op; j++)
				Eq[j].opt = Eq[j + 1].opt;
			op--;
			Print();
			return 1;
		}
	}
	return 0;
}
void Cal()
{
	int d;
	Print();
	while (op > 1)
	{
		d = DivMult();
		if (!d)
			AddSub();
	}
}

int main()
{
	int k = 0;
	while (gets(input))
	{
		if (k++)
		{
			putchar('\n');
		}
		Sep();
		Cal();
	}
	return 0;
}
