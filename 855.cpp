#include <algorithm>
#include <cstdio>
using namespace std;

int S[50005];
int A[50005];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int F;
		scanf("%*d%*d%d",&F);
		for (int i = 0; i < F; i++) {
			scanf("%d%d", &S[i], &A[i]);
		}
		sort(S, S + F);
		sort(A, A + F);
		int bestS = 0, bestA = 0;
		
		if (F & 1) {
			bestS = S[F / 2];
			bestA = A[F / 2];
		}
		else {
			bestS = S[(F - 1) / 2];
			bestA = A[(F - 1) / 2];
		}
		printf("(Street: %d, Avenue: %d)\n", bestS, bestA);
	}
	return 0;
}
