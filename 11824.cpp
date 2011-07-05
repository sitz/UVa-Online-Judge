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
                  int64 temp, n=0, i=0;
                  int64 land[40];
                  while(true){
                              cin>>temp;
                              if(temp == 0)
                                      break;
                              land[n++] = temp;
                  }
                  sort(land, land+n);
                  int64 gtot=0;
                  for(i=n-1; i>=0; i--){
                             gtot += (int64) ( 2 * pow(land[i], (double)(n-i)) );
                             if(gtot > 5000000)
                                     break;
                  }
                  if(gtot < 5000000)
                          cout<<gtot<<endl;
                  else
                      cout<<"Too expensive"<<endl;
    }
    return 0;
}
