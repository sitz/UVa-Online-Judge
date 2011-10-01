#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

long long toLL(string S) {
	long long V = 0, i, j, L = S.length(), toMul = 1;
	for (i = 0; i < L; i++) {
		V += (toMul * (S[i] - '0'));
		toMul *= 2;
	}
	return V;
}

int main() {
	int C, i, j, P, Q;
	string S = "";
	scanf("%d", &C);
	while (C--) {
		scanf("%d %d", &P, &Q);
		S =  "";
		if (P) {
			S += "1";
			P -= 1;
		}
		for (j = 0; j + 1 < Q; Q--) {
			S = "0" + S;
			for (i = 0; i < min(2, P); i++) {
				S = "1" + S;
			}
			P -= 2;
		}
		if (Q) {
			S = "0" + S;
			if (P > 0) {
				S = "1" + S;
				P -= 1;
			}
		}
		while (P-- > 0) {
			S = S + "1";
		}
		reverse(S.begin(), S.end());
		printf("%lld\n", toLL(S));
	}
	return 0;
}
