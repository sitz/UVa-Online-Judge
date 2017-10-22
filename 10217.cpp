#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	int a = 1, b = 1, c;
	double D, x;
	while (scanf("%d", &N) == 1)
	{
		c = -N;
		D = sqrt(b * b - 4 * a * c);
		x = (-b + D) / 2 / a;
		printf("%.2lf %d\n", x, (int)floor(x) + 1);
	}
	return 0;
}
