#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    for(;;){
            long long n,sqr;
            scanf("%lld",&n);
            if(n==0)
                    break;
            sqr=(int)sqrt(n);
            if(sqr*sqr==n)
                          printf("yes\n");
            else
                          printf("no\n");
    }
    return 0;
}
