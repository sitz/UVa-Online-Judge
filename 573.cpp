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

#define EPS	0.0000000001

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	while( true ){
		double H, U, D, F;
		cin >> H;
		if( H <= 0 )
			break;
		cin >> U >> D >> F;
		F = (U * F)/100.0;
		
		int day = 1;
		double cur = 0.0;
		while( true ){
			cur += U;
			if( cur > H ){
				cout << "success on day " << day << endl;
				break;
			}
			U = max(U - F, 0.0);
			cur -= D;
			if( cur < 0.0 ){
				cout << "failure on day " << day << endl;
				break;
			}
			day++;
		}
	}
	return 0;
}
