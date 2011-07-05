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
#define PI		acos(-1.0)
#define INF		1<<30
#define EPS		1e-9
#define sqr(x)	(x)*(x)

int main(){
	freopen("testI.txt", "r", stdin);
	freopen("testO.txt", "w", stdout);
	int N;
	bool flag = false;
	while( cin >> N ){
		map<string, int> Map;
		vector<string> nam;
		int i, j;
		FOI(i, 1, N){
			string name;
			cin >> name;
			nam.push_back(name);
			Map[name] = 0;
		}
		FOI(i, 1, N){
			string S, R;
			int A, M;
			cin >> S >> A >> M;
			if( M == 0 )
				continue;
			FOI(j, 1, M){
				cin >> R;
				Map[R] += (A / M);
				Map[S] -= (A / M);
			}
			Map[S] += (A % M);
		}
		if( flag )
			cout << endl;
		FOI(i, 0, N-1)
			cout << nam[i] << " " << Map[nam[i]] << endl;
		flag = true;
	}
	return 0;
}
