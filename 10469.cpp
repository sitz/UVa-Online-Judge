#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    unsigned long long a,b;
    while(scanf("%ld%ld",&a,&b)!=EOF){
                unsigned long long c=a^b;
                printf("%ld\n",c);
    }
    return 0;
}
