#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
	string vowel = "AUEOI", V = "";
	string consonant = "JSBKTCLDMVNWFXGPYHQZR", C = "";
	for (int i = 0; i < vowel.length(); i++)
		for (int j = 0; j < 21; j++) V += vowel[i];
	for (int i = 0; i < consonant.length(); i++)
		for (int j = 0; j < 5; j++) C += consonant[i];
	int T, t, N;
	cin >> T;
	for (t = 1; t <= T; t++) {
		cin >> N;
		string S = "", A = "", B = "";
		if (N & 1) A = V.substr(0, (N + 1) / 2);
		else A = V.substr(0, N / 2);
		B = C.substr(0, N / 2);
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		for (int i = 0; i < A.length(); i++) {
			S += A[i];
			if (i < B.length()) S += B[i];
		}
		cout << "Case " << t << ": " << S << endl;
	}
	return 0;
}
