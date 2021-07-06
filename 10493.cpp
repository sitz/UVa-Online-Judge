#include <bits/stdc++.h>

using namespace std;

/*******************************
TITLE : CATS WITH OR WITHOUT HATS
NO : 10493
********************************/
int N, M, T;
int solvecase()
{
	if (N == 1 && M == 1)
	{
		printf(" Multiple\n");
		return 0;
	}
	if (M > 1 && N <= 1)
	{
		printf(" Impossible\n");
		return 0;
	}
	//if(N>M)            { printf(" Impossible\n"); return 0; }
	if ((M - 1) % (N - 1))
	{
		printf(" Impossible\n");
		return 0;
	}
	printf(" %d\n", M + (M - 1) / (N - 1));
	return 0;
}
int main()
{
	while (1)
	{
		scanf("%d%d", &N, &M);
		if (N == 0)
		{
			break;
		}
		printf("%d %d", N, M);
		solvecase();
	}
	return 0;
}
