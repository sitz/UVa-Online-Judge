#include <stdio.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
	int T, N, M, I, J;
	scanf("%d", &T);
	while (T--) {
		int minM = 0, maxM = 0;
		scanf("%d%d", &M, &N);
		while (N--) {
			scanf("%d", &I);  J = M - I;
			minM = max(minM, min(I, J));
			maxM = max(maxM, max(I, J));
		}
		printf("%d %d\n", minM, maxM);
	}
	return 0;
}
