#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef long double ldouble;
using namespace std;
#define square(x) (x)*(x)

int64 BigMod(int64 b, int64 e, int64 n){
      if(e == 0)
           return 1;
      else if(e%2 == 0)
           return ( square(BigMod(b, e/2, n)) ) % n;
      else
          return ( (b%n) * BigMod(b, e-1, n) ) % n;
}

int main(){
    int64 base, exponent, n;
    while(cin>>base>>exponent>>n){
                                  cout<<BigMod(base, exponent, n)<<endl;
    }
    return 0;
}
