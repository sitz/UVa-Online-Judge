#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int z=1;z<=t;z++){
            int a,b,c;
            cin>>a>>b>>c;
            int player[1000],board[101][2],die[1000];
            for(int i=0;i<=100;i++)
                    for(int j=0;j<2;j++)
                            board[i][j]=i;
            for(int i=1;<=b;i++){
                    int x,y;
                    cin>>x>>y;
                    board[x][0]=x;
                    board[x][1]=y;
            }
            for(int i=1;i<=c;i++){
                    cin>>die[i];
            }
            int ctr=1;
            for(int i=1;i<=c;i++){
                    player[ctr]+=die[i];
                    if(board[player[ctr]])
                    if(ctr%a==0)
                                ctr=1;
            
    }
    return 0;
}
