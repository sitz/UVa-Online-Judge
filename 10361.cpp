#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
	int T, i;
	scanf("%d\n", &T);
	while (T--) {
		string A, B;
		string s1 = "", s2 = "", s3 = "", s4 = "", s5 = "";
		getline(cin, A); getline(cin, B);
		for (i = 0; A[i] != '<'; i++)		 s1 += A[i];
		for (i = i + 1; A[i] != '>'; i++)	 s2 += A[i];
		for (i = i + 1; A[i] != '<'; i++)	 s3 += A[i];
		for (i = i + 1; A[i] != '>'; i++)	 s4 += A[i];
		for (i = i + 1; i < A.length(); i++) s5 += A[i];
		A = s1 + s2 + s3 + s4 + s5;
		int pos = (int)B.find("...");
		B.replace(pos, 3, s4 + s3 + s2 + s5);
		cout << A << endl;
		cout << B << endl;
	}
	return 0;
}
