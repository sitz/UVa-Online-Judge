#include <cstdio>

int main() {
	long long N, L, U, M;
	while (scanf("%lld%lld%lld", &N, &L, &U) != EOF) {
		M = 0;
		for (int shift = 32; shift >= 0; shift--) {
			long long mask = 1LL<<shift;
			if (!(N & mask) && (M + mask <= U)) {
				M += mask;
			}
			else if (M + mask <= L) {
					M += mask;
			}
		}
		printf("%lld\n", M);
	}
	return 0;
}
