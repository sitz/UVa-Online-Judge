#include <bits/stdc++.h>

using namespace std;

/*
Spam or Not Spam
10476
*/
#define MIN(a, b) (a > b ? b : a)
#define MAX(a, b) (a > b ? a : b)
#define MAXN 884738
int F_SP[MAXN], F_NON[MAXN], F_MS[MAXN];
char Text[1002];
int Max_sp, Max_non, Max_ms;
int min_sp, min_non, min_ms;
int Sp, Non, Ms;
double Sm1, Sm2;
int Val(int a, int b, int c)
{
	int p;
	p = a * 96 * 96 + b * 96 + c;
	return p;
}
void Similarity_1()
{
	int i, tf = 0, t1f = 0, t2f = 0;
	int max = MAX(Max_ms, Max_sp);
	int min = MIN(min_ms, min_sp);
	for (i = min; i <= max; i++)
	{
		tf += F_MS[i] * F_SP[i];
		t1f += F_SP[i] * F_SP[i];
		t2f += F_MS[i] * F_MS[i];
	}
	if (tf == 0 || t1f == 0 || t2f == 0)
	{
		Sm1 = 0.00000;
	}
	else
	{
		Sm1 = (double)tf / (sqrt((double)t1f) * sqrt((double)t2f));
	}
	printf("%.5lf", Sm1);
}
void Similarity_2()
{
	int i, tf = 0, t1f = 0, t2f = 0;
	int max = MAX(Max_ms, Max_non);
	int min = MIN(min_ms, min_non);
	for (i = min; i <= max; i++)
	{
		tf += F_MS[i] * F_NON[i];
		t1f += F_NON[i] * F_NON[i];
		t2f += F_MS[i] * F_MS[i];
	}
	if (tf == 0 || t1f == 0 || t2f == 0)
	{
		Sm2 = 0.00000;
	}
	else
	{
		Sm2 = (double)tf / (sqrt((double)t1f) * sqrt((double)t2f));
	}
	printf(" %.5lf\n", Sm2);
}
void ReadSp()
{
	int i, j = 0, l;
	int p;
	Max_sp = 0;
	min_sp = 21474836;
	while (j < Sp)
	{
		gets(Text);
		if (!strcmp(Text, "ENDMESSAGE"))
		{
			j++;
		}
		else
		{
			l = strlen(Text);
			if (l < 3)
			{
				continue;
			}
			Text[l] = NULL;
			for (i = 0; i < l - 2; i++)
			{
				p = Val(Text[i] - 32, Text[i + 1] - 32, Text[i + 2] - 32);
				F_SP[p]++;
				if (p > Max_sp)
				{
					Max_sp = p;
				}
				if (p < min_sp)
				{
					min_sp = p;
				}
			}
		}
	}
}
void ReadNon()
{
	int i, j = 0, l;
	int p;
	Max_non = 0;
	min_non = 21474836;
	while (j < Non)
	{
		gets(Text);
		if (!strcmp(Text, "ENDMESSAGE"))
		{
			j++;
		}
		else
		{
			l = strlen(Text);
			if (l < 3)
			{
				continue;
			}
			Text[l] = NULL;
			for (i = 0; i < l - 2; i++)
			{
				p = Val(Text[i] - 32, Text[i + 1] - 32, Text[i + 2] - 32);
				F_NON[p]++;
				if (p > Max_non)
				{
					Max_non = p;
				}
				if (p < min_non)
				{
					min_non = p;
				}
			}
		}
	}
}
void ReadMs()
{
	int i, j = 0, l;
	int p, max, min;
	Max_ms = 0;
	min_ms = 21474836;
	while (j < Ms)
	{
		gets(Text);
		if (!strcmp(Text, "ENDMESSAGE"))
		{
			j++;
			Similarity_1();
			Similarity_2();
			if (Sm1 > Sm2)
			{
				printf("spam\n");
			}
			else
			{
				printf("non-spam\n");
			}
			for (i = min_ms; i <= Max_ms; i++)
			{
				F_MS[i] = 0;
			}
		}
		else
		{
			l = strlen(Text);
			if (l < 3)
			{
				continue;
			}
			Text[l] = NULL;
			for (i = 0; i < l - 2; i++)
			{
				p = Val(Text[i] - 32, Text[i + 1] - 32, Text[i + 2] - 32);
				F_MS[p]++;
				if (p > Max_ms)
				{
					Max_ms = p;
				}
				if (p < min_ms)
				{
					min_ms = p;
				}
			}
		}
	}
	max = MAX(Max_sp, Max_non);
	min = MIN(min_sp, min_non);
	for (i = min; i <= max; i++)
	{
		F_SP[i] = F_NON[i] = 0;
	}
}
int main()
{
	char input[100];
	int Set = 1;
	while (gets(input))
	{
		sscanf(input, "%d%d%d", &Sp, &Non, &Ms);
		if (!Sp && !Non && !Ms)
		{
			break;
		}
		ReadSp();
		ReadNon();
		printf("Set %d:\n", Set++);
		ReadMs();
	}
	return 0;
}
