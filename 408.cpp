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
#define REP(i, N)    for(i=1; i<=N; i++)
 
#define INF    INT_MAX
#define EPS    1e-10

int64 GCD(int64 A, int64 B){
      if(B > A)
           return GCD(B, A);
      return B==0?A:GCD(B, A%B);
}

int main(){
    int64 step, mod;
    while(cin>>step>>mod){
                          if(GCD(step, mod) == 1)
                                       printf("%10lld%10lld    Good Choice\n\n", step, mod);
                          else
                              printf("%10lld%10lld    Bad Choice\n\n", step, mod);
    }
    return 0;
}
