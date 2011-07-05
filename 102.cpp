#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    string str[6]={"BCG","BGC","CBG","CGB","GBC","GCB"};
    int b1,b2,b3;
    int c1,c2,c3;
    int g1,g2,g3;
    while(scanf("%d%d%d%d%d%d%d%d%d",&b1,&g1,&c1,&b2,&g2,&c2,&b3,&g3,&c3)!=EOF){
                          int b=b1+b2+b3;
                          int g=g1+g2+g3;
                          int c=c1+c2+c3;
                          int val[6]={b-b1+c-c2+g-g3,b-b1+g-g2+c-c3,c-c1+b-b2+g-g3,c-c1+g-g2+b-b3,g-g1+b-b2+c-c3,g-g1+c-c2+b-b3};
                          int min=val[0];
                          int ind=0,i;
                          for(i=1;i<6;i++){
                                  if(min>val[i]){
                                                 min=val[i];
                                                 ind=i;
                                  }
                          }
                          cout<<str[ind]<<" "<<min<<endl;
    }
    return 0;
}
