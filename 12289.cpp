#include <stdio.h>
#include <string.h>

int main() {
	char S[3][20] = {"one", "two", "three"};
	int Len[3] = {3, 3, 5};
	int T;
	scanf("%d", &T);
	while (T--) {
		char str[20];
		scanf("%s", str);
		int L = strlen(str);
		for (int i = 0; i < 3; i++) {
			if (L == Len[i]) {
				int C = 0;
				for (int j = 0; j < Len[i]; j++)
					C += (str[j] != S[i][j]);
				if (C <= 1) {
					printf("%d\n", i + 1);
					break;
				}
			}
		}
	}
	return 0;
}
