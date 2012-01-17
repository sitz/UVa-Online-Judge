#include <cstdio>

int main() {
	int num[] = {1, 2, 9, 44, 265, 1854, 14833, 133496, 1334961, 14684570, 176214841};
	int den[] = {2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};
	
	int T, N;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		printf("%d/%d\n", num[N - 2], den[N - 2]);
	}
	return 0;
}
