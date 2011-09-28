#include <cstdio>
#include <cmath>
using namespace std;

const double PI = acos(-1.0);

int main() {
	double a, b, c;
	while (scanf("%lf%lf%lf", &a, &b, &c) != EOF) {
			double s = (a + b + c) / 2.0;
			
			double V = sqrt(s * (s - a) * (s - b) * (s - c));
			
			double Rr = V / s;
			double R = PI * Rr * Rr;
			
			double Sr = (a * b * c) / (4 * Rr * s);
			double S = PI * Sr * Sr;
			
			S -= V;
			V -= R;
			
			printf("%.4lf %.4lf %.4lf\n", S, V, R);
	}
	return 0;
}
