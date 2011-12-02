#include <cstring>
#include <cstdio>
using namespace std;

int main() {
	int T, t, i, j, N, I;
	bool flag;
	int count[110];
	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		flag = true;
		memset(count, 0, sizeof count);
		scanf("%d", &N);
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				scanf("%d", &I);
				++count[I];
				if (count[I] > N) flag = false;
			}
		}
		if (!flag) printf("Case %d: no\n", t);
		else printf("Case %d: yes\n", t);
	}
	return 0;
}
