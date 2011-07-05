#include<cstdio>
int main(){
    int i,j;
    while(scanf("%d%d",&i,&j)!=EOF){
    int x=0,y=0,k=0,max=0;
    x=(i>j)?i:j;
    y=(i<j)?i:j;
          for(k=y;k<=x;k++){
              int n=k;
              int nc=0;
              while(n!=1){
                  nc++;
                  if(n%2!=0)
                      n=3*n+1;
                  else
                      n=n/2;
              }
              if(nc>max)
                       max=nc;
          }
          printf("%d %d %d\n",i,j,max+1);
    }
    return 0;
}
