#include <cstdio>

int main() {
    //freopen("testI.txt", "r", stdin);
    //freopen("testO.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        int Arr[N];
        int Less = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", &Arr[i]);
            int L = 0;
            for (int j = 0; j < i; j++)
                L += (Arr[j] <= Arr[i]);

            Less += L;
        }
        printf("%d\n", Less);
    }
    return 0;
}
