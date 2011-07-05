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

string mod(string A){
	int L = A.length(), i;
	string B = "";
	FOI(i, 0, L-1)
		B += tolower(A[i]);
		
	sort(B.begin(), B.end());
	return B;
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	map<string, string> Map;
	map<string, string>::iterator mit;
	map<string, int> Cnt;
	map<string, int>::iterator cit;
	vector<string> V;
	int i, j;
	while (true){
		string A, B;
		cin >> A;
		if (A == "#")
			break;
		B = mod(A);
		Map[A] = B;
		++Cnt[B];
	}
	for (mit = Map.begin(); mit != Map.end(); mit++){
		if (Cnt[(*mit).second] <= 1)
			V.push_back((*mit).first);
	}
	sort(V.begin(), V.end());
	FOI(i, 0, V.size() - 1)
		cout << V[i] << endl;
	return 0;
}

