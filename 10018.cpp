#include<iostream>

using namespace std;

long reverse(long n);

int main()
{
    long num=0,rev_num=0;
    int i=0,n=0,iter=0;
    cin>>n;
    
    for(i=0;i<n;i++)
    {
                    num=0;rev_num=0;iter=0;
                    cin>>num;
                    rev_num=reverse(num);
                    
                    if(num==rev_num)
                                   cout<<"0 "<<num<<endl;
                                   
                    else
                    {
                                   while(num!=rev_num)
                                   {
                                                      iter++;
                                                      num=num+rev_num;
                                                      rev_num=reverse(num);
                                                      
                                   }
                                   cout<<iter<<" "<<num<<endl;
                    }
    }
    return 0;
}
           
    
    
long reverse(long n)    
{
     long rev_n=0;
     while(n)
     {
               rev_n*=10;
               rev_n+=n%10;
               n/=10;
     }
     return rev_n;
}
