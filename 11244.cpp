#include<iostream>
using namespace std;
int main(){
    for(;;){
            long long r,c;
            cin>>r>>c;
            if(r==0 && c==0)
                    break;
            string star[r+1];
            long long count=0,i=0,j=0;
            for(i=0;i<r;i++){
                            cin>>star[i];
            }
            for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                             if(star[i][j]=='*'){
                                              if(star[i][j-1]!='*' & star[i-1][j-1]!='*' & star[i-1][j]!='*' & star[i-1][j+1]!='*'
                                              & star[i][j+1]!='*' & star[i+1][j+1]!='*' & star[i+1][j]!='*' & star[i+1][j-1]!='*')
                                                                   count++;
                             }
            }
            }
            cout<<count<<endl;
    }
    return 0;
}
