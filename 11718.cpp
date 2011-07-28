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

#define FOI(i, A, B) for (i = A; i <= B; i++)
#define FOD(i, A, B) for (i = A; i >= B; i--)
#define PI     acos(-1.0)
#define INF    1<<30
#define EPS    1e-9
#define sqr(x) (x)*(x)

int64 power(int64 B, int64 N, int64 MOD) {
	  if (N == 0) return 1 % MOD;
	  if (N == 1) return B % MOD;
	  
	  int64 V = power(B, N/2, MOD);
	  V = (V %MOD * V %MOD) %MOD;
	  
	  if (N & 1) 
	  	 V = (V %MOD * B %MOD) %MOD;
 	 
 	 return V;
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int T, t, i;
	cin >> T;
	FOI(t, 1, T) {
		int64 N, K, MOD;
		int64 sum = 0;
	
		cin >> N >> K >> MOD;
		FOI(i, 1, N) {
			int I;
			cin >> I;
			sum = (sum + I) % MOD;
		}
 	
 		int64 ansA = sum % MOD;
 		int64 ansB = power(N, K - 1, MOD) % MOD;
 		int64 ansC = K % MOD;
 		int64 ans  = (ansA * ansB * ansC) % MOD;
 	
 		cout << "Case " << t << ": " << ans << endl;
	}
	//system("pause");
    return 0;
}
