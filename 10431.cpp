#include <bits/stdc++.h>

using namespace std;

const double b[] = {0.319381530, -0.356563782, 1.781477937, -1.821255978, 1.330274429};
const double p = 0.2316419;
const double PI = atan(1) * 4;

int kase = 1;
int N, Q;
double mean, dev, value;

int main()
{
	int line = 0;
	while (scanf("%d", &N) != EOF)
	{
		if (line > 0)
		{
			printf("\n");
		}
		printf("Data Set #%d\n", kase++);
		int i;
		double sum_x = 0, sum_xx = 0;
		for (i = 0; i < N; i++)
		{
			cin >> value;
			sum_x += value;
			sum_xx += value * value;
		}
		mean = sum_x / N;
		dev = sum_xx - 2 * sum_x * mean + mean * mean * N;
		dev /= (double)(N - 1);
		dev = sqrt(dev);
		printf("Mean = %.4lf\n", mean);
		printf("Standard Deviation = %.4lf\n", dev);
		cin >> Q;
		for (i = 0; i < Q; i++)
		{
			cin >> value;
			double z, fz, t, qz;
			z = (value - mean) / dev;
			fz = exp(-0.5 * z * z) / sqrt(2 * PI);
			t = 1 / (1 + p * fabs(z));
			qz = fz * (b[0] * t + b[1] * t * t + b[2] * t * t * t + b[3] * t * t * t * t + b[4] * t * t * t * t * t);
			//P(z) = 0.9963, Q(z) = 0.0037, T = 0.0403
			printf("P(z) = %.4lf, Q(z) = %.4lf, T = %.4lf\n", 1.0 - qz, qz, qz * N);
		}
		line++;
	}
	return 0;
}
