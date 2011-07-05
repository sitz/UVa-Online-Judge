#include<iostream>
using namespace std;

int main(){
    int n;
    while(cin>>n){
          if(n==0){
                  cout<<"1"<<endl;
                  continue;
          }
          if(n==1){
                   cout<<"2"<<endl;
                   continue;
          }
          int val=n*(n+1)/2;
          
          cout<<val<<endl;
    }
    return 0;
}
