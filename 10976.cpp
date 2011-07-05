#include<iostream>
using namespace std;

int main(){
    int k;
    while(cin>>k){
                  int y=0;
                  int sol[1000][2]={0},cnt=0;
                  for(y=k+1;y<=2*k;y++){
                                        double x=((double)k*(double)y)/((double)y-(double)k);
                                        if(x==(int)x){
                                                      sol[cnt][0]=(int)x;
                                                      sol[cnt][1]=y;
                                                      cnt++;
                                        }
                  }
                  cout<<cnt<<endl;
                  for(int i=0;i<cnt;i++)
                          cout<<"1/"<<k<<" = 1/"<<sol[i][0]<<" + 1/"<<sol[i][1]<<endl;
    }
    return 0;
}
