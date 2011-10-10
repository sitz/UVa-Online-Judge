#include <cmath>
#include <cstdio>

const double PI = acos(-1.0) / 180.0;
const double D = sin(108.0 * PI) / sin(63.0 * PI);

int main() {
	double F;
	while (scanf("%lf", &F) != EOF) {
		printf("%.10lf\n", F * D);
	}
	return 0;
}
