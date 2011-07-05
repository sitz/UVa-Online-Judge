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
	while( true ){
		   int N, M;
		   cin >> N >> M;
		   if( N == 0 && M == 0 )
		   	   break;
		   int head[N], nite[M];
		   int i, j;
		   FOI(i, 0, N-1)
		   		  cin >> head[i];
 		   FOI(i, 0, M-1)
 		   		  cin >> nite[i];
  		   sort(nite, nite + M);
  		   bool flag = true;
  		   int cost = 0;
  		   FOI(i, 0, N-1){
		   		  FOI(j, 0, M-1){
				  		 if( nite[j] >= head[i] ){
				  		 	 cost += nite[j];
				  		 	 nite[j] = -1;
				  		 	 break;
						 }
		  		  }
		  		  if( j == M ){
		  	  	  	  flag = false;
		  	  	  	  break;
				  }
   		   }
   		   if( !flag )
   		   	   cout << "Loowater is doomed!" << endl;
	   	   else
	   	   	   cout << cost << endl;
 	}
	//system("pause");
    return 0;
}
