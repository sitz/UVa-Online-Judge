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
#define PI     acos(-1.0)
#define INF    1<<30
#define EPS    1e-9
#define sqr(x) (x)*(x)

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	while( T-- ){
		   int M, C;
		   scanf("%d%d", &M, &C);
		   vector< vector<int> > Vec(C);
		   int i, m, c;
		   FOI(i, 0, C-1){
		   		  int K, temp;
		   		  scanf("%d", &K);
		   		  while( K-- ){
				  		 scanf("%d", &temp);
				  		 Vec[i].push_back(temp);
  		 		  }
 		   }

		   int dp[M + 1][C + 1];
 		   memset(dp, -1, sizeof(dp));
 		   FOI(m, 0, M){
		   		  dp[m][0] = 0;
  		   		  FOI(c, 1, C){
				  		 FOI(i, 0, Vec[c - 1].size()-1){
						 		int ci = Vec[c - 1][i];
						 		if( m >= ci && dp[m - ci][c - 1] != -1 )
						 			dp[m][c] = max(dp[m][c], dp[m - ci][c - 1] + ci);
			 			 }
	  		 	  }
  		   }
  		   if( dp[M][C] == -1 )
  		   	   printf("no solution\n");
  		   else
  		   	   printf("%d\n", dp[M][C]);
 	}
	//system("pause");
    return 0;
}
