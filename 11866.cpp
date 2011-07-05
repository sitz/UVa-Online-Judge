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
    int64 test;
    cin>>test;
    while(test--){
                  int64 X, Y, tot=0;
                  int64 i, j, k;
                  cin >> X >> Y ;
                  for(i=X; i<=Y; i++){
                           for(j=i; j<=Y; j++){
                                      int64 val = min(i+j-1, Y) - j + 1;
                                      tot += val;
                           }
                  }
                  cout << tot << endl;
    }
    return 0;
}
