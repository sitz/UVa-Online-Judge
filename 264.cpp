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
       int64 num;
       int64 den;
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
        if(i%2==0){
             int64 nu = 1;
             int64 de = i;
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
                         if(de == 1)
                                break;
                         nu++;
                         de--;
                         
             }
        }
        else{
             int64 nu = i;
             int64 de = 1;
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
        }
             if(!flag)
              break;
    }
    //cout<<can.size()<<endl;
    int64 ind;
    bool nl = false;
    while(cin>>ind){
                    if(nl == true)
                          cout<<endl;
                   cout<<"TERM "<<ind<<" IS "<<can[ind-1].num<<"/"<<can[ind-1].den;
                   nl = true;
    }
    //system("pause");
    return 0;
}
