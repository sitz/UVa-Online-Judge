#include <cstdio>
#include <string>
using namespace std;

string decimalToRoman(int value) {
	string roman[9] = {"c", "xc", "l", "xl", "x", "ix", "v", "iv", "i"};
	int decimal[9]  = {100, 90, 50, 40, 10, 9, 5, 4, 1};
	
    string romanNumeral = "";

    for (int i = 0; i < 9; i++) {
      while (value >= decimal[i]) {
        value -= decimal[i];
        romanNumeral += roman[i];
      }
    }
    return romanNumeral;
}

struct Alpha {
	int ii, vv, xx, ll, cc;
};

int main() {
	string S;
	Alpha R[101];
	R[0].ii = R[0].vv = R[0].xx = R[0].ll = R[0].cc = 0;
	for (int i = 1; i <= 100; i++) {
		S = decimalToRoman(i);
		R[i] = R[i - 1];
		for (int j = 0; j < S.length(); j++) {
			switch (S[j]) {
				case 'i': ++R[i].ii;
						  break;
				case 'v': ++R[i].vv;
						  break;
				case 'x': ++R[i].xx;
						  break;
				case 'l': ++R[i].ll;
						  break;
				case 'c': ++R[i].cc;
						  break;
			}
		}
	}
	
	int N;
	while (scanf("%d", &N)) {
		if (!N) break;
		printf("%d: %d i, %d v, %d x, %d l, %d c\n", N, R[N].ii, R[N].vv, R[N].xx, R[N].ll, R[N].cc);
	}
	return 0;
}
