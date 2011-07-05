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
using namespace std;

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;

#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)
#define REP(i, N) for(i=1; i<=N; i++)

#define INF INT_MAX

int maxSum(int arr[], int N){
    int gVal = -INF;
    int temp = 0;
    int i;
    FOI(i, 0, N){
           temp += arr[i];
           if(temp > gVal)
                   gVal = temp;
           if(temp < 0)
                   temp = 0;
    }
    return gVal;
}

int main(){
    int N, i, j, k;
    cin>>N;
    int mat[N][N];
    FOI(i, 0, N-1){
           FOI(j, 0, N-1){
                  cin>>mat[i][j];
                  if(i > 0)
                       mat[i][j] += mat[i-1][j];
           }
    }
    int gSum = -INF;
    FOI(i, 0, N-1){
           FOI(j, i, N-1){
                  int vec[N];
                  FOI(k, 0, N-1){
                         if(i > 0)
                              vec[k] = mat[j][k] - mat[i-1][k];
                         else
                             vec[k] = mat[i][k];
                  } 
                  int mSum = maxSum(vec, N-1);
                  gSum = max(mSum, gSum);
           }
    }
    cout<<gSum<<endl;
    //cin>>N;
    return 0;
}
