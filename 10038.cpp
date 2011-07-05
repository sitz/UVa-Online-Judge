#include<iostream>

using namespace std;

int main()
{
    int n,i,j,k,l,t,temp,ip[3000]={0},seque[3000],diff[3000];
    
    cin>>n;
    
    for(i=0;i<n;i++)
    {
                    cin>>ip[i];
    }
    
    for(j=0;j<n-1;j++)
                      diff[j]=ip[i+1]-ip[i];
                      seque[j]=j+1;
                      
    for(k=0;k<n-1;k++)
                      for(l=0;l<n-i-2;l++)
                                          if(diff[j]>diff[j+1])
                                          {
                                                               temp=diff[j];
                                                               diff[j]=diff[j+1];
                                                               diff[j+1]=temp;
                                          }
    
    for(t=0;t<n-1;t++)
    {
                      if(seque[t]!=diff[t]) 
                      {
                                           cout<<"Not jolly"<<endl;
                                           break;
                      }                    break;
                      
                      if(seque[t]==diff[t])
                      {
                                           cout<<"Jolly"<<endl;
                                           break;
                      }                    break;
                      
    }
    return 0;
  
}
