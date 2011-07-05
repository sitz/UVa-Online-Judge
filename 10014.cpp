#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    int test;
    scanf("%d",&test);
    while(test--){
                  int n,i;
                  scanf("%d",&n);
                  double start=0,end=0,value=0;
                  scanf("%lf",&start);
                  scanf("%lf",&end);
                  for(i=0;i<n;i++){
                                  double carr=0;
                                  scanf("%lf",&carr);
                                  value+=(n-i)*carr;
                  }
                  double sum=(n*start+end-2*value)/(n+1);
                  printf("%.2lf",sum);
                  if(test>0)
                            printf("\n\n");
    }
    return 0;
}
