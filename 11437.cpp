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
    int test;
    cin>>test;
    while(test--){
                  ldouble Ax,Ay,Bx,By,Cx,Cy;
                  cin>>Ax>>Ay>>Bx>>By>>Cx>>Cy;
                  ldouble sideA,sideB,sideC;
                  sideA=sqrt((Ax-Bx)*(Ax-Bx) + (Ay-By)*(Ay-By));
                  sideB=sqrt((Bx-Cx)*(Bx-Cx) + (By-Cy)*(By-Cy));
                  sideC=sqrt((Ax-Cx)*(Ax-Cx) + (Ay-Cy)*(Ay-Cy));
                  ldouble peri=(sideA+sideB+sideC)/2;
                  ldouble area=peri*(peri-sideA)*(peri-sideB)*(peri-sideC);
                  area=sqrt(area)/7;
                  cout<<(long long)area<<endl;
    }
    return 0;
}
