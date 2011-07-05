#include<iostream>
#include<vector>
using namespace std;

int main(){
    for(int test=1; ; test++){
            int m, n;
            cin>>m>>n;
            if(m==0 && n==0)
                    break;
            int tower[m+1][n+1];
            int row[m+1], col[n+1];
            int i, j;
            for(i=0; i<m+1; i++)
                     tower[i][0]=0;
            for(j=0; j<n+1; j++)
                     tower[0][j]=0;
            for(i=1; i<m+1; i++)
                     cin>>row[i];
            for(i=1; i<n+1; i++)
                     cin>>col[i];
            for(i=1; i<m+1; i++){
                     for(j=1; j<n+1; j++){
                              if(row[i] == col[j])
                                        tower[i][j] = tower[i-1][j-1] + 1;
                              else
                                  tower[i][j] = max(tower[i-1][j], tower[i][j-1]);
                                        
                     }
            }
            cout<<"Twin Towers #"<<test<<endl;
            cout<<"Number of Tiles : "<<tower[m][n]<<endl<<endl;
    }
}
