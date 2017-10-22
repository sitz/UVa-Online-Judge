#include <bits/stdc++.h>

using namespace std;

char B[6][1000], L[32768], E[250] = "0123456789+-*/";
char C[6][60] = {"000 .0. 000 000 0.0 000 0.. 000 000 000 .0. ... 0.0 .0. ",
								 "0.0 .0. ..0 ..0 0.0 0.. 0.. ..0 0.0 0.0 .0. ... 0.0 ... ",
								 "0.0 .0. 000 000 000 000 000 ..0 000 000 000 000 .0. 000 ",
								 "0.0 .0. 0.. ..0 ..0 ..0 0.0 ..0 0.0 ..0 .0. ... 0.0 ... ",
								 "000 .0. 000 000 ..0 000 000 ..0 000 ..0 .0. ... 0.0 .0. ",
								 ""};
int S[100], ptr;
int main()
{
	int i, j, k, hash, n, len;
	len = strlen(C[0]);
	for (n = 0; n < len; n += 4)
	{
		for (i = hash = 0; i < 5; i++)
		{
			for (j = 0; j < 3; j++)
			{
				hash <<= 1;
				if (C[i][n + j] == '0')
				{
					hash |= 1;
				}
			}
		}
		L[hash] = E[n >> 2];
	}
	while (1)
	{
		for (i = 0; i < 6; i++)
		{
			gets(B[i]);
		}
		len = strlen(B[0]);
		for (n = 0; n < len; n += 4)
		{
			for (i = hash = 0; i < 5; i++)
			{
				for (j = 0; j < 3; j++)
				{
					hash <<= 1;
					if (B[i][n + j] == '0')
					{
						hash |= 1;
					}
				}
			}
			E[n >> 2] = L[hash];
		}
		n >>= 2;
		E[n] = '\0';
		if (strcmp(E, "0") == 0)
		{
			break;
		}
		S[0] = 0;
		for (i = ptr = 0; E[i]; i++)
		{
			switch (E[i])
			{
			case '+':
				S[++ptr] = -1, S[++ptr] = 0;
				break;
			case '-':
				S[++ptr] = -2, S[++ptr] = 0;
				break;
			case '*':
				S[++ptr] = -3, S[++ptr] = 0;
				break;
			case '/':
				S[++ptr] = -4, S[++ptr] = 0;
				break;
			default:
				S[ptr] = 10 * S[ptr] + E[i] - '0';
				break;
			}
		}
		for (i = 0, j = 1; j < ptr; j += 2)
		{
			switch (S[j])
			{
			case -3:
				S[i] *= S[j + 1];
				break;
			case -4:
				S[i] /= S[j + 1];
				break;
			default:
				S[++i] = S[j], S[++i] = S[j + 1];
				break;
			}
		}
		for (j = 1; j < i; j += 2)
		{
			if (S[j] == -1)
			{
				S[0] += S[j + 1];
			}
			else
			{
				S[0] -= S[j + 1];
			}
		}
		sprintf(E, "%d", S[0]);
		for (ptr = 0; E[ptr]; ptr++)
		{
			if (E[ptr] == '-')
			{
				k = 44;
			}
			else
			{
				k = (E[ptr] - '0') * 4;
			}
			for (i = 0; i < 5; i++)
			{
				for (j = 0; j < 4; j++)
				{
					B[i][ptr * 4 + j] = C[i][k + j];
				}
			}
		}
		for (i = 0; i < 5; i++)
		{
			B[i][4 * ptr - 1] = '\0';
			printf("%s\n", B[i]);
		}
		printf("\n");
	}
	return 0;
}
