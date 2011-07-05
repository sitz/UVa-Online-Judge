#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    int n,i,j;
     while(scanf("%d",&n)!=EOF){
                           int price[n],amt;
                           for(i=0;i<n;i++)
                                           scanf("%d",&price[i]);
                           scanf("%d",&amt);
                           sort(price,price+n);
                           int min=0,max=0;
                           for(i=0;i<n;i++){
                           for(j=i;j<n;j++){
                                              if(price[i]+price[j]==amt){
                                                          min=price[i];
                                                          max=price[j];
                                              }
                           }
                           }
                           printf("Peter should buy books whose prices are %d and %d.\n\n",min,max);
     }
    return 0;
}
