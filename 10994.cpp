#include<iostream>
using namespace std;
long long F(long long n){
     if(n==0)
             return 0;
     else if(n%10>0)
               return (n%10);
     else
             return F(n/10);
}
int main(){
    long long F[]
    for(i=1;i<)
    for(;;){
            long long p,q,sum=0,i=0;
            cin>>p>>q;
            if(p<0 && q<0)
                   break;
            for(i=p;i<=q;i++){
                              sum+=F(i);
            }
            cout<<sum<<endl;
    }
    return 0;
}
