#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef long double ldouble;
using namespace std;
void swapp(int a, int b){
     int temp=a;
     a=b;
     b=temp;
}
int main(){
    int a=0,b=0,c=0,d=0,n,i,j;
    int cubes[300][4];
    for(a=2;a<=200;a++){
        int lhs=a*a*a,ctr=0;
            for(b=2;b<=a;b++){
                int rhs1=b*b*b;
                    for(c=2;c<=b;c++){
                        int rhs2=c*c*c;
                            for(d=2;d<=c;d++){
                                   int rhs3=d*d*d;
                                   if(rhs1+rhs2+rhs3==lhs){
                                               cubes[n][0]=a; cubes[n][1]=d; cubes[n][2]=c; cubes[n][3]=b;
                                               n++;
                                   }
                            }
                    }
            }
    }
    for(i=0;i<n;i++){
            for(j=i;cubes[j][0]<=cubes[i][0];j++){
                   if(cubes[i][1]>=cubes[j][1]){
                         if(cubes[i][1]>cubes[j][1]){
                                       swapp(cubes[i][1],cubes[j][1]);
                                       swapp(cubes[i][2],cubes[j][2]);
                                       swapp(cubes[i][3],cubes[j][3]);
                         }
                         else{
                              if(cubes[i][2]>cubes[j][2]){
                                                          swapp(cubes[i][1],cubes[j][1]);
                                                          swapp(cubes[i][2],cubes[j][2]);
                                                          swapp(cubes[i][3],cubes[j][3]);
                              }
                         }
                   }
            }
    }
    for(i=0;i<n;i++){
                     cout<<"Cube = "<<cubes[i][0]<<", Triple = ("<<cubes[i][1]<<","<<cubes[i][2]<<","<<cubes[i][3]<<")\n";
    }
    system("pause");
    return 0;
}
