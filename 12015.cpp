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
	for (int t = 1; t <= T; t++){
		string url[10];
		int val[10];
		int M = 0, i;
		for (i = 0; i < 10; i++){
			cin >> url[i] >> val[i];
			M = max(val[i], M);
		}
		cout << "Case #" << t << ":\n";
		for (i = 0; i < 10; i++)
			if( val[i] == M )
				cout << url[i] << endl;
	}
	return 0;
}
