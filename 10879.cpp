#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
            int K=0;
            cin>>K;
            int N1=0,N2=0;
            for(int j=2;j<=sqrt(K);j++){
                    if(j*(K/j)==K){
                                   N1=j;
                                   break;
                    }
            }
            for(int j=N1+1;j<=sqrt(K);j++){
                    if(j*(K/j)==K && j!=N1 && j!=(K/N1)){
                                   N2=j;
                                   break;
                    }
            }
            cout<<"Case #"<<i<<": "<<K<<" = "<<N1<<" * "<<K/N1<<" = "<<N2<<" * "<<K/N2<<endl;
    }
    return 0;
}
