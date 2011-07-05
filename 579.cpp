#include<iostream>
using namespace std;

int main(){
    for(;;){
            int H,M;
            scanf("%d:%d",&H,&M);
            if(H==0 && M==0)
                    break;
            double ha=H*30+M/2;
            double ma=M*6;
            double hc=360-ha;
            double ang1=ha-ma;
            double ang2=hc+ma;
            double angle=(ang1<=ang2)?ang1:ang2;
            printf("%.3f\n",angle);
    }
    return 0;
}
