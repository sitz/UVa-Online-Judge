#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {
	int N;
	char image[30];
	while (true) {
		scanf("%d\n", &N);
		if (!N)
			break;
		int totBlank = 0, minBlank = 50;
		for (int n = 0; n < N; n++) {
			gets(image);
			//puts(image);
			//scanf("%[A-Z ][^\n]s", image);
			//printf("%s\n", image);
			int blank = 0;
			for (int i = 0; i < 25; i++) {
				if (image[i] == ' ') ++blank;
			}
			totBlank = totBlank + blank;
			minBlank = min(blank, minBlank);
		}
		totBlank -= (N * minBlank);
		printf("%d\n", totBlank);
	}
	return 0;
}
