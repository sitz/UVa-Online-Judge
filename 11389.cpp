#include<iostream>
using namespace std;

int main(){
    for(;;){
            long long n,d,r;
            cin>>n>>d>>r;
            if(n==0 && d==0 && r==0)
                    break;
            long long mor[200],eve[200];
            for(long long i=0;i<n;i++)
                    cin>>mor[i];
            for(long long i=0;i<n;i++)
                    cin>>eve[i];
            for(long long i=0;i<n;i++){
                    for(long long j=i+1;j<n;j++){
                            if(mor[i]>mor[j]){
                                              long long temp=mor[i];
                                              mor[i]=mor[j];
                                              mor[j]=temp;
                            }
                    }
            }
            for(long long i=0;i<n;i++){
                    for(long long j=i+1;j<n;j++){
                            if(eve[i]<eve[j]){
                                              long long temp=eve[i];
                                              eve[i]=eve[j];
                                              eve[j]=temp;
                            }
                    }
            }
            long long over=0;
            for(long long i=0;i<n;i++){
                    if((mor[i]+eve[i])>d){
                                        long long temp=(mor[i]+eve[i])-d;
                                        over+=(temp*r);
                    }
            }
            cout<<over<<endl;
    }
    return 0;
}
