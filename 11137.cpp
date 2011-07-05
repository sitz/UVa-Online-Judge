#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

int main(){
    int N, i, j;
    int coin[21]={1, 8, 27, 64, 125, 216, 343, 512, 729, 1000, 1331, 1728, 2197, 2744, 3375, 4096, 4913, 5832, 6859, 8000, 9261};
    uint64 ways[10000];
    ways[0] = 1;
    for(i=0; i<21; i++){
             int c = coin[i];
             for(j=c; j<10000; j++)
                      ways[j]+=ways[j-c];
    }
    int in;
    while(cin>>in)
                  cout<<ways[in]<<endl;
    return 0;
}
