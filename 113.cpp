#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	double p;
	while (scanf("%d%lf", &n, &p) != EOF)
	{
		printf("%d\n", (int)floor(pow(p, (1.0 / (double)n)) + 0.1));
	}
	return 0;
}
