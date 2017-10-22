#include <bits/stdc++.h>

using namespace std;

#define MAXP 100000
char A[MAXP + 10];

int main()
{
	int p;
	while (scanf("%d", &p), p)
	{
		if (p == 2)
		{
			printf("Impossible\n");
			continue;
		}
		memset(A, '1', sizeof(A));
		for (unsigned long long i = 1; i < p; i++)
		{
			A[(i * i) % p] = '0';
		}
		for (int i = 1; i < p; i++)
		{
			printf("%c", A[i]);
		}
		printf("\n");
	}
}
