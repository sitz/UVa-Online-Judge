#include <cstdio>
using namespace std;

int MaxIntervalSum(int num[], int n){
    int max = num[0], i, sum[n];
    sum[0] = num[0] > 0 ? num[0] : 0;
    for(i=1; i<n; i++){
             if(sum[i-1] + num[i] < num[i])
                    sum[i] = num[i];
             else
                 sum[i] = sum[i-1] + num[i];
             max = max > sum[i] ? max : sum[i];
    }
    return max;
}

int main(){
    while(true){
                int N, i;
                scanf("%d", &N);
                if(N == 0)
                     break;
                int vec[N];
                for(i=0; i<N; i++)
                         scanf("%d", &vec[i]);
                int maxm = MaxIntervalSum(vec, N);
                if(maxm > 0)
                        printf("The maximum winning streak is %d.\n", maxm);
                else
                    printf("Losing streak.\n");
    }
    return 0;
}
