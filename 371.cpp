#include<iostream>
using namespace std;

int main(){
    long long i,j;
    for(;;){
            cin>>i>>j;
            if(i==0 && j==0)
                    break;
            long long x=0,y=0,k=0,max=0,maxn=0;
            x=(i>j)?i:j;
            y=(i<j)?i:j;
            for(k=y;k<=x;k++){
                              long long n=k;
                              long long nc=0;
                              if(n==1)
                                      nc=3;
                              while(n!=1){
                                          nc++;
                                          if(n%2!=0)
                                                    n=3*n+1;
                                          else
                                                    n=n/2;
                              }
                              if(nc>max){
                                         maxn=k;
                                         max=nc;
                              }
            }
            cout<<"Between "<<y<<" and "<<x<<", "<<maxn<<" generates the longest sequence of "<<max<<" values."<<endl;
    }
    return 0;
}
