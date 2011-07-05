#include<iostream>

using namespace std;

int main()
{
    unsigned long long int fib[5000]={0};
    int i=0,n=0;
    fib[0]=0;
    fib[1]=1;
    
    for(int i=2;i<5000;i++)
            fib[i]=fib[i-1]+fib[i-2];
    
    while(cin>>n)
    {
                 cout<<"The Fibonacci number for "<<n<<" is "<<fib[n-1]<<endl;
    }
    
    return 0;
}
