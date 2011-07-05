#include<iostream>
using namespace std;

int main(){
    for(;;){
            long long m=0,n=0;
            cin>>m>>n;
            if(m==-1 && n==-1)
                     break;
            long long cnt=0;
            for(long long i=m;i<=n;i++){
                    long long no=i;
                    if(no==0)
                             cnt++;
                    while(no>0){
                                long long rem=no%10;
                                if(rem==0)
                                          cnt++;
                                no/=10;
                    }
            }
            cout<<cnt<<endl;
    }
    return 0;
}
