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

int main(){
    int test;
    cin>>test;
    while(test--){
                  int64 a, i, j, s=0;
                  cin>>a;
                  if(a<0)
                         a*=-1;
                  for(i=1;s<=a;i++)
                                   s+=i;
                  while((s-a)%2){
                                 s+=i;
                                 i++;
                  }
                  cout<<i-1;
                  if(test > 0)
                          cout<<endl<<endl;
    }
    return 0;
}
