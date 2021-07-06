#include <bits/stdc++.h>

using namespace std;

/*
camel trading
10700
*/
typedef long long INT;
char expr[100], Op[25];
INT Val[30], tval, top;
void GetVal()
{
	tval = 0;
	char *p;
	p = strtok(expr, "+*");
	while (p)
	{
		Val[tval++] = atoi(p);
		p = strtok(NULL, "+*");
	}
}
void GenOp()
{
	INT i;
	top = 0;
	for (i = 0; expr[i]; i++)
	{
		if (expr[i] == '+' || expr[i] == '*')
		{
			Op[top++] = expr[i];
		}
	}
}
void Max()
{
	INT i, j = 0, temp = 1, sum;
	while (j < tval)
	{
		sum = Val[j];
		for (i = j; i + 1 < tval; i++)
		{
			if (Op[i] == '+')
			{
				sum += Val[i + 1];
			}
			else
			{
				break;
			}
		}
		temp *= sum;
		j = i + 1;
	}
	printf(" %lld", temp);
}
void Min()
{
	INT i, j = 0, temp = 0, sum;
	while (j < tval)
	{
		sum = Val[j];
		for (i = j; i + 1 < tval; i++)
		{
			if (Op[i] == '*')
			{
				sum *= Val[i + 1];
			}
			else
			{
				break;
			}
		}
		temp += sum;
		j = i + 1;
	}
	printf(" and %lld.\n", temp);
}
void Cal()
{
	GenOp();
	GetVal();
	printf("The maximum and minimum are");
	Max();
	Min();
}
int main()
{
	INT kase;
	scanf("%lld", &kase);
	while (kase--)
	{
		scanf("%s", expr);
		Cal();
	}
	return 0;
}
