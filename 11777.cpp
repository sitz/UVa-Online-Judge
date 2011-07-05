#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef long double ldouble;
using namespace std;
int main(){
    int test;
    scanf("%d",&test);
    for(int z=1;z<=test;z++){
            double marks[4],clasTest[3],sum=0;
            int i;
            for(i=0;i<4;i++){
                            scanf("%lf",&marks[i]);
                            sum+=marks[i];
            }
            for(i=0;i<3;i++){
                            scanf("%lf",&clasTest[i]);
            }
            sort(clasTest,clasTest+3);
            sum+=((clasTest[1]+clasTest[2])/2.0);
            if(sum>=90){
                 printf("Case %d: A\n",z);
                 continue;
            }
            if(sum>=80 && sum<90){
                 printf("Case %d: B\n",z);
                 continue;
            }
            if(sum>=70 && sum<80){
                 printf("Case %d: C\n",z);
                 continue;
            }
            if(sum>=60 && sum<70){
                 printf("Case %d: D\n",z);
                 continue;
            }
            else
                printf("Case %d: F\n",z);
    }
    return 0;
}
