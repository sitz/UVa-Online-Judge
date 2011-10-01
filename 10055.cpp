#include <cstdio>

int main() {
    int p,q,r;
    while (scanf("%d %d",&p,&q) != EOF){
	r=q-p;
	if (r < 0) r *= -1;
	printf("%ld\n",r);
    }
    return 0;
}
