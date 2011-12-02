#include <cstdio>

int main() {
	int T, t, HH, MM;
	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		int A, B, C, D;
		scanf("%d:%d", &HH, &MM); A = HH * 60 + MM;
		scanf("%d:%d", &HH, &MM); B = HH * 60 + MM;
		scanf("%d:%d", &HH, &MM); C = HH * 60 + MM;
		scanf("%d:%d", &HH, &MM); D = HH * 60 + MM;
		
		if (A > D || B < C) printf("Case %d: Hits Meeting\n", t);
		else printf("Case %d: Mrs Meeting\n", t);
	}
	return 0;
}
