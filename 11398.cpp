#include <string>
#include <iostream>
using namespace std;

string binaryValue(string S) {
	if (S.length() == 1) return "1";
	return "0";
}

long long decimalValue(string S) {
	long long V = 0, mul = 1;
	int N = S.length();
	for (int i = N - 1; i >= 0; i--) {
		V += (S[i] - '0') * mul;
		mul *= 2;
	}
	return V;
}

int main() {
	string str, S = "";
	string flag;
	while (true) {
		cin >> str;
		if (str == "~") break;
		flag = binaryValue(str);
		while (true) {
			cin >> str;
			if (str == "#") {
				cout << decimalValue(S) << endl;
				S = "";
				break;
			}
			else if (str.length() < 3) {
				flag = binaryValue(str);
			}
			else {
				for (int i = 0; i + 2 < str.length(); i++)
					S += flag;
			}
		}
	}
	return 0;
}
