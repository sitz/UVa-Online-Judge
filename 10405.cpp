#include<iostream>
#include<vector>
using namespace std;

int main(){
    string row, col;
    while(getline(cin,row) && getline(cin,col)){
            int m, n;
            m=row.length();
            n=col.length();
            int i, j;
            int tower[m+1][n+1];
            for(i=0; i<m+1; i++)
                     tower[i][0]=0;
            for(j=0; j<n+1; j++)
                     tower[0][j]=0;
            for(i=1; i<m+1; i++){
                     for(j=1; j<n+1; j++){
                              if(row[i-1] == col[j-1])
                                        tower[i][j] = tower[i-1][j-1] + 1;
                              else
                                  tower[i][j] = max(tower[i-1][j], tower[i][j-1]);
                     }
            }
            cout<<tower[m][n]<<endl;
    }
}
