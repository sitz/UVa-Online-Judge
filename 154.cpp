#include <bits/stdc++.h>

using namespace std;

char str[1000];
char Bin[] = "roygb";
int A[101][130], N;
int C[101];

void Set(int n)
{
	int i, j, d;
	for (i = 2; str[i]; i += 4)
	{
		j = str[i - 2];
		d = str[i];
		A[n][j] = d;
	}
}

void Cal()
{
	int i, j, c, k, d;
	int min = 21474836;
	for (i = 0; i < N - 1; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			c = 0;
			for (k = 0; Bin[k]; k++)
			{
				d = Bin[k];
				if (A[i][d] != A[j][d])
				{
					c++;
				}
			}
			C[i] += c;
			C[j] += c;
		}
	}
	for (i = 0; i < N; i++)
	{
		if (C[i] < min)
		{
			min = C[i];
			k = i;
		}
	}
	printf("%d\n", k + 1);
}

int main()
{
	while (gets(str) && strcmp(str, "#"))
	{
		N = 0;
		Set(N++);
		while (1)
		{
			gets(str);
			if (str[0] == 'e')
			{
				break;
			}
			Set(N++);
		}
		Cal();
		for (int i = 0; i < N; i++)
		{
			C[i] = 0;
		}
	}
	return 0;
}
