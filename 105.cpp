#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    int build[20002]={0},max=0,i,start,end,height;
    while(scanf("%d%d%d",&start,&height,&end)!=EOF){
                max=max>start?max:start;
                max=max>end?max:end;
                for(i=start;i<=end;i++){
                           if(height>build[i])
                                              build[i]=height;
                }
    }
    for(i=1;i<=max;i++){
                       if(build[i]!=build[i-1]){
                                   int ind=i;
                                   ind=build[i]<build[i-1]?i-1:i;
                                   printf("%d %d ",ind,build[i]);
                       }
    }
    printf("%d 0",max);
    system("pause");
    return 0;
}
