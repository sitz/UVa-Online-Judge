#include <stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	while( T-- ){
		int S, D;
		scanf("%d%d", &S, &D);
		int A = S + D;
		int B = S - D;
		if (A < 0 || A&1 || B < 0 || B&1)
			printf("impossible\n");
		else
			printf("%d %d\n", A/2, B/2);
	}
	return 0;
}
