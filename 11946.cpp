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

#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	map<char, char> Map;
	Map.clear();
	Map['0'] = 'O'; Map['1'] = 'I'; Map['2'] = 'Z'; Map['3'] = 'E'; Map['4'] = 'A';
	Map['5'] = 'S'; Map['6'] = 'G'; Map['7'] = 'T'; Map['8'] = 'B'; Map['9'] = 'P';
	int T;
	cin >> T;
	string str;
	getline(cin, str);
	while( 	T-- ){
		while( getline(cin, str) ){
			if( str == "" )
				break;
			string out = "";
			int i, L = str.length();
			FOI(i, 0, L-1){
				if( Map.find(str[i]) != Map.end() )
					out += Map[str[i]];
				else
					out += str[i];
			}
			cout << out << endl;
		}
		if( T > 0 )
			cout << endl;
	}
	return 0;
}
