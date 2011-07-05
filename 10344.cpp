#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    for(;;){
            int num[5]={0},i=0,j=0,k=0,l=0,ctr=0;
            for(i=0;i<5;i++)
                            cin>>num[i];
            if(num[0]==0 && num[1]==0 && num[2]==0 && num[3]==0 && num[4]==0)
                                break;
            sort(num,num+5);
            do{
            for(i=0;i<=2;i++){
            long long v1=0;
            if(i==0)
                    v1=num[0]+num[1];
            else if(i==1)
                    v1=num[0]-num[1];
            else
                    v1=num[0]*num[1];
            for(j=0;j<=2;j++){
            if(j==0)
                    v1+=num[2];
            else if(j==1)
                    v1-=num[2];
            else
                    v1*=num[2];
            for(k=0;k<=2;k++){
            if(k==0)
                    v1+=num[3];
            else if(k==1)
                    v1-=num[3];
            else
                    v1*=num[3];
            for(l=0;l<=2;l++){
            if(l==0)
                    v1+=num[4];
            else if(l==1)
                    v1-=num[4];
            else
                    v1*=num[4];
                    if(v1==23){
                               ctr=-1;
                               break;
                    }
            }
            if(ctr<0)
                     break;
            }
            if(ctr<0)
                     break;
            }
            if(ctr<0)
                     break;
            }
            }while(next_permutation(num,num+5) || ctr>=0);
            if(ctr<0)
                     cout<<"Possible\n";
            else
                     cout<<"Impossible\n";
    }
    return 0;
}
