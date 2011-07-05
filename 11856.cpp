#include<iostream>
using namespace std;

int main(){
    while(true){
                  int N, i, w;
                  cin>>N;
                  if(N == 0)
                       break;
                  double price[N+1];
                  double nMem, MW=0;
                  for(i=1; i<=N; i++){
                           cin>>price[i];
                           price[i]*=10;
                           MW += price[i];
                  }
                  sort(price+1,price+N+1);
                  double dVal = MW;
                  MW /= 2;
//                  MW*=10;       
                  int mat[N+1][(int)MW+1];
                  for(i=0; i<=N; i++)
                           mat[i][0] = 0;
                  for(w=0; w<=(int)MW; w++)
                           mat[0][w] = 0;
                  for(i=1; i<=N; i++){
                           for(w=1; w<=(int)MW; w++){
                                    if(price[i] > w)
                                                 mat[i][w] = mat[i-1][w];
                                    else
                                        mat[i][w] = max(mat[i-1][w], mat[i-1][w-(int)price[i]] + (int)price[i]);
                           }
                  }
                  cout<<(dVal-2*mat[N][(int)MW])/10.0;
//                                totVal += mat[N][(int)MW];
//                  cout<<totVal<<endl;
    }
    return 0;
}
