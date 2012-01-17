#include <cstdio>
using namespace std;

int main() {
	long long N, M, S;
	while (scanf("%lld", &N) != EOF) {
		N = (N + 1) / 2;
		M = N * N;
		M = (2 * M - 1);
		S = 3 * M - 6;
		printf("%lld\n", S);
	}
	
	return 0;
}
