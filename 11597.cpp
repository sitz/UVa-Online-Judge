#include<iostream>
using namespace std;

int main(){
    long long n=0;
    for(int i=1;;i++){
            cin>>n;
            if(n==0)
                    break;
            cout<<"Case "<<i<<": "<<n/2<<endl;
    }
    return 0;
}
