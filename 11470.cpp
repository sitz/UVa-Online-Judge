#include<iostream>
using namespace std;

int main(){
    for(int z=1;;z++){
            int n;
            cin>>n;
            if(n==0)
                    break;
            int mat[10][10]={0};
            for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                            cin>>mat[i][j];
                    }
            }
            int nl=(n%2==0)?(n/2):(n+1)/2;
            int sum[10]={0};
            for(int k=0;k<=nl;k++){
                    for(int i=0;i<n;i++){
                            for(int j=0;j<n;j++){
                                    if((i!=nl || i!=nl-k) && (j!=nl || j!=nl-k))
                                            continue;
                                         sum[k]+=mat[i][j];
                            }
                    }
                    cout<<sum[k]<<"\t";
            }
            cout<<"Case "<<z<<": ";
            for(int k=0;k<nl;k++){
                    cout<<sum[k];
                    if(k!=(nl-1))
                                 cout<<" ";
            }
            cout<<endl;
    }
    return 0;
}
