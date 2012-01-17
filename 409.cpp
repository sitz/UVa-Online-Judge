#include <set>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int K, E, t = 1;
	string str;
	while (scanf("%d %d\n", &K, &E) != EOF) {
		set< string > keyword;
		string excuse[E];
		int score[E], Max = 0;
		while (K--) {
			getline(cin, str);
			keyword.insert(str);
		}
		for (int i = 0; i < E; i++) {
			getline(cin, str);
			excuse[i] = str;
			score[i] = 0;
			string temp = "";
			str = " " + str + " ";
			for (int j = 0; j < str.length(); j++) {
				if (isalpha(str[j])) temp += tolower(str[j]);
				else {
					if (keyword.find(temp) != keyword.end()) ++score[i];
					temp = "";
				}
			}
			Max = max(Max, score[i]);
		}
		cout << "Excuse Set #" << t++ << endl;
		for (int i = 0; i < E; i++) {
			if (score[i] == Max) cout << excuse[i] << endl;
		}
		cout << endl;
	}
	return 0;
}
