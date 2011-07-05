#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef long double ldouble;
using namespace std;
int main(){
    int test;
    cin>>test;
    while(test--){
                  int side[4],i;
                  double peri=0;
                  for(i=0;i<4;i++){
                                  cin>>side[i];
                                  peri+=side[i];
                  }
                  peri/=2;
                  sort(side,side+4);
                  if(side[0]==side[1] && side[1]==side[2] && side[2]==side[3] && side[3]==side[1]){
                                                        cout<<"square\n";
                                                        continue;
                  }
                  if(side[0]==side[1] && side[2]==side[3]){
                                      cout<<"rectangle\n";
                                      continue;
                  }
                  if(side[0]<peri && side[1]<peri && side[2]<peri && side[3]<peri){
                                  cout<<"quadrangle\n";
                                  continue;
                  }
                  cout<<"banana\n";
    }
    return 0;
}
