#include <stdio.h>
const long long MOD = 2000000011LL;

long long bigMod(long long a, long long b) {
	long long x = 1, y = a;
	while (b > 0) {
		if (b % 2 == 1)
			x = (x * y) %MOD;
		y = (y * y) %MOD;
		b /= 2;
	}
	return x %MOD;
}

int main() {
	long long T, N, t;
	scanf("%lld", &T);
	for (t = 1; t <= T; t++) {
		scanf("%lld", &N);
		printf("Case #%lld: %lld\n", t, bigMod(N, N - 2));
	}
	return 0;
}
