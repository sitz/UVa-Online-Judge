#include <bits/stdc++.h>

using namespace std;

double solve(double a, double b, double c)
{
	double D = b * b - 4 * a * c;
	return (-b + sqrt(D)) / (2 * a);
}

int main()
{
	double AB;
	double CD;
	double AD;
	double BC;
	double Height;
	double s;
	double S;
	double degree;
	int Land;
	scanf("%d", &Land);
	for (int i = 1; i <= Land; i++)
	{
		scanf("%lf %lf %lf %lf", &AB, &CD, &AD, &BC);
		degree = AB - CD;
		s = (AD + (degree) + BC) / 2;
		S = sqrt(s * (s - AD) * (s - (degree)) * (s - BC));
		Height = S * 2 / (degree);
		S = (CD + AB) * Height / 2;
		S = S / 2;
		s = solve(degree, CD * Height * 2, -S * Height * 2);
		printf("Land #%d: %lf %lf\n", i, ((Height - s) * AD) / Height + 1e-7, ((Height - s) * BC) / Height + 1e-7);
	}
	return 0;
}
