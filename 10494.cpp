#include <bits/stdc++.h>

using namespace std;

/*******************************
TITLE : IF WE WERE A CHILD AGAIN
   NO : 10494
********************************/
#define MAXN 10000
/*100000  */
char SIGN[5], NUM[MAXN], DEN[15];
long K;
int DIVISION()
{
	long long i, j, n, g, l;
	l = strlen(NUM);
	i = 0;
	n = NUM[i] - '0';
	i++;
	while (n < K && NUM[i])
	{
		n = n * 10 + NUM[i] - '0';
		i++;
	}
	if (n < K)
	{
		printf("0");
		return 0;
	}
	if (i >= l)
	{
		printf("%lld", n / K);
		return 0;
	}
	while (1)
	{
		printf("%lld", n / K);
		if (i >= l)
		{
			break;
		}
		g = n % K;
		n = g * 10 + NUM[i] - '0';
		i++;
	}
	return 0;
}
int MOD()
{
	long i, j, k, l;
	i = 0;
	j = 0;
	while (NUM[i])
	{
		k = j * 10 + NUM[i] - '0';
		j = k % K;
		i++;
	}
	printf("%ld", j);
	return 0;
}
int main()
{
	while (scanf("%s%s%s", NUM, SIGN, DEN) != EOF)
	{
		sscanf(DEN, "%ld", &K);
		if (!strcmp(SIGN, "/"))
		{
			DIVISION();
		}
		else
		{
			MOD();
		}
		putchar('\n');
	}
	return 0;
}
