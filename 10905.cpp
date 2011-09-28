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
#include <ctime>
#include <sstream>
using namespace std;

bool comp(string A, string B) {
	if (A == B) return true;
	
	int aL = A.length(), bL = B.length();
	int Lmin = min(aL, bL);
	int Lmax = max(aL, bL);
	
	string X = A.substr(0, Lmin);
	string Y = B.substr(0, Lmin);
	if (X != Y) return X > Y;
	
	if (aL > bL) {
		X = A.substr(Lmin);
		return comp(X, B);
	}
	else {
		Y = B.substr(Lmin);
		return comp(A, Y);
	}
}

int main() {
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	while (true) {
		int N;
		cin >> N;
		if (!N) break;
		
		string Arr[N];
		for (int i = 0; i < N; i++)
			cin >> Arr[i];
			
		sort(Arr, Arr + N, comp);
		
		for (int i = 0; i < N; i++)
			cout << Arr[i];
			
		cout << endl;
	}
	return 0;
}
