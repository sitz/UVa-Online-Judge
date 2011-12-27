#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int line[10005] = {0};
	int L, H, R;
	int Min = 10004, Max = 0;
	while (scanf("%d %d %d", &L, &H, &R) != EOF) {
		Min = min(L, Min);
		Max = max(R, Max);
		
		for (int i = L; i < R; i++)
			line[i] = max(line[i], H);
	}
	
	for (int i = Min; i <= Max; i++) {
		if (line[i] != line[i - 1]) {
			if (i > Min) printf(" ");
			
			printf("%d %d", i, line[i]);
		}
	}
	printf("\n");
	return 0;
}
