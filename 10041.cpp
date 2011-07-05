#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    int test;
    scanf("%d",&test);
    while(test--){
                  int r,i;
                  scanf("%d",&r);
                  int relative[r];
                  for(i=0;i<r;i++)
                                  scanf("%d",&relative[i]);
                  sort(relative,relative+r);
                  int ind=relative[r/2],sum=0;
                  for(i=0;i<r;i++)
                                  sum+=abs(relative[i]-ind);
                  printf("%d\n",sum);
    }
    return 0;
}
