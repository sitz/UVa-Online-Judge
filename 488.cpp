#include<iostream>
using namespace std;

int main(){
    int test=0,ampl=0,freq=0,i=0,j=0,t=0,k=0;
    cin>>test;
    for(t=1;t<=test;t++){
            cin>>ampl>>freq;
            for(i=1;i<=freq;i++){
                                 for(j=1;j<ampl;j++){
                                                     for(k=1;k<=j;k++)
                                                                      cout<<j;
                                                     cout<<endl;
                                 }
                                 for(j=ampl;j>=1;j--){
                                                      for(k=1;k<=j;k++)
                                                                       cout<<j;
                                                      cout<<endl;
                                 }
            if((t==test)&&(i==freq))
                          break;
            cout<<endl;
            }
    }
    return 0;
}
