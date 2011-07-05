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
#define REP(i, N) for(i=1; i<=N; i++)

#define LIM 100000000
struct Cantor{
       int num;
       int den;
       /*
       Cantor(int n, int d){
                  num = n;
                  den = d;
       }
       */
       
};

Cantor can[LIM+1];

int main(){
    int i, SZ=0;
    bool flag = true;
    for(i=1; ; i++){
             int nu = i;
             int de = 1;
             while(true){
                         Cantor c;
                         c.num = nu;
                         c.den = de;
                         can[SZ] = c;
                         SZ++;
                         if(SZ == LIM){
                               flag = false;
                               break;
                         }
                         if(nu == 1)
                                break;
                         nu--;
                         de++;
                         
             }
             if(!flag)
                      break;
    }
    //cout<<can.size()<<endl;
    int ind;
    while(cin>>ind){
                   cout<<can[ind-1].num<<"/"<<can[ind-1].den<<endl;
    }
    return 0;
}
