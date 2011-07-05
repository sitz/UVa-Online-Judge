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

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;

#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)

string toString(int I){
	stringstream ss;
	string str;
	ss << I;
	ss >> str;
	return str;
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int T;
	cin >> T;
	string str, s;
	while( T-- ){
		getline(cin, str);
		getline(cin, str);
		vector< string > ind, val;
		map<string, string> Map;
		stringstream ss;
		getline(cin, str);
		ss << str;
		while( ss >> s ) ind.push_back(s);
		int N = ind.size(), i;
		FOI(i, 0, N-1){
			cin >> str;
			Map[ind[i]] = str;
		}
		FOI(i, 0, N-1)
			cout << Map[toString(i+1)] << endl;
		if( T > 0 )
			cout << endl;
	}
	return 0;
}
