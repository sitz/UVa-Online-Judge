#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    int test;
    scanf("%d",&test);
    while(test--){
                  int total,lines,i,value=0;
                  scanf("%d%d",&total,&lines);
                  for(i=0;i<lines;i++){
                          int n;
                          int val=1;
                          scanf("%d",&n);
                          while(n--){
                                     int toffee;
                                     scanf("%d",&toffee);
                                     val=(val*toffee)%total;
                          }
                          value+=val;
                  }
                  value%=total;
                  printf("%d\n",value);
                  
    }
    return 0;
}
