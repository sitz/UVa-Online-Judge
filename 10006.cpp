#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    int carmichel[]={561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973};
    for(;;){
            int n,ctr=0;
            scanf("%d",&n);
            if(n==0)
                    break;
            for(int i=0;i<15;i++){
                    if(carmichel[i]==n){
                                       ctr=-1;
                                       break;
                    }
            }
            if(ctr<0)
                     printf("The number %d is a Carmichael number.\n",n);
            else
                     printf("%d is normal.\n",n);
    }
    return 0;
}
