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
	map<char, int> Map;
	Map['q'] = 1; Map['a'] = 1; Map['z'] = 1; 
	Map['w'] = 2; Map['s'] = 2; Map['x'] = 2; 
	Map['e'] = 3; Map['d'] = 3; Map['c'] = 3; 
	Map['r'] = 4; Map['f'] = 4; Map['v'] = 4; Map['t'] = 4; Map['g'] = 4; Map['b'] = 4; 
	//Special Case : ' ' -- > 5, 6
	Map['y'] = 7; Map['h'] = 7; Map['n'] = 7; Map['u'] = 7; Map['j'] = 7; Map['m'] = 7;
	Map['i'] = 8; Map['k'] = 8; Map[','] = 8; 
	Map['o'] = 9; Map['l'] = 9; Map['.'] = 9; 
	Map['p'] = 10; Map[';'] = 10; Map['/'] = 10; 
	
	int F, N;
	while (cin >> F >> N) {
		int i, j;
		bool hand[11];
		memset(hand, true, sizeof hand);
		FOI(i, 1, F) {
			int ind;
			cin >> ind;
			hand[ind] = false;
		}
		vector< string > Vec(N);
		vector< string > Ans, Print;
		int L = 0;
		FOI(i, 0, N-1) {
			cin >> Vec[i];
			L = max(L, (int)Vec[i].length());
		}
		do {
			FOI(i, 0, N-1) {
				bool flag = true;
				if ((int)Vec[i].length() == L) {
					FOI(j, 0, L-1) {
						if ( !hand[Map[Vec[i][j]]] ) {
							flag = false;
							break;
						}
					}
					if (flag) Ans.push_back(Vec[i]);
				}
			}
			if (Ans.size() > 0) break;
		}while (L--);
		
		int S = Ans.size();
		sort(Ans.begin(), Ans.end());
		FOI(i, 0, S-1) {
			if (i > 0 && Ans[i] == Ans[i - 1]) continue;
			else Print.push_back(Ans[i]);
		}
		
		S = Print.size();
		cout << S << endl;
		FOI(i, 0, S-1)
			cout << Print[i] << endl;
	}
	return 0;
}
