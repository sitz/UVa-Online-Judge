#include <bits/stdc++.h>

using namespace std;

int main()
{
	double sqrtwo = sqrt(2.0);
	double pathLength;
	int times, n;
	scanf("%d", &times);
	for (int i = 0; i < times; i++)
	{
		scanf("%d", &n);
		pathLength = (n - 1) * 4 + ((n - 2 > 0) ? ((n - 2) * (n - 2) * sqrtwo) : (0));
		printf("%.4f\n", pathLength);
		if (i != times - 1)
		{
			printf("\n");
		}
	}
	return 0;
}
