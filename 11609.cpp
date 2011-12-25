#include <cstdio>
using namespace std;

typedef long long int64;
const int64 MOD = 1000000007;

int64 power(int64 B, int64 N) {
	if (N == 0) return 1LL;
	if (N == 1) return B;
	
	int64 V = power(B, N/2) %MOD;
	V = (V * V) %MOD;
	if (N & 1)
		V = (V * B) %MOD;
	return V;
}

int main() {
	int64 T;
	scanf("%lld", &T);
	for (int64 t = 1; t <= T; t++) {
		int64 N;
		scanf("%lld", &N);
		int64 V = (N * power(2, N - 1)) %MOD;
		printf("Case #%lld: %lld\n", t, V);
	}
	return 0;
}
