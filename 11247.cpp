#include<iostream>
#include<cmath>
using namespace std;
int main(){
    for(;;){
            long double m,x;
            cin>>m>>x;
            if(m==0 && x==0)
                    break;
            long long v=(long long)floor(((m-1)/(1.0-x/100.0)));
            if(v>=m)
                    cout<<v<<endl;
            else
                    cout<<"Not found"<<endl;
    }
    return 0;
}
