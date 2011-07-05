#include<iostream>
using namespace std;

int main(){
            int n=0,i=0,j=0, no=0,p;
            cin>>n;
            int real[n+1],dup[n+1];
            for(i=1;i<=n;i++){
                            cin>>p;
                            real[p]=i;
            }
            while(cin>>no){
                           dup[no]=1;
                           for(i=2;i<=n;i++){
                                           cin>>p;
                                           dup[p]=i;
                           }
                           int tower[n+1][n+1];
                           for(i=0; i<n+1; i++)
                                    for(j=0; j<n+1; j++)
                                             tower[i][j]=0;
                           for(i=1; i<n+1; i++){
                                    for(j=1; j<n+1; j++){
                                             if(real[i] == dup[j]){
                                                       tower[i][j] = tower[i-1][j-1] + 1;
                                             }
                                             else{
                                                 if(tower[i-1][j]>tower[i][j-1]){
                                                         tower[i][j]=tower[i-1][j];
                                                 }
                                                 else{
                                                     tower[i][j] = tower[i][j-1];
                                                 }
                                             }
                                    }
                           }
                           cout<<tower[n][n]<<endl;
            }
            return 0;
}
