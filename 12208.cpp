#include <map>
#include <cstdio>
using namespace std;

map<long long, long long> Map;

long long Cal(long long N) {
	if (N <= 0) return 0;
	if (Map.find(N) != Map.end())
		return Map[N];
	
	long long M = N / 2;
	if (N & 1) {
		Map[N] = 2 * Cal(M) + M + 1;
	}
	else {
		Map[N] = Cal(M) + Cal(M - 1) + M;
	}
	return Map[N];
}

int main() {
	long long A, B, V;
	for (int t = 1; ; t++) {
		scanf("%lld%lld", &A, &B);
		if (!A && !B) return 0;
		
		V = Cal(B) - Cal(A - 1);
		printf("Case %d: %lld\n", t, V);
	}
}
