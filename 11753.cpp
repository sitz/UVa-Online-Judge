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

int fun(int vec[], int N){
	int i = 0, j = N - 1;
	int D = 0;
	while(i < j){
		if(vec[i] == vec[j]){
			++i;
			--j;
		}
		else{
			++i;
			++D;
		}
	}
	return D;
}
int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int T, t;
	cin >> T;
	FOI(t, 1, T){
		int N, K;
		cin >> N >> K;
		int vec[N];
		int i, j;
		FOI(i, 0, N-1)
			cin >> vec[i];
		int D1 = fun(vec, N);
		reverse(vec, vec + N);
		int D2 = fun(vec, N);
		int D = min(D1, D2);
		if(D < 1)
			cout << "Case " << t << ": " << "Too easy" << endl;
		else if(D > K)
			cout << "Case " << t << ": " << "Too difficult" << endl;
		else
			cout << "Case " << t << ": " << D << endl;
	}
	return 0;
}

