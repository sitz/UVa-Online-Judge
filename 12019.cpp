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

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;

#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	string day[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	int month[]  = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	vector< vector<int> > week(12);
	int S = 5;
	int i, j;
	FOI(i, 0, 11){
		FOI(j, 0, month[i]-1){
			week[i].push_back(S);
			S = (S + 1) % 7;
		}
	}
	int T;
	cin >> T;
	while( T-- ){
		int D, M;
		cin >> M >> D;
		cout << day[week[M - 1][D - 1]] << endl;
	}
	return 0;
}

