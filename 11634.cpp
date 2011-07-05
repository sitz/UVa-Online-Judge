#include<iostream>
using namespace std;

int main(){
    for(;;){
            long long a=0,na=0,cnt=0;
            cin>>a;
            if(a==0)
                    break;
            long long oa=a;
            while(na!=a){
                         na=((oa*oa)/100)%10000;
                         na=oa;
                         cnt++;
            }
            cout<<cnt<<endl;
    }
    return 0;
}
            
