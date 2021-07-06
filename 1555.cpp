#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e3 + 10;
double eps = 1e-8;
int n;
double A, B, H[N];
bool judge(double h2)
{
	H[2] = h2;
	for (int i = 3; i <= n; i++)
	{
		H[i] = H[i - 1] * 2 + 2 - H[i - 2];
		if (H[i] < 0)
		{
			return false;
		}
	}
	B = H[n];
	return true;
}
int main()
{
	while (scanf("%d%lf", &n, &A) != EOF)
	{
		H[1] = A;
		double L = 0, R = A;
		while (R - L > eps)
		{
			double M = (L + R) / 2;
			if (judge(M))
			{
				R = M;
			}
			else
			{
				L = M;
			}
		}
		printf("%.2lf\n", B);
	}
	return 0;
}
