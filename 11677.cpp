#include<iostream>
using namespace std;

int main(){
    int uni=24*60;
   for(;;){
           int H1,M1,H2,M2;
           cin>>H1>>M1>>H2>>M2;
           if(H1==0 && M1==0 && H2==0 && M2==0)
                    break;
           int t1=H1*60+M1;
           int t2=H2*60+M2;
           int sleep=0;
           if(t2>=t1)
                    sleep=t2-t1;
           else
                    sleep=uni-t1+t2;
           cout<<sleep<<endl;
    }
    return 0;
}
