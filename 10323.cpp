#include<iostream>
using namespace std;

int main(){
    long long n;
    while(cin>>n){
                  if(n<0){
                         if(n%2==0)
                                   cout<<"Underflow!"<<endl;
                         else
                                   cout<<"Overflow!"<<endl;
                         continue;
                  }
                  if(n<8 && n>=0){
                         cout<<"Underflow!"<<endl;
                         continue;
                  }
                  if(n>13){
                            cout<<"Overflow!"<<endl;
                            continue;
                  }
                  if(n==8){
                           cout<<"40320"<<endl;
                           continue;
                  }
                  if(n==9){
                           cout<<"362880"<<endl;
                           continue;
                  }
                  if(n==10){
                            cout<<"3628800"<<endl;
                            continue;
                  }
                  if(n==11){
                            cout<<"39916800"<<endl;
                            continue;
                  }
                  if(n==12){
                            cout<<"479001600"<<endl;
                            continue;
                  }
                  if(n==13){
                            cout<<"6227020800"<<endl;
                            continue;
                  }
    }
    return 0;
}
