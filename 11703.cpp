#include<iostream>
#include<cmath>

using namespace std;
long long x(long long a);

int main(){
    long long i;
    for(;;){
               cin>>i;
               if(i==(-1))
                        break;

               long long val=0;
               if(i==0){
                       cout<<"1"<<endl;
                       continue;
               }
               
                    val= x(i);
                    cout<<val%1000000<<endl;
    }
    return 0;
}

long long x(long long a){
     if(a<1)
             return 1;
     else
         return x(a-(long long)sqrt(a)) + x((long long)log(a)) + x(a*(long long)sin(a)*(long long)sin(a));
}
