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

int GCD(int A, int B) {
	if (B == 0)
		return A;
	else
		return GCD(B, A % B);
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		map<char, int> Map;
		map<char, int>::iterator it;
		string S;
		cin >> S;
		int L = S.length() - 1, i, j, k;
		FOI(i, 0, L) ++Map[S[i]];
		int G = 0;
		int tot = 0;
		for (it = Map.begin(); it != Map.end(); it++)
			G = GCD(G, (*it).second);
		for (it = Map.begin(); it != Map.end(); it++)
			tot += (*it).second / G;
		cout << tot << endl;
		if (T) cout << endl;
	}
	return 0;
}
