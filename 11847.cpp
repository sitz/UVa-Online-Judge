#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    while(true){
                int n;
                scanf("%d", &n);
                if(n==0)
                        break;
                printf("%d\n", (int)floor(log2(n)));
    }
    return 0;
}
