#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    for(int z=1;;z++){
            string str;
            int i;
            getline(cin,str,'\n');
            if(str=="EOF" || str=="\0")
                          break;
            int len=str.length();
            int counter[len];
            counter[0]=0;
            for(i=1;i<len;i++){
                    if(str[i]!=str[i-1])
                                        counter[i]=counter[i-1]+1;
                    else
                                        counter[i]=counter[i-1];
            }
            printf("Case %d:\n",z);
            int cases;
            scanf("%d\n",&cases);
            while(cases--){
                           int a,b;
                           scanf("%d %d\n",&a,&b);
                           if(counter[a]==counter[b])
                                                     printf("Yes\n");
                           else
                                                     printf("No\n");
            }
    }
    return 0;
}
