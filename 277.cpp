#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000

char Rec[70], code[5], stname[17], Ex[27], Pri[10], des[17], F[MAXN], Stn[MAXN][17];
int fn, fe, fu;

int ReadCase()
{
	int i;
	while (gets(Rec))
	{
		for (i = 0; Rec[i]; i++)
		{
			if (Rec[i] == '\n')
			{
				Rec[i] = '\0';
			}
		}
		if (strlen(Rec) == 0)
		{
			return 0;
		}
		return 1;
	}
	return 0;
}
void Sep()
{
	int i, j, k = 0, co, l;
	char temp[30];
	fn = fu = fe = 0;
	l = strlen(Rec);
	for (i = 0; Rec[i] != ',' && i < l; i++)
	{
		temp[k++] = Rec[i];
	}
	temp[k] = '\0';
	co = atoi(temp);
	sprintf(code, "%03d", co);
	k = 0;
	for (j = i + 1; Rec[j] != ',' && j < l; j++)
	{
		stname[k++] = Rec[j];
	}
	if (k > 0)
	{
		fn = 1;
	}
	stname[k] = '\0';
	if (F[co] == 0)
	{
		F[co] = 1;
		if (fn)
		{
			strcpy(Stn[co], stname);
		}
		else
		{
			strcpy(Stn[co], ",,,");
		}
	}
	k = 0;
	for (i = j + 1; Rec[i] != ',' && i < l; i++)
	{
		des[k++] = Rec[i];
	}
	des[k] = '\0';
	k = 0;
	for (j = i + 1; Rec[j] != ',' && j < l; j++)
	{
		Ex[k++] = Rec[j];
	}
	Ex[k] = '\0';
	if (k > 0)
	{
		fe = 1;
	}
	k = 0;
	for (i = j + 1; Rec[i] != ',' && i < l; i++)
	{
		Pri[k++] = Rec[i];
	}
	Pri[k] = '\0';
	if (k > 0)
	{
		fu = 1;
	}
}
void SolvedCase()
{
	char iid[100], ides[100];
	double price = 0;
	int co = atoi(code);
	strcpy(iid, code);
	strcat(iid, des);
	if (strlen(iid) > 13)
	{
		return;
	}
	if (fn == 0)
	{
		if (F[co] == 1)
		{
			if (!strcmp(Stn[co], ",,,"))
			{
				return;
			}
			else
			{
				strcpy(ides, Stn[co]);
			}
		}
		else
		{
			return;
		}
	}
	else
	{
		strcpy(ides, stname);
	}
	if (fe)
	{
		strcat(ides, "-");
		strcat(ides, Ex);
	}
	ides[30] = '\0';
	if (fu)
	{
		price = atof(Pri);
	}
	printf("%s,%s,%.2lf\n", iid, ides, price / 100);
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
		printf("Item Id,Item Desc,Item Price\n");
		while (ReadCase())
		{
			Sep();
			SolvedCase();
		}
		if (kase)
		{
			putchar('\n');
			for (int i = 0; i < MAXN; i++)
			{
				F[i] = 0;
			}
		}
	}
	return 0;
}
