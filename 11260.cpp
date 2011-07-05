#include<iostream>
#include<cmath>
#define limit (long long)pow(2.0,20.0)
#define max 100000000
using namespace std;
int main(){
    long long root[limit+1],i;
    for(i=1;i<=limit;i++)
                         root[i]=(root[i-1]+(long long)sqrt(2*i-1))%max;
    for(;;){
            long long n;
            cin>>n;
            if(n==0)
                    break;
            cout<<root[n]<<endl;
    }
    return 0;
}
