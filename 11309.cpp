#include<iostream>
using namespace std;
int rev(int a){
    int r;
    while(a>0){
               r+=(a%10);
               a/=10;
    }
    return r;
}
int main(){
    int test;
    cin>>test;
    int h,m;
    while(test--){
                  scanf("%d:%d",&h,&m);
                  if(h==0){
                           if(m<9)
                                  m+=1;
                           else{
                                m+=1;
                                if(m%10<m/10)
                                             m=(m/10)*10+(m/10);
                                else
                                     m=(m/10+1)*10+(m/10+1);
                  }
                  else if(h<10){
                       if(m%10)
                  }
                  cout<<h<<":"<<m<<endl;
    }
    return 0;
}
