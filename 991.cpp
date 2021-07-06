#include <bits/stdc++.h>

using namespace std;

/*
  Name:  UVA 991
  Author: zoom
  Date: 22/07/11
*/

#define LLU long long unsigned int
#define LLD long long double
#define FOR(i, N) for (int i = 0; i < (N); i++)
int ANS[11], j, k, first = 0;
int main()
{
	ANS[0] = 1;
	ANS[1] = 1;
	ANS[2] = 2;
	for (int i = 3; i < 11; i++)
	{
		ANS[i] = 0;
		j = 0, k = i - 1;
		while (j < i)
		{
			ANS[i] += ANS[j] * ANS[k];
			j++, k--;
		}
	}
	while (scanf("%d", &j) != EOF)
	{
		if (first)
		{
			printf("\n");
		}
		else
		{
			first = true;
		}
		printf("%d\n", ANS[j]);
	}
	return 0;
}
