#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
            int n;
            cin>>n;
            int mat[20][20]={0};
            for(int j=0;j<n;j++){
                    long long no=0;
                    cin>>no;
                    for(int k=n-1;k>=0;k--){
                            mat[j][k]=no%10;
                            no/=10;
                    }
            }
            
            int m=0;
            cin>>m;
            for(int x=1;x<=m;x++){
                    string str;
                    cin>>str;
                    if(str=="row"){
                                   int a,b;
                                   cin>>a>>b;
                                   for(int j=0;j<n;j++){
                                           int temp=mat[a-1][j];
                                           mat[a-1][j]=mat[b-1][j];
                                           mat[b-1][j]=temp;
                                   }
                    }
                    if(str=="col"){
                                   int a,b;
                                   cin>>a>>b;
                                   for(int k=0;k<n;k++){
                                           int temp=mat[k][a-1];
                                           mat[k][a-1]=mat[k][b-1];
                                           mat[k][b-1]=temp;
                                   }
                    }
                    if(str=="inc"){
                                   for(int j=0;j<n;j++){
                                           for(int k=0;k<n;k++){
                                                   mat[j][k]+=1;
                                                   if(mat[j][k]>=10)
                                                                    mat[j][k]-=10;
                                           }
                                   }
                    }
                    if(str=="dec"){
                                   for(int j=0;j<n;j++){
                                           for(int k=0;k<n;k++){
                                                   mat[j][k]-=1;
                                                   if(mat[j][k]<0)
                                                                  mat[j][k]+=10;
                                           }
                                   }
                    }
                    if(str=="transpose"){
                                         for(int j=0;j<n;j++){
                                                 for(int k=0;k<n;k++){
                                                         if(j==k)
                                                                 break;
                                                         int temp=mat[j][k];
                                                         mat[j][k]=mat[k][j];
                                                         mat[k][j]=temp;
                                                 }
                                         }
                    }
            }
            cout<<"Case #"<<i<<endl;
            for(int j=0;j<n;j++){
                    for(int k=0;k<n;k++){
                            cout<<mat[j][k];
                    }
                    cout<<endl;
            }
            cout<<endl;
            
            
    }
    return 0;
}
