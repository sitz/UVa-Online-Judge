#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long int64;

int main() {
	int64 t = 1, N;
	while (scanf("%lld", &N) != EOF) {
		int64 Vec[N];
		for (int i = 0; i < N; i++) scanf("%lld", &Vec[i]);
		
		int64 Max = 0;
		for (int i = 0; i < N; i++) {
			int64 Pro = 1;
			for (int j = i; j < N; j++) {
				Pro *= Vec[j];
				Max = max(Max, Pro);
			}
		}
		printf("Case #%lld: The maximum product is %lld.\n\n", t++, Max);
	}
	return 0;
}
