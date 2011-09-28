#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main() {
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	string str;
	while (getline(cin, str))
		cout << str << endl;
	return 0;
}
