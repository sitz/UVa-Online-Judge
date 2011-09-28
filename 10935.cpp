#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main() {
	while (true) {
		int N;
		scanf("%d", &N);
		if (!N) break;
		
		queue< int > q;
		vector< int > T;
		for (int i = 1; i <= N; i++) q.push(i);
		
		while (q.size() > 2) {
			T.push_back(q.front());
			q.pop();
			q.push(q.front());
			q.pop();
		}
		if (q.size() == 2) {
			T.push_back(q.front());
			q.pop();
		}
		
		printf("Discarded cards:");
		for (int i = 0; i < T.size(); i++) {
			if (i > 0) printf(",");
			printf(" %d", T[i]);
		}
		printf("\n");
		printf("Remaining card: %d\n", q.front());
	}
}
