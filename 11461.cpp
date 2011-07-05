#include<iostream>
#include<cmath>
using namespace std;

int main(){
    for(;;){
            long long a,b;
            cin>>a>>b;
            if(a==0 && b==0)
                    break;
            double sqra=sqrt(a);
            long long na=(long long)sqra;
            if(sqra==(long long)sqra)
                           na-=1;
            double sqrb=sqrt(b);
            long long nb=(long long)sqrb;
            cout<<nb-na<<endl;
    }
    return 0;
}
