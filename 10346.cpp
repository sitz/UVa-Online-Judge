#include<cstdio>
int main(){
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
                     int total=n;
                     while(n>=k){
                                 int curr=(n/k);
                                 total+=curr;
                                 n%=k;
                                 n+=curr;
                     }
                     printf("%d\n",total);
    }
    return 0;
}
