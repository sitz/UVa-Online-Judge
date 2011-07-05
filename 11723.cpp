#include<iostream>
using namespace std;

int main(){
    for(int j=1;;j++){
            int R,N;
            cin>>R>>N;
            if(R==0 && N==0)
                    break;
            int pre=-1;
            for(int i=0;i<=26;i++){
                    if(N*(1+i)>=R){
                                   pre=i;
                                   break;
                    }
            }
            if(pre>=0)
                      cout<<"Case "<<j<<": "<<pre<<endl;
            else
                      cout<<"Case "<<j<<": "<<"impossible"<<endl;
    }
    return 0;
}
