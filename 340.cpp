#include <cstring>
#include <cstdio>
using namespace std;

int main() {
	int t = 1;
	while (true) {
		int N;
		scanf("%d", &N);
		if (!N) break;
		printf("Game %d:\n", t++);
		int A[N], B[N];
		for (int i = 0; i < N; i++)
			scanf("%d", &A[i]);
		while (true) {
			int C = 0;
			for (int i = 0; i < N; i++) {
				scanf("%d", &B[i]);
				if (!B[i]) ++C;
			}
			if (C == N) break;
			bool flag[N];
			int X = 0, Y = 0;
			memset(flag, true, sizeof flag);
			for (int i = 0; i < N; i++) {
				if (A[i] == B[i]) {
					++X;
					flag[i] = false;
					B[i] = -1;
				}
			}
			for (int i = 0; i < N; i++) {
				if (flag[i]) {
					for (int j = 0; j < N; j++) {
						if (A[i] == B[j]) {
							++Y;
							B[j] = -1;
							break;
						}
					}
				}
			}
			printf("    (%d,%d)\n", X, Y);
		}
	}
	return 0;
}
