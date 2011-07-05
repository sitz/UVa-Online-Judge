#include<iostream>
using namespace std;
int main(){
    long long n,m,i;
    cin>>n>>m;
    long long value[n];
    string job[n];
    for(i=0;i<n;i++)
                    cin>>job[i]>>value[i];
    while(m--){
               long long sum=0;
               for(;;){
                       
                       string str;
                       cin>>str;
                       if(str==".")
                                   break;
                       for(i=0;i<n;i++){
                                        if(str==job[i]){
                                                       sum+=value[i];
                                                       break;
                                        }
                       }
               }
               cout<<sum<<endl;
    }
    return 0;
}
