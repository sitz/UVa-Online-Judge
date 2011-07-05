#include<iostream>
using namespace std;

int main(){
    long long nine[50]={0};
    nine[1]=9;
    for(long long i=2;i<50;i++){
                 nine[i]=nine[i-1]*9;
    }
    long long n=0;
    while(cin>>n){
                  int ctr=0;
                  for(int i=0;;i++){
                          if(n<=nine[i]){
                                         ctr=i;
                                         break;
                          }
                  }
                  if(ctr%2!=0)
                              cout<<"Stan wins."<<endl;
                  else
                              cout<<"Ollie wins."<<endl;
    }
      return 0;
}
                  
