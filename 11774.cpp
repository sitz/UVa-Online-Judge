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
    uint64 a,b,c;
    int test;
    cin>>test;
    for(int z=1;z<=test;z++){
            cin>>a>>b;
            if(a==b)
                    cout<<"Case "<<z<<": 2\n";
            else
                    cout<<"Case "<<z<<": "<<a+b<<endl;
    }
    return 0;
}
