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
    for(;;){
            int i,j,u,v;
            cin>>i>>j>>u>>v;
            if(i==0 && j==0 && u==0 && v==0)
                    break;
            cout << ( (i == u && j == v) ? 0 : (i == u || j == v || abs(i - u) == abs(j - v)) ? 1 : 2 ) << endl;
    }
    return 0;
}
