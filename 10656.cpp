#include <stdio.h>

int main() {
	while (true) {
		int N, I, F = 0;
		scanf("%d", &N);
		if (!N) break;
		
		while (N--) {
			scanf("%d", &I);
			if (I > 0) {
				if (F) printf(" ");
				printf("%d", I);
				F = 1;
			}
		}
		if (!F) printf("0");
		printf("\n");
	}
	return 0;
}

