#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef long double ldouble;
using namespace std;
int main(){
    uint64 m,n;
    for(;;){
            cin>>m>>n;
            if(m<n){
                    uint64 temp=m;
                    m=n;
                    n=temp;
            }
            if(m==0 && n==0)
                    break;
            uint64 val= m*(m-1)*n+n*(n-1)*m+(n*(n-1)*(2*n-1)/6-(n-1)*n/2)*4+2*n*(n-1)*(m-n+1);
            cout<<val<<endl;
    }
    return 0;
}
