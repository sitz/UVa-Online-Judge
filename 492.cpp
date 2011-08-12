#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define FOI(i, A, B) for (i = A; i <= B; i++)
#define FOD(i, A, B) for (i = A; i >= B; i--)

bool isVowel(char C) {
	C = tolower(C);
	return (C == 'a' || C == 'e' || C == 'i' || C == 'o' || C == 'u');
}

string mod(string S) {
	if (isVowel(S[0]))
		return S + "ay";
	return S.substr(1) + S[0] + "ay";
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	string str;
	while (getline(cin, str)) {
		int L = str.length() - 1;
		int i, j;
		string temp = "";
		FOI(i, 0, L) {
			if (!isalpha(str[i])) {
				if (!temp.empty())
					cout << mod(temp);
				cout << str[i];
				temp = "";
			}
			else
				temp += str[i];
		}
		if (!temp.empty())
			cout << mod(temp);
		cout << endl;
	}
	return 0;
}
