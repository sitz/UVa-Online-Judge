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
	freopen("testI.txt", "r", stdin);
	freopen("testO.txt", "w", stdout);
	int Test;
	cin >> Test;
	while( Test-- ){
		int N, T, M;
		cin >> N >> T >> M;
		int i, arr[M];
		FOI(i, 0, M-1)
			cin >> arr[i];
		int trip = 0, time = 0;
		for (i = min(N-1, M-1); i < M; i += N){
			time = max(time, arr[i]);
		}
		time = arr[M - 1];
		trip  = ceil( (double)M / (double)N );
		time += (2 * T * trip);
		cout << time << " " << trip << endl;
	}
	return 0;
}
