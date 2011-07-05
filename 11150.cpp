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
	int N;
	while( cin >> N ){
		int cnt = N;
		if( N % 2 == 0 )
			cnt++;
		while( N >= 3 ){
			int temp = N/3;
			cnt += temp;
			N %= 3;
			N += temp;
		}
		cout << cnt << endl;
	}
	return 0;
}
