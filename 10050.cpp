#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    int test;
    scanf("%d",&test);
    while(test--){
                  int n,p,i,j;
                  scanf("%d",&n);
                  int day[3651]={0};
                  scanf("%d",&p);
                  for(i=1;i<=p;i++){
                                   int hpar;
                                   scanf("%d",&hpar);
                                   for(j=hpar;j<=n;j+=hpar)
                                                       day[j]=1;
                  }
                  for(i=6;i<=n;i+=7){
                                     day[i]=0;
                                     day[i+1]=0;
                  }
                  int cnt=0;
                  for(i=1;i<=n;i++){
                                    if(day[i]==1)
                                                 cnt++;
                  }
                  printf("%d\n",cnt);
    }
    return 0;
}
