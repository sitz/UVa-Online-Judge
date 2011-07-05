#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    for(int z=1;;z++){
            int n,query,i;
            scanf("%d%d",&n,&query);
            if(n==0 && query==0)
                    break;
            int num[n];
            for(i=0;i<n;i++)
                            scanf("%d",&num[i]);
            sort(num,num+n);
            printf("CASE# %d:\n",z);
            while(query--){
                           int find,ctr=0;
                           scanf("%d",&find);
                           for(i=0;i<n;i++){
                                            if(num[i]==find){
                                                             printf("%d found at %d\n",find,i+1);
                                                             ctr=-1;
                                                             break;
                                            }
                           }
                           if(ctr>=0)
                                     printf("%d not found\n",find);
            }
    }
    return 0;
}
