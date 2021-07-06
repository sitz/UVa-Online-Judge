#include <bits/stdc++.h>

using namespace std;

int R[60] = {1}, I[60] = {0}, N[60], ptr;
int main()
{
	int i, t, tt, a, b, ta, tb, m;
	for (i = 1; i < 60; i++)
	{
		R[i] = -R[i - 1] - I[i - 1];
		I[i] = R[i - 1] - I[i - 1];
	}
	scanf("%d", &tt);
	for (t = 1; t <= tt; t++)
	{
		scanf("%d%d", &a, &b);
		printf("Case #%d: ", t);
		if ((a | b) == 0)
		{
			printf("0\n");
			continue;
		}
		for (ptr = 0; a | b;)
		{
			m = (1 << (ptr / 2 + 1));
			if (a % m == 0 && b % m == 0)
			{
				N[ptr++] = 0;
				N[ptr++] = 0;
			}
			else if ((a - R[ptr]) % m == 0 && (b - I[ptr]) % m == 0)
			{
				a = a - R[ptr];
				b = b - I[ptr];
				N[ptr++] = 1;
				N[ptr++] = 0;
			}
			else if ((a - R[ptr + 1]) % m == 0 && (b - I[ptr + 1]) % m == 0)
			{
				a = a - R[ptr + 1];
				b = b - I[ptr + 1];
				N[ptr++] = 0;
				N[ptr++] = 1;
			}
			else
			{
				a = a - R[ptr] - R[ptr + 1];
				b = b - I[ptr] - I[ptr + 1];
				N[ptr++] = 1;
				N[ptr++] = 1;
			}
		}
		if (N[ptr - 1] == 0)
		{
			ptr--;
		}
		for (i = ptr - 1; i >= 0; i--)
		{
			printf("%d", N[i]);
		}
		printf("\n");
	}
	return 0;
}
