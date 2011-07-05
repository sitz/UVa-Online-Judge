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

long endianSolBits(long x){
   long temp = 0;   // variable to hold result
   int j;

   for (j=0; j<32; j++){
      if (x&(1<<j)){   // check every bits
         temp|= 1<<(3-j/8)*8+(j%8);   // set bits accordingly ;)
      }
   }
   return temp;
}

int main(){
    long x;    
    while(cin>>x)
                 cout<<x<<" converts to "<<endianSolBits(x)<<endl;
    return 0;
}
