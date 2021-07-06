#include <bits/stdc++.h>

using namespace std;

const char fail[] = "is not an integer with less than 100 digits.";

int B[1000], S[1000], T[1000], lb, ls, lt;// B is t^b, S is sol

void mult(int M1[1000], int *l1, int M2[1000], int *l2)
{
	lt = *l1 + *l2 - 1;
	for (int i = 0; i < 1000; i++)
	{
		T[i] = 0;
	}
	for (int i = 0; i < *l1; i++)
	{
		for (int j = 0; j < *l2; j++)
		{
			T[i + j] += M1[i] * M2[j];
		}
	}
	for (int i = 0; i < lt; i++)
	{
		T[i + 1] += T[i] / 10;
		T[i] %= 10;
	}
	if (T[lt])
	{
		lt++;
	}
	for (int i = M1[lt] = 0; i < lt; i++)
	{
		M1[i] = T[i];
	}
	*l1 = lt;
}

int main()
{
	int t, a, b, m;
	while (scanf("%d%d%d", &t, &a, &b) == 3)
	{
		printf("(%d^%d-1)/(%d^%d-1) ", t, a, t, b);
		if (t == 1)
		{
			printf("%s\n", fail);
			continue;
		}
		if (t == 2 && b == 1)
		{
			if (a * log(2.0) / log(10.0) > 100.0)
			{
				printf("%s\n", fail);
				continue;
			}
			for (int i = 0; i < 1000; i++)
			{
				B[i] = S[i] = 0;
			}
			lb = ls = 1;
			S[0] = 2;
			for (B[0] = 1; a; a >>= 1)
			{
				if (ls > 100)
				{
					lb = 1000;
					break;
				}
				if (a & 1)
				{
					mult(B, &lb, S, &ls);
				}
				mult(S, &ls, S, &ls);
				if (lb > 100)
				{
					break;
				}
			}
			if (lb > 100)
			{
				printf("%s\n", fail);
				continue;
			}
			B[0]--;
			for (int i = lb - 1; i >= 0; i--)
			{
				printf("%d", B[i]);
			}
			printf("\n");
			continue;
		}
		m = a / b;
		if (a != m * b)
		{
			printf("%s\n", fail);
			continue;
		}
		if ((a - b) * log((double)t) / log(10.0) > 100.0)
		{
			printf("%s\n", fail);
			continue;
		}
		if (a == b)
		{
			printf("1\n");
			continue;
		}
		for (int i = 0; i < 1000; i++)
		{
			B[i] = S[i] = 0;
		}
		lb = 1;
		for (ls = 0; t; ls++, t /= 10)
		{
			S[ls] = t % 10;
		}
		for (B[0] = 1; b; b >>= 1)
		{
			if (ls > 100)
			{
				lb = 1000;
				break;
			}
			if (b & 1)
			{
				mult(B, &lb, S, &ls);
			}
			mult(S, &ls, S, &ls);
			if (lb > 100)
			{
				break;
			}
		}
		if (lb > 100)
		{
			printf("%s\n", fail);
			continue;
		}
		for (int i = 0; i < 1000; i++)
		{
			S[i] = 0;
		}
		ls = 1;
		for (int i = 0; i < m; i++)
		{
			// S=S*B+1
			if (ls != 1 || S[0])
			{
				mult(S, &ls, B, &lb);
			}
			S[0]++;
			for (int j = S[ls] = 0; j < ls; j++)
			{
				S[j + 1] += S[j] / 10;
				S[j] %= 10;
			}
			if (S[ls])
			{
				ls++;
			}
			if (ls > 100)
			{
				break;
			}
		}
		if (ls > 100)
		{
			printf("%s\n", fail);
			continue;
		}
		for (int i = ls - 1; i >= 0; i--)
		{
			printf("%d", S[i]);
		}
		printf("\n");
	}
	return 0;
}
