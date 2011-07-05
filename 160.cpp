#include<iostream>
#include<cmath>
using namespace std;

int isPrime(int a){
    for(int k=2;k<=sqrt(a);k++){
            if(a%k==0)
                      return 0;
    }
    return 1;
}

int main(){
    int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    for(;;){
            int n;
            cin>>n;
            if(n==0)
                    break;
            int factor[25]={0};
            int ind=0;
            for(int i=n;i>=2;i--){
                    int val=i;
                    for(int j=0;j<25;j++){
                            while((val%prime[j])==0){
                                                   factor[j]++;
                                                   val/=prime[j];
                            }
                            if(isPrime(val)==1)
                                               break;
                    }
                    for(int j=0;j<25;j++){
                                      if(prime[j]==val){
                                                        factor[j]++;
                                                                 break;
                                                        }
                    }
            }
            for(int j=24;j>=0;j--){
                    if(factor[j]!=0){
                                     ind=j;
                                     break;
                    }
            }
            printf("%3d! =",n);
            for(int i=0;i<=ind;i++){
                    if(i!=0 && i%15==0)
                                   printf("\n      ");
                    printf("%3d",factor[i]);
            }
            cout<<endl;
    }
    return 0;
}
