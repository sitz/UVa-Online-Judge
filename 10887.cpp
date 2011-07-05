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
#include <complex>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <ctime>
using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

#define FOI(I, A, B)	for (I=A; I<=B; I++)
#define FOD(I, A, B)	for (I=A; I>=B; I--)

int strToint(string str){
		stringstream sstr;
		int I;
		sstr << str;
		sstr >> I;
		return I;
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	string str;
	int T, t;
	getline(cin, str);
	T = strToint(str);
	FOI(t, 1, T){
		int i, j;
		int M, N;
		getline(cin, str);
		stringstream sstr;
		sstr << str;
		sstr >> M >> N;
		string sA[M], sB[N];
		FOI(i, 0, M-1)
			getline(cin, sA[i]);
		FOI(i, 0, N-1)
			getline(cin, sB[i]);
			
		set<string> ss;
		FOI(i, 0, M-1){
			FOI(j, 0, N-1)
				ss.insert( sA[i] + sB[j] );
		}
				
		cout << "Case " << t << ": " << ss.size() << endl;
	}
	return 0;
}
