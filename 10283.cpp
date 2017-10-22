#include <bits/stdc++.h>

using namespace std;

/* Globals */
long double r, I, E;
int R, N;
const long double PI = 2 * acos(0.0);

/* Functions */

/* Calculates the radius of each smaller circle */
void radius(void)
{
	if (N < 3)
	{
		r = (double)R / N;
		return;
	}
	long double num = sin(2.0 / N * PI);
	long double denom = 2 * sin((N - 2) / (2.0 * N) * PI) + sin((2.0 / N) * PI);
	r = (double)R * num / denom;
}

/* Calculates the blue area */
void internal(void)
{
	if (N < 3)
	{
		I = 0;
		return;
	}
	I = N * r * sqrt(R * R - 2 * r * R) - 0.5 * PI * r * r * (N - 2.0);
}

/* Calculates the leftover area */
void external(void)
{
	/* Area of whole circle minus area of all small circles minus I */
	E = PI * R * R - N * PI * r * r - I;
}

int main(int argc, char **argv)
{
	while (cin >> R >> N)
	{
		radius();
		internal();
		external();
		printf("%.10Lf %.10Lf %.10Lf\n", r, I, E);
	}
	return 0;
}
