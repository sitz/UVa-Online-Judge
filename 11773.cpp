#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef long double ldouble;
using namespace std;
int isPrime(int64 num){
    int64 lim=(int64)sqrt(num);
    lim=lim<100?lim:100;
    for(int i=2;i<=lim;i++)
            if(num%i==0)
                        return 0;
    return 1;
}
int main(){
    int test,z;
    scanf("%d",&test);
    for(z=1;z<=test;z++){
              int64 K;
              scanf("%lld",&K);
              if(K%2!=0){
              if(isPrime(K)){
                        printf("Case %d: Impossible\n",z);
                        continue;
              }
              }
              int64 width=(int64)sqrt(K);
              int64 mat[10000][4];
              int lim=0;
              while(width-->2){
                               int64 length=K/width;
                               if(length!=width && length*width==K){
                                                mat[lim][0]=length;
                                                mat[lim][1]=width;
                                                mat[lim][2]=length-width;
                                                mat[lim][3]=2*(length+width);
                                                lim++;
                               }
              }
              int ind=0,i;
              for(i=1;i<lim;i++){
                      if(mat[i][2]>mat[ind][2]){
                                               ind=i;
                                               continue;
                      }
                      if(mat[i][2]==mat[ind][2] && mat[i][3]>mat[ind][3])
                                                ind=i;
              }
                        printf("Case %d: %lld %lld\n",z,mat[ind][0],mat[ind][1]);
    }
    return 0;
}
