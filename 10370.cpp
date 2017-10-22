#include <bits/stdc++.h>

using namespace std;

int main()
{
	int test_case, N, a[1001], i, j;
	int sum;
	float av, p;
	scanf("%d", &test_case);
	for (i = 0; i < test_case; i++)
	{
		sum = 0;
		p = 0;
		scanf("%d", &N);
		for (j = 0; j < N; j++)
		{
			scanf("%d", &a[j]);
		}
		for (j = 0; j < N; j++)
		{
			sum += a[j];
		}
		av = sum / N;
		for (j = 0; j < N; j++)
		{
			if (a[j] > av)
			{
				p++;
			}
		}
		printf("%.3f%\n", (p * 100) / N);
	}
	return 0;
}
