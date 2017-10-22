#include <bits/stdc++.h>

using namespace std;

float r = 3950;
float R = 432000;
float D = 92900000;
float pi;
float L, theta1, theta2, beta1, beta;
float d;
float Gamma;
float fraction;

float degree(float a)
{
	return a * 180.0 / pi;
}

float betaT(float t)
{
	return beta1 - 2 * pi * t / 24.0 / 3600.0;
}

int main()
{
	float t;
	pi = 4 * atan(1);
	L = sqrt(D * D + R * R - r * r);
	theta1 = atan(R / D);
	theta2 = atan(L / r);
	beta1 = theta1 + theta2;
	/*
	   printf("pi = %9.4f\n", pi);
	   printf("L = %9.4f\n", L );
	   printf("th1 = %9.4f  th2 = %9.4f\n", degree(theta1), degree(theta2) );
	   */
	while (1)
	{
		if (scanf("%f", &t) == EOF)
		{
			break;
		}
		beta = betaT(t);
		d = (D * cos(beta) - r) / sin(beta);
		if (d <= -R)
		{
			Gamma = -pi / 2;
		}
		else if ((d > -R) && (d < R))
		{
			Gamma = asin(d / R);
		}
		else
		{
			Gamma = pi / 2;
		}
		fraction = 0.5 + Gamma / pi + d * cos(Gamma) / pi / R;
		printf("%f\n", fraction);
		/*
		   printf("t = %9.4f  betaT = %9.4f  d = %9.4f  fraction = %9.4f\n",
		   t, degree ( beta ), d, fraction);
		   */
	}
	return 0;
}
