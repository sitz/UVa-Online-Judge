#include <cstring>
#include <cstdio>

int main() {
	int T, D = 0, I;
	char str[20];
	scanf("%d", &T);
	while (T--) {
		scanf("%s", str);
		if (!strcmp(str, "report")) {
			printf("%d\n", D);
		}
		else {
			scanf("%d", &I);
			D += I;
		}
	}
	return 0;
}
