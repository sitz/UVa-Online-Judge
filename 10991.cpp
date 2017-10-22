#include <bits/stdc++.h>

using namespace std;

int numOfCase;

double r1, r2, r3;

int main()
{
	cin >> numOfCase;
	while (numOfCase--)
	{
		cin >> r1 >> r2 >> r3;
		double a, b, c;
		double A, B, C;
		a = r2 + r3;
		b = r1 + r3;
		c = r1 + r2;
		A = acos((b * b + c * c - a * a) / (2.0 * b * c));
		B = acos((a * a + c * c - b * b) / (2.0 * a * c));
		C = acos((a * a + b * b - c * c) / (2.0 * a * b));
		double Area = 0.5 * a * c * sin(B);
		Area -= 0.5 * A * r1 * r1;
		Area -= 0.5 * B * r2 * r2;
		Area -= 0.5 * C * r3 * r3;
		printf("%.6lf\n", Area);
	}
	return 0;
}
