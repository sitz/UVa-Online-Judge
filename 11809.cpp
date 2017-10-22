#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6

int main()
{
	char array[100];
	long long unsigned M, E, y, i;
	double x, A, diff;
	while (scanf("%s", array) != EOF)
	{
		for (i = 0; array[i]; i++)
		{
			if ((array[i] >= 'a' && array[i] <= 'z') || (array[i] >= 'A' && array[i] <= 'Z'))
			{
				array[i] = ' ';
				break;
			}
		}
		sscanf(array, "%lf%llu", &x, &y);
		if (fabs(x) > -EPS && fabs(x) < EPS && y == 0)
		{
			break;
		}
		A = log(x) + y * log(10);
		for (M = 0; M < 10; M++)
		{
			E = (long long unsigned)(log(M + 2 + (A - log(pow(2, M + 1) - 1)) / log(2)) / log(2) + 0.5);
			diff = A - (pow(2, E) - M - 2) * log(2) - log(pow(2, M + 1) - 1);
			if (diff > -EPS && diff < EPS)
			{
				break;
			}
		}
		printf("%llu %llu\n", M, E);
	}
	return 0;
}
