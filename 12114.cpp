#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

const double EPS = 1e-10;

int main() {
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	for (int t = 1; ; t++) {
		int B, S;
		scanf("%d%d", &B, &S);
		if (!B && !S) break;
		
		printf("Case %d: ", t);
		
		if (B <= 1) printf(":-\\\n");
		else if (B <= S) printf(":-|\n");
		else printf(":-(\n");
	}
	return 0;
}
