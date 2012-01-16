#include <cstring>
#include <cstdio>
using namespace std;

int DNA[11];
int mat[51][41];

void init() {
	memset(DNA, 0, sizeof DNA);
	memset(mat[0], 0, sizeof mat[0]);
	mat[0][19] = 1;
}

void printMatrix() {
	char C[4] = {' ', '.', 'x', 'W'};
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 40; j++) {
			printf("%c", C[mat[i][j]]);
		}
		printf("\n");
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		init();
		
		for (int i = 0; i < 10; i++) {
			scanf("%d", &DNA[i]);
		}
		for (int i = 1; i < 50; i++) {
			for (int j = 0; j < 40; j++) {
				int K = mat[i - 1][j];
				if (j > 0) K += mat[i - 1][j - 1];
				if (j < 39)K += mat[i - 1][j + 1];
				mat[i][j] = DNA[K];
			}
		}
		
		printMatrix();
		if (T) printf("\n");
	}
	return 0;
}
