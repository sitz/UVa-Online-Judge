#include<iostream>
#include<cstdio>
#include<cmath>
#include<math.h>
#include<algorithm>
using namespace std;
int main(){
    int test;
    scanf("%d",&test);
    while(test--){
                  long double Y;
                  scanf("%lf",&Y);
                  printf("%.0lf\n",sqrtl(Y));
    }
    return 0;
}
