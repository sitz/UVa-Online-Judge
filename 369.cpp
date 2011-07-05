#include<iostream>
#include<stdio.h>

using namespace std;

long long fact(long long x,long long y)
{
     long long a,b,fact_a=1,fact_b=1;
     a=x>2*y?(x-y):y;
     b=x<2*y?(x-y):y;
     for(long long j=1;j<=b;j++)
     {
             fact_b*=j;
     }
     for(long long i=a+1;i<=x;i++)
     {
             fact_a*=i;
     }
     return (fact_a/fact_b);
}

int main()
{
    long long M,N,C;
    for(;;)
    {
           cin>>N>>M;
           if(N==0 && M==0)
           break;
                         C=fact(N,M);
                         cout<<N<<" things taken "<<M<<" at a time is "<<C<<" exactly."<<endl;
    }
    return 0;
}
