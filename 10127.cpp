#include<iostream>
using namespace std;

int main(){
    int n=0;
    while(cin>>n){
                  int m=1;
                  int c=1;
                  while(m%n){
                             c++;
                             m=(m*10+1)%n;
                  }
                  cout<<c<<endl;
    }
    return 0;
}
