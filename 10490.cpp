#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    int prime[]={2,3,5,7,11,13,17,19,23,29,31};
    for(;;){
            int n,i,ctr=0;
            scanf("%d",&n);
            if(n==0)
                    break;
            if(n==11 || n==23 || n==29){
                     printf("Given number is prime. But, NO perfect number is available.\n");
                     continue;
            }
            for(i=0;i<=10;i++){
                     if(prime[i]==n){
                                     unsigned long long val=(long long)(pow(2.0,n-1)*(pow(2.0,n)-1));
                                     printf("Perfect: %lld!\n",val);
                                     ctr=-1;
                                     break;
                     }
            }
            if(ctr>=0)
                      printf("Given number is NOT prime! NO perfect number is available.\n");
    }
    return 0;
}
