#include <bits/stdc++.h>

using namespace std;

/*******************
Polly the Polymonial
      498
********************/
#define MAX 10000
char C[MAX];
char X[MAX];
double CON[1000];
double V[1000];
int K, N;
void SEPA()
{
	int i, j = 0, c;
	char temp[15];
	K = 0;
	N = 0;
	c = 0;
	for (i = 0; C[i];)
	{
		if (C[i] != ' ')
		{
			temp[j++] = C[i++];
			c = 1;
		}
		else if (c)
		{
			temp[j] = NULL;
			CON[K++] = atof(temp);
			j = 0;
			for (i++; C[i] == ' ' && C[i]; i++)
				;
			c = 0;
		}
		else
		{
			i++;
		}
	}
	if (c)
	{
		temp[j] = NULL;
		CON[K++] = atof(temp);
	}
	j = 0;
	c = 0;
	for (i = 0; X[i];)
	{
		if (X[i] != ' ')
		{
			temp[j++] = X[i++];
			c = 1;
		}
		else if (c)
		{
			temp[j] = NULL;
			V[N++] = atof(temp);
			j = 0;
			for (i++; X[i] == ' ' && X[i]; i++)
				;
			c = 0;
		}
		else
		{
			i++;
		}
	}
	if (c)
	{
		temp[j] = NULL;
		V[N++] = atof(temp);
	}
}
double EVU(double v)
{
	int i;
	double val = 0;
	for (i = 0; i < K; i++)
	{
		val *= v;
		val += CON[i];
	}
	return val;
}
void CAL()
{
	int i;
	double VAL;
	for (i = 0; i < N; i++)
	{
		VAL = EVU(V[i]);
		printf("%.0lf", VAL);
		if (i < N - 1)
		{
			printf(" ");
		}
	}
}
int main()
{
	while (gets(C))
	{
		gets(X);
		SEPA();
		CAL();
		putchar('\n');
	}
	return 0;
}
