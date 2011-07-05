#include<iostream>
using namespace std;

int main(){
    long long fib[51]={0};
    fib[1]=1;
    fib[2]=2;
    for(int i=3;i<51;i++)
            fib[i]=fib[i-1]+fib[i-2];
    for(;;){
            int n;
            cin>>n;
            if(n==0)
                    break;
            cout<<fib[n]<<endl;
    }
    return 0;
}
            
