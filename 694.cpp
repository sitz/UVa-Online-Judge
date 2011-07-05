#include<iostream>
using namespace std;

int main(){
    for(long long i=1;;i++){
             long long A,L;
             cin>>A>>L;
            if(A<0 && L<0)
                    break;
            long long n=A;
            long long nc=1;
            while(n!=1){
                    if(n%2!=0){
                              n=3*n+1;
                              if(n>L)
                                     break;
                    }
                    else
                              n=n/2;
                       nc++;
            }
            cout<<"Case "<<i<<": A = "<<A<<", limit = "<<L<<", number of terms = "<<nc<<endl;
    }
    return 0;
}
