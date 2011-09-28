#include <cstdio>

struct Phone {
	int A, B;
};

int main() {
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	
	while (true) {
		int N, M;
		scanf("%d%d", &N, &M);
		if (!N && !M) break;
		Phone P[N];
		for (int i = 0; i < N; i++) {
			int U, V, W, X;
			scanf("%d%d%d%d", &U, &V, &W, &X);
			P[i].A = W;
			P[i].B = W + X;
		}
		while (M--) {
			int X, Y, C = 0;
			scanf("%d%d", &X, &Y);
			Y += X;
			for (int i = 0; i < N; i++)
				C += (X < P[i].B && Y > P[i].A );
			printf("%d\n", C);
		}
	}
	return 0;
}
