#include <cstdio>

const long long MAX = 50000;
long long P[10000];
long long S = 0;
static bool prime[MAX + 1];

void sieve() {
	prime[0] = true;
	prime[1] = true;
	
	for (long long i = 2; i <= MAX; i++) {
		if (!prime[i]) {
			P[S++] = i;
			for (long long j = i * i; j <= MAX; j += i) {
				prime[j] = true;
			}
		}
	}
}

int main() {
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);

	sieve();
	long long N, I;
	while (scanf("%lld", &N) != EOF) {
		if (N == 0) break;
		
		long long M = 0;
		long long V[50];
		I = N;
		if (N < 0) {
			V[M++] = -1;
			N = -N;
		}
		for (long long i = 0; i < S; i++) {
			if (N == 1) break;
			while (N % P[i] == 0) {
				V[M++] = P[i];
				N /= P[i];
			}
		}
		if (N > 1) V[M++] = N;
		
		printf("%lld = %lld", I, V[0]);
		for (long long i = 1; i < M; i++) {
			printf(" x %lld", V[i]);
		}
		printf("\n");
	}
	return 0;
}
