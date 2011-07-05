#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    double a,b,c;
    while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF){
                double s=0.5*(a+b+c);
                double area=s*(s-a)*(s-b)*(s-c);
                if(area<=0){
                           printf("-1.000\n");
                           continue;
                }
                else{
                     area=4*sqrt(area)/3;
                     printf("%.3lf\n",area);
                }
    }
    return 0;
}
