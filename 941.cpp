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
    while(test--){
                  char str[25];
                  int N;
                  cin>>str>>N;
                  int len=strlen(str);
                  sort(str, str+len);
                  while(N--){
                            next_permutation(str, str+len);
                  }
                  cout<<str<<endl;
    }
    return 0;
}
