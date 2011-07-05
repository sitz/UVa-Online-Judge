#include<iostream>
#include<queue>
using namespace std;
#define FOR(i,N) for(i=0;i<(N);i++)
bool visited[30];
int NNode,i,j;
int node[30];
bool mat[30][30];
int TTL[30];

void gen(){
     FOR(i,30){
     node[i]==-1;
     visited[i]=false;
     TTL[i]=-1;
     }
     FOR(i,30)
     FOR(j,30)
     mat[i][j]=0;
     NNode=-1;
}
void init(){
     FOR(i,NNode+1){
                    TTL[i]=-1;
                    visited[i]=false;
                    }
}
    
     
int find(int i){
    FOR(j,NNode+1)
    {if(node[j]==i) return j;}
    NNode++;
    node[NNode]=i;
    return NNode;
}

int calc(int p,int ttl){
    init();
    int m,ans=0;
    queue<int> q;
    m=find(p);
    q.push(m);
    visited[m]=true;
    TTL[m]=ttl;
    while (!q.empty()){
          m=q.front();
          q.pop();
          if(!TTL[m]) continue;
          if(TTL[m]>=1)
          FOR(i,NNode+1){
                      if (mat[m][i] && !visited[i]){
                         q.push(i);
                         TTL[i]=TTL[m]-1;
                         visited[i]=true;}
          }
    }
    FOR(i,NNode+1)
    if(!visited[i]) ans++;
    return ans;
}
                   
int main(){
    int ans,NC,p,q,m,n,ttl,cases=0;
    while (cin>>NC){
          if(!NC) break;
          gen();
          FOR (i,NC){
              cin>>p>>q;
              m=find(p);
              n=find(q);
              mat[m][n]=true;
              mat[n][m]=true;
              }
          while (cin>>p>>ttl){
                if(!p && !ttl) break;
                ans=calc(p,ttl);
                cout<<"Case "<<++cases<<": "<<ans<<" nodes not reachable from node "<<p<<" with TTL = "<<ttl<<"."<<endl;
                }
          }
    return 0;
}
