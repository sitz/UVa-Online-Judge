#include<iostream>
using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
                  int N, i, w;
                  cin>>N;
                  int price[N+1], weight[N+1];
                  for(i=1; i<=N; i++)
                           cin>>price[i]>>weight[i];
                  int nMem, totVal=0;
                  cin>>nMem;
                  while(nMem--){
                                int MW;
                                cin>>MW;
                                int mat[N+1][MW+1];
                                for(i=0; i<=N; i++)
                                         mat[i][0] = 0;
                                for(w=0; w<=MW; w++)
                                         mat[0][w] = 0;
                                for(i=1; i<=N; i++){
                                         for(w=1; w<=MW; w++){
                                                  if(weight[i] > w)
                                                               mat[i][w] = mat[i-1][w];
                                                  else
                                                      mat[i][w] = max(mat[i-1][w], mat[i-1][w-weight[i]] + price[i]);
                                         }
                                }
                                totVal += mat[N][MW];
                  }
                  cout<<totVal<<endl;
    }
    return 0;
}
