#include<iostream>
using namespace std;
long long H(long long a);

int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
            long long n;
            cin>>n;
            long long val=H(n);
            cout<<val<<endl;
    }
    return 0;
}

long long H(long long a){
     long long res = 0;
     for(long long i=1;i<=a;i++){
            res+=(a/i);
      }
      return res;
}
