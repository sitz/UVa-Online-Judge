#include <cstdio>
typedef long long int64;
int main(){
    while(true){
                int64 A, B, C;
                scanf("%lld%lld%lld", &A, &B, &C);
                if(A==0 && B==0 && C==0)
                              break;
                int64 Asq=A*A, Bsq=B*B, Csq=C*C;
                if(Asq+Bsq==Csq || Asq+Csq==Bsq || Csq+Bsq==Asq)
                                printf("right\n");
                else
                    printf("wrong\n");
    }
    return 0;
}
