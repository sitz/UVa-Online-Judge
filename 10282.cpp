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
#include <complex>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <ctime>
using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

#define FOI(I, A, B)	for (I=A; I<=B; I++)
#define FOD(I, A, B)	for (I=A; I>=B; I--)

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	
	map<string, string> dict;
	map<string, string>::iterator it;
	
	string str;
	while( getline(cin, str) ){
		if( str == "" )
			break;
		stringstream ss;
		string key, val;
		ss << str;
		ss >> val >> key;
		dict[key] = val;
	}
	
	while( cin >> str ){
		it = dict.find(str);
		if( it != dict.end() )
			cout << dict[str] << endl;
		else
			cout << "eh" << endl;
	}
	return 0;
}
