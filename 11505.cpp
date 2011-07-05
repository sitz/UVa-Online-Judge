#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define pi 2*acos(0.0)
#define con pi/180.0
int main(){
    int t;
    cin>>t;
    for(int z=0;z<t;z++){
            int n;
            cin>>n;
            double x=0,y=0,angle=0;
            for(int i=0;i<n;i++){
                    double v;
                    string str;
                    cin>>str>>v;
                    if(str=="fd"){
                                  x+=v*cos(con*angle);
                                  y+=v*sin(con*angle);
                    }
                    if(str=="bk"){
                                  x-=v*cos(con*angle);
                                  y-=v*sin(con*angle);
                    }
                    if(str=="lt")
                                  angle-=v;
                    if(str=="rt")
                                 angle+=v;
            }
            double dis=sqrt(x*x+y*y);
            cout<<(int)dis<<endl;
    }
    return 0;
}
