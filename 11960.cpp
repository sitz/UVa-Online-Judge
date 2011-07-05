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

#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)
#define MAX 1000000

int dp[MAX + 1];
bool P[MAX + 1];
vector<int> Prime;
int N;

void seive(){
	memset(P, true, sizeof P);
	Prime.clear();
	P[0] = false; P[1] = false;
	int i;
	FOI(i, 2, MAX){
		if( P[i] ){
			Prime.push_back(i);
			for(int j = 2*i; j <= MAX; j += i)
				P[j] = false;
		}
	}
}

int countDiv(int M){
	int i;
	int ret = 1;
	FOI(i, 0, N){
		if( Prime[i] > M ) break;
		int cnt = 0;
		while( M % Prime[i] == 0 ){
			++cnt;
			M /= Prime[i];
		}
		ret = ret * (cnt + 1);
	}
	return ret;
}

int count(int n){
   int p = 1;
   int factor = 1;
   while (n % 2 == 0) {
      p++;
      n /= 2;
   }
   factor *= p;
   for (int i = 3; i*i <= n; i+=2) {
      p = 1;
      while (n % i == 0) {
         p++;
         n /= i;
      }
      factor *= p;
   }
   if (n > 1) factor *= 2;
   return factor;
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	//seive();
	//N = Prime.size() - 1;
	dp[0] = 0; dp[1] = 1;
	int cmax = 1, cval = 1;
	int i;
	FOI(i, 2, MAX){
		int tmax = count(i);
		if( tmax >= cmax ){
			cmax = tmax;
			cval = i;
		}
		dp[i] = cval;
	}
	int T;
	scanf("%d", &T);
	while( T-- ){
		int M;
		scanf("%d", &M);
		printf("%d\n", dp[M]);
	}
	return 0;
}
