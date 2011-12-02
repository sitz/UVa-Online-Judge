#include <cstdio>
#define min(A, B) ((A) < (B) ? (A) : (B))

int main() {
	int T, t;
	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		int N, duration, Mile = 0, Juice = 0;
		scanf("%d", &N);
		while (N--) {
			scanf("%d", &duration);
			Mile  += (duration/30 + 1) * 10;
			Juice += (duration/60 + 1) * 15;
		}
		printf("Case %d:", t);
		if (Mile <= Juice) printf(" Mile");
		if (Juice <= Mile) printf(" Juice");
		printf(" %d\n", min(Mile, Juice));
	}
	return 0;
}
