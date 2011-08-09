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
typedef long long int64;

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	string Dic = "0123456789ABCDEF";
	string S;
	int64 A, B;
	while (cin >> S >> A >> B) {
		int64 i, j;
		int64 V = 0, mul = 1;
		vector< char > C;
		int L = S.length() - 1;
		FOD(i, L, 0) {
			if (isalpha(S[i]))
				V += (S[i] - 'A' + 10) * mul;
			else
				V += (S[i] - '0') * mul;
				
			mul *= A;
		}
		while (V > 0) {
			C.push_back(Dic[V % B]);
			V /= B;
		}
		if (C.size() == 0)
			C.push_back('0');
		string O = "";
		if (C.size() > 7)
			O = "ERROR";
		else {
			O = "";
			reverse(C.begin(), C.end());
			L = C.size() - 1;
			FOI(i, 0, L)
				O += C[i];
		}
		printf("%7s\n", O.c_str());
	}
	return 0;
}
