#include<iostream>

using namespace std;

int main(){
    long long y=0;
    while(cin>>y){
                  long long a=0,b=0,c=0;
                  if(((y%400)==0) || (y%4==0 && y%100!=0)){
                                a=1;
                                cout<<"This is leap year."<<endl;
                  }
                  if(y%15==0){
                              b=1;
                             cout<<"This is huluculu festival year."<<endl;
                  }
                  if(y%55==0 && a==1){
                             c=1;
                             cout<<"This is bulukulu festival year."<<endl;
                  }
                  if(a==0 && b==0 && c==0)
                          cout<<"This is an ordinary year."<<endl;
                      
                  cout<<endl;
    }
    return 0;
}
