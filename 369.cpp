#include <cstdio>
using namespace std;

long gcd(long A, long B) {
    if (A % B == 0) return B;
    return gcd(B, A % B);
}

void Divbygcd(long& A, long& B) {
    long g = gcd(A, B);
    A /= g;
    B /= g;
}

long C(long N, long K) {
    long num = 1, den = 1, toMul, toDiv;
    if (K > N/2) K = N - K;

    for (int i = K; i; i--) {
        toMul = N - K + i;
        toDiv = i;
        Divbygcd(toMul, toDiv);
        Divbygcd(toMul, den);
        Divbygcd(toDiv, num);

        num *= toMul;
        den *= toDiv;
    }
    return num / den;
}

int main() {
    while (true) {
        long N, M;
        scanf("%ld%ld", &N, &M);
        if (!N && !M) break;

        printf("%ld things taken %ld at a time is %ld exactly.\n", N, M, C(N, M));
    }
}
