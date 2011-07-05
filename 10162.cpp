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

int64 power(int64 b, int64 n){
      if(n==0)
              return 1;
      int64 x = power(b, n/2);
      if(n%2 == 0)
             return (x*x)%100000;
      else
          return (x*x*b)%100000;
}

int main(){
    int lDigit[101]={0}, i;
    for(i=1; i<=100; i++)
             lDigit[i] = ( lDigit[i-1] + power(i, i) )%100000;
    while(true){
                string str;
                cin>>str;
                if(str == "0")
                       break;
                       
                int ind, len=str.length();
                
                if( len == 1 )
                    ind = str[len-1];
                else
                    ind = (str[len-2]-'0')*10 + (str[len-1]-'0');
                
                cout<<lDigit[ind]<<endl;
    }
    return 0;
}
