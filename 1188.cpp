#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	while (scanf("%d", &N) > 0 && N)
	{
		double F1 = 0, F2 = 0, F3 = 0;
		double num1 = 1, denom1 = 0;
		for (int i = 1; i <= N; i++)
		{
			num1 *= (N - 1);
			F1 += (num1 * i);
			denom1 += (num1);
		}
		double num2 = N, denom2 = 0;
		for (int i = 1; i <= N - 1; i++)
		{
			num2 *= (N - i);
			F2 += (num2 * i);
			denom2 += (num2);
		}
		double num3 = N * (N - 1), denom3 = 0;
		for (int i = 2; i <= N - 1; i++)
		{
			num3 *= (N - i);
			F3 += (num3 * (i + 1));
			denom3 += (num3);
		}
		F1 /= denom1;
		F2 /= denom2;
		F3 /= denom3;
		printf("%.4lf %.4lf %.4lf\n", F1, F2, F3);
	}
}