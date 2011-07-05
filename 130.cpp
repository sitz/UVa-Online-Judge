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

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int64 josephus(int64 n, int64 k){
      if(n==1)
              return 0;
      return (josephus(n-1, k) + k)%n;
}
int main(){
    while(true){
                int64 n, k;
                scanf("%lld%lld", &n, &k);
                if(n==0 && k==0)
                        break;
                int64 val = josephus(n ,k) + 1;
                printf("%lld\n", val);
    }
    return 0;
}
