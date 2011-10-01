#include <stdio.h>
#include <stdlib.h>

int compA(const void *A, const void *B) {
	return ( *(int *)A - *(int *)B );
}

int compB(const void *A, const void *B) {
	return ( *(int *)B - *(int *)A );
}

int main() {
	while (1) {
		int n, d, r, i, j, over = 0, temp;
		int mor[200], eve[200];
		
		scanf("%d%d%d", &n, &d, &r);
		if (!n && !d && !r) return 0;
	
		for (i = 0; i < n; i++) scanf("%d", &mor[i]);
		for (i = 0; i < n; i++) scanf("%d", &eve[i]);
		
		qsort(mor, n, sizeof (int), compA);
		qsort(eve, n, sizeof (int), compB);

		for (i = 0; i < n; i++) {
			if (mor[i] + eve[i] > d) {
				temp = mor[i] + eve[i] - d;
				over += temp * r;
			}
		}
		printf("%d\n", over);
    }
    return 0;
}
