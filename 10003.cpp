#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

#define INF 1<<30
#define MAX 53
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAXINT 9999999
#define NCUTS 50

int L, N;
int C[MAX];
int dp[MAX][MAX];

int Cost(int J, int I) {
	if (J - I <= 1) return 0;
	return C[J] - C[I];
}

int memo(int I, int J) {
	if (I + 1 == J)		return 0;
	if (dp[I][J] != -1)	return dp[I][J];
	
	int gMin = INF, K;
	
	for (K = I + 1; K < J; K++) {
		gMin = MIN(gMin, memo(I, K) + memo(K, J) + C[J] - C[I]);
	}
	return dp[I][J] = gMin;
}

void doIt() {
	int i, j, k;
	for (i = 0; i <= N; i++) {
		for (j = 0; j <= N; j++) {
			for (k = i + 1; k < j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + Cost(j, i));
			}
		}
	}
}

int main() {
    int len;
    int nc;
    int places[NCUTS+2];
    int mincost[NCUTS+2][NCUTS+2];
        
    while(scanf("%d", &len) && (len != 0)) {
        scanf("%d", &nc);
                
        for(int i=0; i<nc; i++) {
        	scanf("%d", &places[i + 1]);
        }
        
        places[0] = 0;
        nc++;
        places[nc] = len;
                
        for(int i=0; i<=NCUTS+1; i++) {
            for(int j=0;j<=NCUTS+1;j++) {
                mincost[i][j] = MAXINT;
            }
        }
        
        for(int i=0; i<=nc; i++) {
            mincost[i][i] = 0;
            mincost[i][i+1] = 0;
            mincost[i][i+2] = places[i+2] - places[i];
        }

        for(int k=3; k<=nc; k++) {
            for(int i=0; i<=nc-k; i++) {
                for(int j=i+1; j<=i+k-1; j++) {
                    if((mincost[i][j] + mincost[j][i+k] + places[i+k] - places[i]) < mincost[i][i+k]) {
                        mincost[i][i+k] = mincost[i][j] + mincost[j][i+k] + places[i+k] - places[i];
                    }
                }
            }
        }
        
        printf("The minimum cutting is %d.\n",mincost[0][nc]);
    }
    return 0;
}
