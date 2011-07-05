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

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int T;
	cin >> T;
	while( T-- ){
		int S, D;
		cin >> S >> D;
		int A = (S + D);
		int B = (S - D);
		if( A%2 != 0 || A < 0 || B%2 != 0 || B < 0 )
			cout << "impossible" << endl;
		else
			cout << A/2 << " " << B/2 << endl;
	}
	return 0;
}
