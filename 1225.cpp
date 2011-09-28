#include <cstdio>

int Mat[10001][10];

void Cal() {
    for (int i = 0; i < 10; i++)
        Mat[0][i] = 0;

    for (int i = 1; i <= 10000; i++) {
        for (int j = 0; j < 10; j++)
            Mat[i][j] = Mat[i - 1][j];

        int K = i;
        while (K) {
            ++Mat[i][K % 10];
            K /= 10;
        }
    }
}

int main() {
    //freopen("testI.txt", "r", stdin);
    //freopen("testO.txt", "w", stdout);

    Cal();

    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        for (int i = 0; i < 10; i++) {
            if (i > 0) printf(" ");
            printf("%d", Mat[N][i]);
        }
        printf("\n");
    }
}
