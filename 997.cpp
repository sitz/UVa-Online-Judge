#include <bits/stdc++.h>

using namespace std;

char S[50];
int N[50], V1[60], V2[60];
int main()
{
	int n, term, i, j;
	while (scanf("[%d%c", N, S) == 2)
	{
		for (n = 1; S[n - 1] != ']'; n++)
		{
			scanf("[%d%c", N + n, S + n);
		}
		for (i = 1; i < n; i++)
		{
			scanf("%c", S + n);
		}
		scanf("%d", &term);
		getchar();
		for (i = 0; i < term; i++)
		{
			V1[i] = N[n - 1];
		}
		for (i = n - 2; i >= 0; i--)
		{
			for (j = 0; j < term; j++)
			{
				V2[j] = V1[j];
			}
			if (S[i] == '+')
			{
				V1[0] = N[i];
				for (j = 1; j < term; j++)
				{
					V1[j] = V1[j - 1] + V2[j - 1];
				}
			}
			else
			{
				V1[0] = N[i] * V2[0];
				for (j = 1; j < term; j++)
				{
					V1[j] = V1[j - 1] * V2[j];
				}
			}
		}
		printf("%d", V1[0]);
		for (i = 1; i < term; i++)
		{
			printf(" %d", V1[i]);
		}
		printf("\n");
	}
	return 0;
}
