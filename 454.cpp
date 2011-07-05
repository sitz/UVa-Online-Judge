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

string rem(string S){
	sort(S.begin(), S.end());
	int L = S.length() - 1, i;
	string R = "";
	FOI(i, 0, L)
		if (!isspace(S[i]))
			R += S[i];
	return R;
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int T;
	cin >> T;
	string str;
	getline(cin, str); getline(cin, str);
	while (T--){
		vector< string > V;
		map<string, string> Map;
		while (getline(cin, str)){
			if (str == "")
				break;
			V.push_back(str);
			Map[str] = rem(str);
		}
		sort(V.begin(), V.end());
		int SZ = V.size() - 1;
		int i, j;
		FOI(i, 0, SZ)
			FOI(j, i+1, SZ)
				if (Map[V[i]] == Map[V[j]])
					cout << V[i] << " = " << V[j] << endl;
		if (T)
			cout << endl;
	}
	return 0;
}

