#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
            long long n;
            cin>>n;
            long long val=abs((((((n*567)/9)+7492)*235)/47)-498);
            val/=10;
            int tens=val%10;
            cout<<tens<<endl;
    }
    return 0;
}
