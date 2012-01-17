#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;

#define abs(X) ((X) > 0 ? (X) : (-1.0 * X))
const double EPS = 1e-9;
bool isP, isU, isI;
double P, U, I;
string str;

void decide(int A) {
	string temp = "";
	double V;
	int B;
	for (B = A + 2; !isalpha(str[B]); B++) {
		temp += str[B];
	}
	stringstream ss;
	ss << temp;
	ss >> V;
	if (str[B] == 'm') V *= 0.001;
	if (str[B] == 'k') V *= 1000;
	if (str[B] == 'M') V *= 1000000;
	//cout << V << endl;
	
	if (str[A] == 'P') {
		isP = true; P = V; return;
	}
	else if (str[A] == 'U') {
		isU = true; U = V; return;
	}
	else if (str[A] == 'I') {
		isI = true; I = V; return;
	}
}

int main() {
	int T, t;
	scanf("%d\n", &T);
	for (t = 1; t <= T; t++) {
		printf("Problem #%d\n", t);
		getline(cin, str);
		isP = false; isU = false; isI = false;
		
		int A = str.find_first_of("=");
		decide(A - 1);
		int B = str.find_last_of("=");
		decide(B - 1);
		
		if (!isP) {
			P = U * I;
			printf("P=%.2lfW\n\n", (double)P);
		}
		else if (!isU) {
			U = P / I;
			printf("U=%.2lfV\n\n", (double)U);
		}
		else if (!isI) {
			I = P / U;
			printf("I=%.2lfA\n\n", (double)I);
		}
	}
	return 0;
}
