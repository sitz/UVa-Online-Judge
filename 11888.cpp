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

char str[200005];
int L;

bool isPal(int I, int J){
	 int i;	 
	 FOI(i, 0, (J - I)/2)
	 	 if( str[I + i] != str[J - i] )
		  	return false;
	 return true;
}
	 
int main(){
	int T;
	scanf("%d", &T);
	while( T-- ){
		   scanf("%s", str);
 		   L = strlen( str );
 		   bool ail = false;
		   int i;
 		   FOI(i, 0, L-2){
		   		  if( isPal(0, i) && isPal(i+1, L-1) ){
 	  		   	  	  printf("alindrome\n");
 	  		   	  	  ail = true;
 	  		   	  	  break;
				  }
           }
		   if( !ail ){
		   	   if( isPal(0, L-1) )
			   	   printf("palindrome\n");
				else
					printf("simple\n");
			}
 	}	   	
    return 0;
}
