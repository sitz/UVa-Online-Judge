#include<iostream>
using namespace std;

int main(){
    int sum[10000]={0};
    sum[0]=1;
    for(int i=2;;i++){
            int s=0;
            for(int j=1;j<i;j++){
                    if(i%j==0)
                              s+=j;
            }
            sum[i]=s;
            cout<<sum[i]<<endl;
            if(s==1000)
                    break;
    }
    return 0;
}
