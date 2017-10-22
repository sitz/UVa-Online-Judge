#include <bits/stdc++.h>

using namespace std;

// O(n + MAX^4)

const int MAX = 10;// maximum number of quarters in one direction

int nr[MAX][MAX];		// number of houses in each quarter
double ll[MAX][MAX];// sum of the distances of all houses in a quarter to its lower left corner

double doit()
{
	double sum = 0.0;// total length of all admissible paths
	long long n2 = 0;// total number of admissible paths, must be > 32 bits
	// iterate over all pairs of quarters
	for (int i = 1; i < MAX; ++i)
	{
		for (int j = 1; j < MAX; ++j)
		{
			for (int k = 0; k < i; ++k)
			{
				for (int l = 0; l < j; ++l)
				{
					// compute the total length of all admissible paths
					// between quarters i,j and k,l in two steps:
					// first, the parts which run inside each quarter
					sum += ll[i][j] * nr[k][l] - ll[k][l] * nr[i][j];
					// then, the parts which run between the two quarters
					sum += (double)(i - k + j - l) * nr[i][j] * nr[k][l];
					// finally, update the number of admissible paths
					n2 += (long long)nr[i][j] * nr[k][l];
				}
			}
		}
	}
	return sum / n2;
}

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		memset(nr, 0, sizeof nr);
		memset(ll, 0, sizeof ll);
		while (n-- > 0)
		{
			double x, y;
			scanf("%lf%lf", &x, &y);
			int u = floor(x), v = floor(y);
			++nr[u][v];
			// only save the Manhattan distance to lower left corner of quarter:
			ll[u][v] += x - u + y - v;
		}
		printf("%.8f\n", doit());
	}
	return 0;
}
