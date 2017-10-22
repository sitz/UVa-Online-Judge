#include <bits/stdc++.h>

using namespace std;


int main()
{
	int t;
	double H, W, S;
	scanf("%d", &t);

	while (t--)
	{
		scanf("%lf %lf %lf", &H, &W, &S);
		if (S >= H * W)
			puts("0.000000%");
		else if (S)
			printf("%.6f%%\n", (W * H - S * log(W / S * H) - S) / (W * H) * 100 + 1e-12);
		else
			printf("%.6f%%\n", 100.0);
	}
}
