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

int EditDistance(string s1, string s2) {
	int m = s1.length();
    int n = s2.length();
    int i, j;
    int cost[m + 1][n + 1];
    cost[0][0] = 0;
    FOI(i, 1, m) cost[i][0] = i;
    FOI(j, 1, n) cost[0][j] = j;
    
    FOI(i, 1, m) {
		FOI(j, 1, n) {
			int val = (s1[i - 1] == s2[j - 1] ? 0 : 1);
				cost[i][j] = min(cost[i - 1][j - 1] + val, min(cost[i - 1][j] + 1, cost[i][j - 1] + 1));
		}
	}
    return cost[m][n];
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int N, Q;
	int i, j;
	set< string > Set;
	cin >> N;
	string str[N];
	FOI(i, 0, N-1) {
		cin >> str[i];
		Set.insert(str[i]);
	}
	cin >> Q;
	while (Q--) {
		string S;
		cin >> S;
		if (Set.find(S) != Set.end()) {
			cout << S << " is correct\n";
			continue;
		}
		bool flag = false;
		int A[26], B[26];
		memset(A, 0, sizeof A);
		FOI(i, 0, S.length()) ++A[S[i] - 'a'];
		FOI(i, 0, N-1) {
			memset(B, 0, sizeof B);
			FOI(j, 0, str[i].length()-1) ++B[str[i][j] - 'a'];
			int diff = 0;
			FOI(j, 0, 25) diff += abs(A[j] - B[j]);
			if (diff == 1 || (diff) {
				cout << S << " is a misspelling of " << str[i] << endl;
				flag = true;
				break;
			}
		}
		if (!flag)
			cout << S << " is unknown\n";
	}	
	return 0;
}
