#include<iostream>
using namespace std;

int main(){
    int n=0;
    for(;;){
            cin>>n;
            if(n==0)
                    break;
                     int age[200]={0};
                     int j=0,ctr=0;
                     for(int i=0;i<n;i++){
                             cin>>j;
                             age[j]++;
                             ctr++;
                             
                     }
                     for(int i=0;i<=100;i++){
                             for(int k=0;k<age[i];k++){
                                     cout<<i;
                                     ctr--;
                                     if(ctr>0)
                                              cout<<" ";
                             }
                     }
                     cout<<endl;
    }
    return 0;
}
