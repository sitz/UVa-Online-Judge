#include <set>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int N, M, I, A, B;
	while (scanf("%d", &N) != EOF) {
		set< int > S;
		set< int >::iterator it;
		
		while (N--) {
			scanf("%d", &I);
			S.insert(I);
		}
		scanf("%d", &M);
		A = 0; B = 1000000;
		for (it = S.begin(); it != S.end(); it++) {
			if (S.find(M - *it) != S.end()) {
				int V = M - 2 * (*it);
				if (V >= 0 && V < B - A) {
					A = *it;
					B = M - (*it);
				}
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n", A, B);
	}
	return 0;
}
