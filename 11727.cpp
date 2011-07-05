#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
            int no[3];
            for(int j=0;j<3;j++)
                    cin>>no[j];
            for(int j=0;j<3;j++){
                    for(int k=j+1;k<3;k++){
                            if(no[j]>no[k]){
                                            int temp=no[j];
                                            no[j]=no[k];
                                            no[k]=temp;
                            }
                    }
            }
            cout<<"Case "<<i<<": "<<no[1]<<endl;
    }
    return 0;
}
