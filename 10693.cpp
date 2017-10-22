#include <bits/stdc++.h>

using namespace std;

double v, volume;
long int L, f;
int main()
{
	while (scanf("%ld %ld", &L, &f) != EOF)
	{
		if (L == 0 && f == 0)
		{
			break;
		}
		v = sqrt(L * f * 2.0);
		volume = (v * 3600) / (2 * L);
		printf("%0.5lf %0.5lf", v, volume);
		printf("\n");
	}
	return 0;
}
