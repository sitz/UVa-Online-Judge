#include<iostream>

using namespace std;

int main()
{
    int n,cuts;
    for(;;)
    {
           cin>>n;
           
           if(n<0)
           break;
           
           cuts=(unsigned long long)n*(n+1)/2+1;
           cout<<cuts<<endl;
    }
    return 0;
}
                      
