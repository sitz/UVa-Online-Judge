#include <set>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	set< string > Set;
	set< string >::iterator it;
	string str, A, B;
	while (cin >> str)
		Set.insert(str);
		
	for (it = Set.begin(); it != Set.end(); it++) {
		str = *it;
		for (int i = 1; i < str.length(); i++) {
			A = str.substr(0, i);
			B = str.substr(i);
			if (Set.find(A) != Set.end() && Set.find(B) != Set.end()) {
				cout << str << endl;
				break;
			}
			//cout << A << " " << B << endl;
		}
	}
	return 0;
}
