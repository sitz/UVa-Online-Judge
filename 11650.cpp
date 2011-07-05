#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
            int OH,NH,OM,NM,OT,NT;
            scanf("%d:%d",&OH,&OM);
            OT=OH*60+OM;
            NT=720-OT;
            NH=abs(NT)/60;
            if(NT<0){
                     NT+=60;
                     NH=11;
            }
            if(NH==0)
                     NH+=12;
            NM=abs(NT)%60;
            printf("%2.2d:%2.2d\n",NH,NM);
    }
    return 0;
}
