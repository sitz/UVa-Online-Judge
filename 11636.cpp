#include<iostream>
#include<cmath>
using namespace std;

int main(){
    for(int i=1;;i++){
           int n;
           cin>>n;
           if(n<0) 
                    break;
           int copy=0;
           for(int j=0;j<=20;j++){
                   if((int)pow(2.0,j)>=n){
                                    copy=j;
                                    break;
                   }
           }
           cout<<"Case "<<i<<": "<<copy<<endl;
    }
    return 0;
}
