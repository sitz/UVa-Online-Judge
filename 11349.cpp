#include<iostream>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
            char ch1,ch2;
            int N;
            cin>>ch1>>ch2>>N;
            int mat[150][150]={0},sym[150][150]={0};
            
            for(int j=0;j<N;j++){
                    for(int k=0;k<N;k++){
                            cin>>mat[j][k];
                            sym[N-j-1][N-k-1]=mat[j][k];
                    }
            }
            int cnt=0;
            for(int j=0;j<N;j++){
                    for(int k=0;k<N;k++){
                                         if(mat[j][k]==sym[j][k])
                                                                 cnt++;
                    }
            }
            if(cnt==N*N){
                        cout<<"Test #"<<i<<": Symmetric.";
            }
            else{
                        cout<<"Test #"<<i<<": Non-symmetric.";
            }
            if(i!=t){
                     cout<<endl;
            }
                        
    }
    return 0;
}
