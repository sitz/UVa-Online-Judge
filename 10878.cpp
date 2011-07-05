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

int val[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

char calc(string S){
	int L = S.length() - 1, i;
	int V = 0;
	FOI(i, 0, L)
		if (S[i] == '1')
			V += val[i];
	//cout << V << " ";
	return (char)V;
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	string S;
	getline(cin, S);
	while (!cin.eof()) {
		string str = "";
		int L = S.length() - 1, i;
		FOD(i, L, 0) {
			if (S[i] == ' ') str += "0";
			else if (S[i] == 'o') str += "1";
			else continue;
		}
		//cout << str << endl;
		if (str != "") cout << calc(str);
		getline(cin, S);
	}
	return 0;
}

