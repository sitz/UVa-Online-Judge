#include <bits/stdc++.h>

using namespace std;

int N[128];
char S[128];
int main()
{
	int first = 1, i, j, k, p;
	while (scanf("%s", S) == 1)
	{
		memset(N, 0, sizeof(N));
		for (i = 0, j = strlen(S) - 1; j >= 0; i++, j--)
		{
			N[i] = S[j] - '0';
		}
		scanf("%s", S);
		for (i = 0, j = strlen(S) - 1; j >= 0; i++, j--)
		{
			N[i] += S[j] - '0';
		}
		for (p = 0; p < 128;)
		{
			if (p < 0)
			{
				p = 0;
			}
			switch (N[p])
			{
			case 0:
				p++;
				break;
			case 1:
				if (N[p + 1])
				{
					N[p]--, N[p + 1]--, N[p + 2]++;
				}
				p++;
				break;
			default:
				if (p == 0)
				{
					N[0] -= 2, N[1]++;
				}
				else if (p == 1)
				{
					N[0]++, N[1] -= 2, N[2]++, p = 0;
				}
				else
				{
					N[p + 1]++, N[p] -= 2, N[p - 2]++, p -= 3;
				}
				break;
			}
		}
		for (p = 127; p >= 0; p--)
		{
			if (N[p])
			{
				break;
			}
		}
		if (first)
		{
			first = 0;
		}
		else
		{
			printf("\n");
		}
		if (p >= 0)
		{
			for (i = p; i >= 0; i--)
			{
				printf("%d", N[i]);
			}
			printf("\n");
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}
