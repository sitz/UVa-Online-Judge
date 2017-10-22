#include <bits/stdc++.h>

using namespace std;

/**
300
**/
char X[20][10] = {"imix", "ik", "akbal", "kan", "chicchan",
									"cimi", "manik", "lamat", "muluk", "ok",
									"chuen", "eb", "ben", "ix", "mem", "cib",
									"caban", "eznab", "canac", "ahau"};
int ResolveMonth(char P[100])
{
	char X[19][10] = {"pop", "no", "zip", "zotz", "tzec", "xul",
										"yoxkin", "mol", "chen", "yax", "zac", "ceh",
										"mac", "kankin", "muan", "pax", "koyab", "cumhu",
										"uayet"};
	int i;
	for (i = 0; i < 19; i++)
	{
		if (strcmp(P, X[i]) == 0)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	int N, n, d, y;
	char M[100];
	scanf("%d", &N);
	printf("%d\n", N);
	for (n = 0; n < N; n++)
	{
		scanf("%d.%s%d", &d, &M, &y);
		d += ResolveMonth(M) * 20 + y * 365;
		y = d / 260;
		d %= 260;
		strcpy(M, X[d % 20]);
		d %= 13;
		d++;
		printf("%d %s %d\n", d, M, y);
	}
	return 0;
}
