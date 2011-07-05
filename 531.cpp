#include<iostream>
#include<vector>
using namespace std;

int main(){
    string str;
    while(cin>>str)
    {
            bool ctr=true;
            string row[110],col[110];
            int m=1, n=1;
            if(str=="#")
            ctr=false;
            else
            row[m++]=str;
            
            while(ctr==true){
                        cin>>str;
                        if(str=="#")
                        {
                                    ctr=false;
                                    break;
                        }
                        row[m++]=str;
            }
            while(true){
                        cin>>str;
                        if(str=="#")
                        break;
                        else
                        col[n++]=str;
            }
 //           cout<<row<<" :"<<col;
            int tower[m][n];
            int i, j;
            for(i=0; i<m; i++)
                     tower[i][0]=0;
            for(j=0; j<n; j++)
                     tower[0][j]=0;
            for(i=1; i<m; i++){
                     for(j=1; j<n; j++){
                              if(row[i] == col[j])
                                        tower[i][j] = tower[i-1][j-1] + 1;
                              else
                                  {
                                        if(tower[i-1][j]>=tower[i][j-1])
                                        tower[i][j]=tower[i-1][j];
                                        else
                                        tower[i][j] = tower[i][j-1];
                                  }
                                        
                     }
            }
            string lcs[110];
            int k=0;
            i=m-1;
            j=n-1;
            while(i>0 && j>0)
            {                                      if(row[i]==col[j])
                                                {
                                                                  lcs[k++]=col[j];
                                                                  i--;
                                                                  j--;
                                                }
                                                else if(tower[i-1][j]==tower[i][j])
                                                i--;
                                                else
                                                j--;
                              }
            for(i=k-1;i>=0;i--)
            {
                               cout<<lcs[i];
                               if(i)
                               cout<<" ";
            }
            cout<<endl;
    }
}
