#include <cstdio>
using namespace std;

int F[50000];

int main() {
	int N, M, Q, i, j, A, B;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &F[i]);
	scanf("%d", &Q);
	while (Q--) {
		scanf("%d", &M);
		A = -1; B = -1;
		for (j = 0; j < N; j++) {
			if (F[j] > M) {
				B = F[j];
				break;
			}
			if (F[j] < M) A = F[j];
		}
		if (A == -1) printf("X ");
		else printf("%d ", A);
		
		if (B == -1) printf("X\n");
		else printf("%d\n", B);
	}
	return 0;
}
