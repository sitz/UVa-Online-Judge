#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int main(){
    for(;;){
            int L;
            cin>>L;
            if(L==0)
                    break;
            string str;
            cin>>str;
            int dr,dd,d=L;
            for(int i=0;i<L;i++){
                    if(str[i]=='Z'){
                                   d=0;
                                   break;
                    }
                    if(str[i]=='R')
                                   dr=i;
                    if(str[i]=='D')
                                   dd=i;
                    if(abs(dr-dd)<d)
                                    d=abs(dr-dd);
            }
            cout<<d<<endl;
    }
    return 0;
}
