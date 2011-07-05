#include<iostream>
using namespace std;

int main(){
    for(;;){
            int n;
            cin>>n;
            if(n==0)
                    break;
            int max=0,min=0;
            int original[10000]={0},destination[10000]={0};
            for(int i=0;i<n;i++){
                    int j,k;
                    cin>>j;
                           original[j]++;
                    cin>>k;
                           destination[k]++;
                    if(k>max)
                             max=k;
                    if(k<min)
                             min=k;
                    if(j>max)
                             max=j;
                    if(j<min)
                             min=j;
            }
            int ctr=0;
            for(int i=min;i<=max;i++){
                    if(original[i]!=destination[i]){
                                                    ctr=1;
                                                   break;
                    }
            }
            if(ctr==1)
                      cout<<"NO"<<endl;
            else
                      cout<<"YES"<<endl;
    }
}
            
