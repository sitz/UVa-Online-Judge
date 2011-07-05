#include<iostream>
#include<cmath>
using namespace std;

int main(){
    long long n;
    while(cin>>n){
                  int i=0,no[50]={0};
                  while(n>0){
                             int rem=n%10;
                             no[i]=rem;
                             n/=10;
                             i++;
                  }
                  for(int j=0;j<i;j++){
                          for(int k=j+1;k<i;k++){
                                  if(no[j]>no[k]){
                                                 int temp=no[j];
                                                 no[j]=no[k];
                                                 no[k]=temp;
                                  }
                          }
                  }
                  long long a=0,b=0;
                  for(int j=0;j<i;j++){
                          a+=no[j]*(long long)pow(10.0,j);
                          b+=no[j]*(long long)pow(10.0,i-j-1);
                  }
                  long long x=(a-b);
                  cout<<a<<" - "<<b<<" = "<<x<<" = 9 * "<<(x/9)<<endl;
    }
    return 0;
}
