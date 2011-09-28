#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

#define MAX 10010
bool prime[MAX];
vector< int > P;

void sieve() {
	memset(prime, true, sizeof prime);
	prime[1] = prime[0] = false;
	
	for (int i = 2; i < MAX; i++) {
		if (prime[i]) {
			P.push_back(i);
			for (int j = i * i; j < MAX; j += i)
				prime[j] = false;
		}
	}
	//printf("%d\n", P.size());
}

int main() {
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);

	sieve();

	int T;
	scanf("%d", &T);
	while (T--) {
		int N;
		scanf("%d", &N);
		int Max = -1, X = -1;
		for (int i = 0; i < P.size(); i++) {
			if (P[i] > N) break;
			int x = P[i];
			int p = (int) N / x;
			if (p * x <= N && N < (p + 1) * x && Max < N - p * x) {
				Max = N - p * x;
				X	= x;
			}
		}
		printf("%d\n", X);
	}
}
