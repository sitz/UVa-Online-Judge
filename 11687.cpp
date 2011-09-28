#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int toInt(string S) {
	istringstream ss(S);
	int I;
	ss >> I;
	return I;
}

string toString(int I) {
	stringstream ss;
	string S;
	ss << I;
	ss >> S;
	return S;
}

int main(int argc, char **argv) {
	while (true) {
		string S;
		cin >> S;
		if (S == "END") break;
		
		if (S.length() < 30) {
			if (toInt(S) == (int)S.length()) {
				cout << "1\n";
				continue;
			}
		}
		S = toString(S.length());
		int I = 2;
		while ((int)S.length() != toInt(S)) {
			++I;
			S = toString(S.length());
		}
		cout << I << endl;
	}
	return 0;
}

