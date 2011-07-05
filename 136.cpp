#include<iostream>

using namespace std;

int primes(int j);

int main()
{
    int ugly[1500],primes[1500],k=0,j=0;
    for(k=0;k<1500;k++)
        ugly[k]=0;
    while(ugly[1500]==0)
    {
                     ugly[0]=1;
                     k=1;
                     j=2;
                     primes(j)
                     if(j%2==0 || j%3==0 || j%5==0)
                     {
                               ugly[k]=j;
                               k++;
                               j++;
                     }
                     else
                               j++;
    }
                     
    cout<<"The 1500'th ugly number is "<<ugly[1500];
cin>>k;    return 0;
}       

primes(int j)
{
           for(int p=2;p<j;p++)
                   if(j%p==0)
