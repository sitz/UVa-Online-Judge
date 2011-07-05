#include<iostream>
#include<cmath>
using namespace std;

int main(){
    long long n=0,p=0,k=0;
    while(cin>>n>>p){
                    k=exp(log(p)/n);
                    cout<<(long long int)k<<endl;
    }
    return 0;
}
