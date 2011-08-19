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

string convert(string S) {
	int i, L = S.length() - 1;
	FOI(i, 0, L)
		if (!isalpha(S[i]))
			S[i] = ' ';
	return S;
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	char Key;
	cin >> Key;
	string str;
	map< string, set< int > > Map;
	map< string, set< int > >::iterator mit;

	int Ind = 1;
	getline(cin, str);
	while (getline(cin, str)){
		str = convert(str);
		stringstream ss(str);
		string S;
		while (ss >> S)
			if (S[0] == Key)
				Map[S].insert(Ind);
		++Ind;
	}
	for (mit = Map.begin(); mit != Map.end(); mit++) {
		cout << (*mit).first;
		set< int > Set;
		set< int >::iterator sit;
		Set = (*mit).second;
		for (sit = Set.begin(); sit != Set.end(); sit++)
			cout << " " << *sit;
		cout << endl;
	}
	return 0;
}
