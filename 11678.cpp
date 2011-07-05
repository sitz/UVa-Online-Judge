#include<iostream>
using namespace std;

int main(){
    for(;;){
            int A,B;
            int Alice[10000]={0},Betty[10000]={0},a=0,b=0;
            cin>>A>>B;
            if(A==0 && B==0)
                    break;
            for(int i=0;i<A;i++)
                    cin>>Alice[i];
            for(int i=0;i<B;i++)
                    cin>>Betty[i];
            for(int i=0;i<A;i++){
                    int ctr=0;
                    if(Alice[i]!=Alice[i-1]){
                    for(int j=0;j<B;j++){
                            if(Alice[i]==Betty[j]){
                                                   ctr++;
                            }
                    }
                    if(ctr==0)
                              a++;
                    }
            }
            for(int i=0;i<B;i++){
                    int ctr=0;
                    if(Betty[i]!=Betty[i-1]){
                    for(int j=0;j<A;j++){
                            if(Betty[i]==Alice[j]){
                                                   ctr++;
                            }
                    }
                    if(ctr==0)
                              b++;
                    }
            }
            int max=(a<b)?a:b;
            cout<<max<<endl;
    }
    return 0;
}
