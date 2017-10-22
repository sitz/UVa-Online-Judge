#include <bits/stdc++.h>

using namespace std;

const double lg2 = log10(2.0);

int main()
{
	int i, n, r, digit;
	double ans;
	scanf("%d", &r);
	for (i = 0; i < r; i++)
	{
		scanf("%d", &n);
		digit = (int)ceil(n * lg2);
		ans = pow(2, digit / lg2 - n) + 0.0000000001;
		printf("2^-%d = %.3fE-%d\n", n, ans, digit);
	}
	return 0;
}
