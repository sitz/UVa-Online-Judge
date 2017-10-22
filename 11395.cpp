#include <bits/stdc++.h>

using namespace std;

int main()
{
	double n;
	scanf("%lf", &n);
	while (n != 0)
	{
		printf("%0.lf\n", n - ((int)sqrt(n) + (int)sqrt(n / 2)));
		scanf("%lf", &n);
	}
	return 0;
}
