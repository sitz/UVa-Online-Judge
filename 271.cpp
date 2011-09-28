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

string Ap = "pqrstuvwxyz";
string Pe = "CDEI";
set< char > Alp, Pre, Set;

bool check(string S) {
	int L = S.length();
	string A = "";
	string B = S.substr(1);
	
	if (S == "")
		return false;
	
	if (L == 1) {
		if (Set.find(S[0]) != Set.end())
			return true;
		return false;
	}
	
	if (S[0] == 'N')
		return check(B);
	else if (S[0] == 'C' || S[0] == 'D' || S[0] == 'E' || S[0] == 'I') {
		int i;
		FOI(i, 1, L-2) {
			A += S[i];
			B.erase(0, 1);
			if (check(A) && check(B)) return true;
		}
		return false;
	}
	else return false;
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int i = 0;
	FOI(i, 0, Ap.length()-1)
		Alp.insert(Ap[i]);
	FOI(i, 0, Pe.length()-1)
		Pre.insert(Pe[i]);
	string str;
	while (getline(cin, str)) {
		int L = str.length()-1;
		int S = 0;
		FOD(i, L, 0) {
			if (Alp.find(str[i]) != Alp.end())
				++S;
			else if (Pre.find(str[i]) != Pre.end()) {
				if (S >= 2) --S;
				else {
					S = 0;
					break;
				}
			}
			else if (str[i] == 'N') {
				if (S < 1) {
					S = 0;
					break;
				}
				else
					S = S;
			}
			else {
				S = 0;
				break;
			}
		}
		if (S == 1) cout << "YES\n";
		else		cout << "NO\n";
	}
	return 0;
}
