#include<iostream>

using namespace std;

long long carry(long long n)
{
    long long carry=0;
    if(n>9)
           carry =1;
    else 
         carry =0;
         
    return carry;
}

int main()
{
    long long a,b,r1=0,r2=0,r=0,c=0,count=0;
    for(;;)
    {
           cin>>a>>b;
           
           if(a==0 && b==0)
                   break;
                   
           count =0;
           r1=0;r2=0;r=0;
           while((a!=0)||(b!=0))
           {
                      r1=a%10;                   
                      r2=b%10;
                      a/=10;
                      b/=10;
                      
                      r=r1+r2+c;
                      
                      if(r>=9)
                             count++;
                             
                      c=carry(r);                      
           }
           if(count>1)
                      cout<<count<<" carry operations."<<endl;
           if(count==1)
                      cout<<"1 carry operation."<<endl;
                
           if(count==0)
                       cout<<"No carry operation."<<endl;
    }
    
    return 0;
}
