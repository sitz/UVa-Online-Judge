#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

struct City{
       double X, Y;
};
int main(){
    int test;
    cin>>test;
    for(int t=1; t<=test; t++){
            int N;
            cin>>N;
            int i, j, k;
            City city[N];
            for(i=0; i<N; i++)
                     cin>>city[i].X>>city[i].Y;
           double mat[N][N];
            for(i=0; i<N; i++)
                     for(j=0; j<N; j++){
                              double dis = (city[i].X - city[j].X)*(city[i].X - city[j].X) + 
                                           (city[i].Y - city[j].Y)*(city[i].Y - city[j].Y);
                              dis = sqrt(dis);
                              if(i==j){
                                       mat[i][j] = 0;
                                       mat[j][i] = 0;
                              }
                              else if(dis <= 10.0){
                                     mat[i][j] = dis;
                                     mat[j][i] = dis;
                              }
                              else{
                                   mat[i][j] = 999999999;
                                   mat[j][i] = 999999999;
                              }
                     }
            for(k=0; k<N; k++)
                         for(i=0; i<N; i++)
                                  for(j=0; j<N; j++)
                                           mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
            double maxm = 0;
            for(i=0; i<N; i++)
                     for(j=0; j<N; j++)
                              maxm = max(maxm, mat[i][j]);
            cout<<"Case #"<<t<<":\n";
            if(maxm >= 900000000)
                    printf("Send Kurdy\n\n");
            else
                printf("%.4lf\n\n", maxm);
    }
    return 0;
}
