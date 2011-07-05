#include<iostream>
using namespace std;

int main(){
    for(int test=1; ; test++){
            bool flag = false;
            int N=0, missile[40000];
            for(N=0; ;N++){
                     int no;
                     cin>>no;
                     if(no == -1){
                                if(N == 0)
                                        flag = true;
                                break;
                     }
                     missile[N] = no;
            }
            if(flag == true)
                          break;
            if(test > 1)
                 cout<<endl;
            int i=0, j=0;
            int len[N];
            for(i=0; i<N; i++)
                     len[i] = 1;
            for(i=0; i<N-1; i++){
                     for(j=i+1; j<N; j++){
                                if(missile[i] >= missile[j]){
                                              if(len[i] + 1 > len[j]){
                                                        len[j] = len[i] + 1;
                                              }
                                }
                     }
            }
            cout<<"Test #"<<test<<":\n";
            int maxm = len[0];
            for(i=1; i<N; i++)
                     if(maxm < len[i])
                             maxm = len[i];
            cout<<"  maximum possible interceptions: "<<maxm<<endl;
    }
    return 0;
}
