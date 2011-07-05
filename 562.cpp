#include<iostream>
using namespace std;

int main(){
    int arr[100],front=0,back=0,n,m,i=0,j=0,k=0,temp=0,val=0;
    cin>>n;
    for(i=0;i<n;i++){
                     cin>>m;
                     
                     for(j=0;j<m;j++)
                                     cin>>arr[j];
                     if(m>=2){
                              for(j=0;j<m;j++){
                                     for(k=j+1;k<m;k++){
                                                       if(arr[j]>arr[k]){
                                                                        temp=arr[j];
                                                                        arr[j]=arr[k];
                                                                        arr[k]=temp;
                                                       }
                                     }
                              }
                     front=arr[m-1];
                     back=arr[m-2];
                     m=m-3;
                     while(m!=(-1)){
                            if(front>=back){
                                           back+=arr[m];
                                           front=front;
                                           m--;
                            }
                            else{
                                 front+=arr[m];
                                 back=back;
                                 m--;
                            }
                     }
                     val=abs(front-back);
                     cout<<val<<endl;
                     }
                     else{
                          cout<<arr[0]<<endl;
                     }
    }
    return 0;
}
