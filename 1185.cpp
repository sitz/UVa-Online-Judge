#include <math.h>
#include <stdio.h>

#define MAX 10000000
double Arr[MAX + 1];

void Cal() {
	Arr[0] = 0;
	for (int i = 1; i <= MAX; i++)
		Arr[i] = Arr[i - 1] + log(i);
}

int main() {
	Cal();
	int T;
	scanf("%d", &T);
	while (T--) {
		int N;
		scanf("%d", &N);
		printf("%.0lf\n", floor(Arr[N]/log(10.0) + 1.0));
	}
	return 0;
}
