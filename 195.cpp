#include <bits/stdc++.h>

using namespace std;

char ALPHA[] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
int POS[200];
int VALUE[200];
char STR[500];

int sort_function(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

void INTERCHANGE(int m, int n)
{
	int c;
	c = VALUE[m];
	VALUE[m] = VALUE[n];
	VALUE[n] = c;
}

void GETVALUE()
{
	int i, j;
	for (i = 0; STR[i]; i++)
	{
		j = STR[i];
		VALUE[i] = POS[j];
	}
}

void FIXED()
{
	int i, j;
	for (i = 0; ALPHA[i]; i++)
	{
		j = ALPHA[i];
		POS[j] = i;
	}
}

int main()
{
	int i, n, c, m, p, N, M, kase, j, Q;
	FIXED();
	scanf("%d", &kase);
	while (kase--)
	{
		scanf("%s", STR);
		GETVALUE();
		n = strlen(STR) - 1;
		qsort((void *)VALUE, n + 1, sizeof(int), sort_function);
		for (i = 0; STR[i]; i++)
		{
			Q = VALUE[i];
			printf("%c", ALPHA[Q]);
		}
		printf("\n");
		while (1)
		{
			c = 0;
			for (i = n; i >= 1; i--)
			{
				if (VALUE[i] > VALUE[i - 1])
				{
					c = 1;
					break;
				}
			}
			if (c == 0)
			{
				break;
			}
			m = i - 1;
			for (i = n; VALUE[i] <= VALUE[m]; i--)
				;
			p = i;
			INTERCHANGE(m, p);
			N = n;
			M = m + 1;
			while (N > M)
			{
				INTERCHANGE(N, M);
				N--;
				M++;
			}
			for (j = 0; STR[j]; j++)
			{
				Q = VALUE[j];
				printf("%c", ALPHA[Q]);
			}
			printf("\n");
		}
	}
	return 0;
}
