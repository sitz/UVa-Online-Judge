#include <cstdio>

long long BigMod(long long a, long long b, long long c) {
	long long x = 1, y = a;
	while (b > 0) {
		if (b % 2 == 1)
			x = (x * y) % c;
		y = (y * y) % c;
		b = b / 2;
	}
	return x % c;
}

int main(){
    long long B, E, N;
	while (scanf("%lld%lld%lld", &B, &E, &N) != EOF)
		printf("%lld\n", BigMod(B, E, N));

    return 0;
}
