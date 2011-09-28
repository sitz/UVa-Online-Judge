#include <cstdio>

int main(){
    //freopen("testI.txt", "r", stdin);
    //freopen("testO.txt", "w", stdout);
    for (int t = 1; ; t++) {
        int N;
        scanf("%d", &N);
        if (!N) break;

        int A = 0, B = 0, I;
        while (N--) {
            scanf("%d", &I);
            if (I == 0) ++B;
            else        ++A;
        }
        printf("Case %d: %d\n", t, A - B);
    }
    return 0;
}
