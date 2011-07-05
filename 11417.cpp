#include<iostream>
using namespace std;
#define limit 200001
int GCD(long long a, long b){
    if(a==0)
            return b;
    else
            return GCD(b%a,a);
}
int main(){
    long long gcd[limit][limit],k=0,i=0,j=0;
    for(i=1;i<limit;i++)
    for(j=i+1;j<=limit;j++)
                         gcd[i][j]=GCD(i,j);
    for(;;){
            long long n,sum=0;
            cin>>n;
            if(n==0)
                    break;
            for(i=1;i<n;i++)
            for(j=i+1;j<=n;j++)
                            sum+=gcd[i][j];
            cout<<sum<<endl;
    }
    return 0;
}
