#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    double a,b,c;
    while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF){
                                       double s=(a+b+c)/2;
                                       double rad=sqrt((s-a)*(s-b)*(s-c)/s);
                                       printf("The radius of the round table is: %.3lf\n",rad);
    }
    return 0;
}
