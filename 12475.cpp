#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

const double PI = acos(-1);

double ellipse_circumference(double a, double b)
{
	int p[] = {0, 1, 2, 4, 9, 20, 43, 90, 185, 376, 759, 1526};
	double c[] = {5.9685, 3.7127, 0.28582, 2.098, 1.462, 1.1413, 0.736, 0.459, 0.244, 0.144, 0.051, 0.062};
	double h = pow((a - b) / (a + b), 2), g = 0;
	rep(i, 11) g += c[i] * pow(h, p[i]);
	return PI * (a + b) * (1 + 3 * h / (10 + sqrt(4 - 3 * h)) + (44 - 14 * PI) / (11 * PI) * pow(h, g));
}

void solve()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%.9f\n", ellipse_circumference(a, b));
}

int main()
{
	int T, t;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		printf("Case %d: ", t), solve();
	}
	return 0;
}
