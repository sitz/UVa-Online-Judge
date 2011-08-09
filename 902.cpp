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

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int N, i;
	string S;
	while (cin >> N) {
		cin >> S;
		map<string, int> Map;
		map<string, int>::iterator it;
		pair<string, int> P;
		
		int L = S.length();
		int M = 0;
		FOI(i, 0, L-N) {
			string Key = S.substr(i, N);
			++Map[Key];
		}
		for (it = Map.begin(); it != Map.end(); it++) {
			if ((*it).second > M) {
				M = (*it).second;
				P = (*it);
			}
		}
		cout << P.first << endl;
	}
	return 0;
}
