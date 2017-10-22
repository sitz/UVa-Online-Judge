#include <bits/stdc++.h>

using namespace std;

int main()
{
	long int N;
	while (scanf("%ld", &N) && N > 0)
	{
		if (N == 1)
		{
			printf("0%%\n");
		}
		else
		{
			printf("%ld%%\n", 25 * N);
		}
	}
}
