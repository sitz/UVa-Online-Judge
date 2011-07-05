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
    int n;
    while(cin>>n){
                  double gopX,gopY,dogX,dogY;
                  cin>>gopX>>gopY>>dogX>>dogY;
                  int ctr=0,i;
                  double hole[n][2];
                  for(i=0;i<n;i++)
                                  cin>>hole[i][0]>>hole[i][1];
                  for(i=0;i<n;i++){
                                   double d1=(hole[i][0]-gopX)*(hole[i][0]-gopX) + (hole[i][1]-gopY)*(hole[i][1]-gopY);
                                   double d2=(hole[i][0]-dogX)*(hole[i][0]-dogX) + (hole[i][1]-dogY)*(hole[i][1]-dogY);
                                   if(d2>=4*d1){
                                                printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",hole[i][0],hole[i][1]);
                                                ctr=-1;
                                                break;
                                   }
                  }
                  if(ctr==0)
                            cout<<"The gopher cannot escape.\n";
    }
    return 0;
}
