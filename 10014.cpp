#include <cstdio>
using namespace std;

int main() {
	int T;
    scanf("%d", &T);
	while (T--) {
		int N;
		scanf("%d", &N);
		double start = 0, end = 0, value = 0;
		scanf("%lf", &start);
		scanf("%lf", &end);
		for (int i = 0; i < N; i++) {
			double carr = 0;
			scanf("%lf", &carr);
			value += (N - i) * carr;
		}
		double sum = (N * start + end - 2 * value) / (N + 1.0);
		printf("%.2lf\n", sum);
		if (T) printf("\n");
    }
    return 0;
}
