#include <cstdio>

#define MAX 500000
int Last[MAX + 1];
void Cal() {
	Last[0] = 0;
	Last[1] = 1;
	Last[2] = 2;
	
	for (int i = 3; i <= MAX; i++) {
		if (i < Last[i - 1] + 2)
			Last[i] = 2;
		else
			Last[i] = Last[i - 1] + 2;
	}
}

int main() {
	Cal();
	
	while (true) {
		int N;
		scanf("%d", &N);
		if (!N) break;
		
		printf("%d\n", Last[N]);
	}
}
