#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
	int T, t;
	cin >> T;
	for (t = 1; t <= T; t++) {
		string str = "", S = "";
		cin	>> str;
		str += " ";
		for (int i = 0; i + 1 < str.length(); i++) {
			S += str[i];
			if (isalpha(str[i])) S += " ";
			if (isdigit(str[i]) && !isdigit(str[i + 1])) S += " ";
		}
		istringstream ss(S);
		string A;
		int B;
		cout << "Case " << t << ": ";
		while (ss >> A >> B) {
			while (B--) cout << A;
		}
		cout << endl;
	}
	return 0;
}
