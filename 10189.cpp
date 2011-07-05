#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int i=0,j=0,R,C,no=0,cnt=0;
    char ele[100][100];
    for(no=1;;no++){
           cin>>R>>C;
           if(R==0 && C==0)
                   break;
           if(no!=1)
                    cout<<endl;
    for(i=0;i<R;i++)
                    for(j=0;j<C;j++){
                                    cin>>ele[i][j];
                                    }
    for(i=0;i<R;i++)
                    for(j=0;j<C;j++){
                                    cnt=0;
                                    if(ele[i][j]=='*')
                                                     continue;
                                    else{
                                        if(i!=0 && j!=0 && ele[i-1][j-1]=='*')
                                                              cnt++;
                                        if(i!=0 && ele[i-1][j]=='*')
                                                              cnt++;
                                        if(i!=0 && j!=C-1 && ele[i-1][j+1]=='*')
                                                              cnt++;
                                        if(j!= C-1 && ele[i][j+1]=='*')
                                                              cnt++;
                                        if(j!=C-1 && i!=R-1 && ele[i+1][j+1]=='*')
                                                              cnt++;
                                        if(i!=R-1 && ele[i+1][j]=='*')
                                                              cnt++;
                                        if(i!= R-1 && j!=0 && ele[i+1][j-1]=='*')
                                                              cnt++;
                                        if(j!=0 && ele[i][j-1]=='*')
                                                              cnt++;
                                        cnt+=48;                  
                                        ele[i][j]=(char)(cnt);
                                    }
                    }
        cout<<"Field #"<<no<<":"<<endl;
        for(i=0;i<R;i++){
                    for(j=0;j<C;j++)
                                    cout<<ele[i][j];
                    cout<<endl;
        }
    }
        return 0;
}
