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
#include <sstream>
using namespace std;

#define FOI(i, A, B) for (i = A; i <= B; i++)
#define FOD(i, A, B) for (i = A; i >= B; i--)

int parse(string S) {
	stringstream ss;
	int I;
	ss << S;
	ss >> I;
	return I;
}

bool isValid(string S) {
	if (S.empty())
		return false;
	int L = S.length() - 1, i;
	FOI(i, 0, L)
		if (!isdigit(S[i]))
			return false;
	return true;
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	string str;
	int tot = 0, i;
	while ( cin >> str ) {
		str += "#";
		//cout << str << endl;
		//cout << str << " " << str.length() << endl;
		vector< string > V;
		string O = "", temp = "";
		int L = str.length() - 1;
		//cout << "# ";
		FOI(i, 0, L) {
			//cout << i << "# " ;
			if (!isdigit(str[i])) {
				V.push_back(temp);
				//cout << temp << endl;
				temp = "";
				if (O == "") {
					O += str[i];
					//cout << O << endl;
				}
			}
			else
				temp += str[i];
		}
		//cout << endl;
		if ( !(isValid(V[0]) && isValid(V[1]) && isValid(V[2])) )
			continue;
		else if ( O == "+" && (parse(V[0]) + parse(V[1]) == parse(V[2])) )
			++tot;
		else if ( O == "-" && (parse(V[0]) - parse(V[1]) == parse(V[2])) )
			++tot;
	}
	cout << tot << endl;
	return 0;
}
