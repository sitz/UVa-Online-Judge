#include<cstdio>
using namespace std;
int main() {
    long p,q,r;
    while (scanf("%ld %ld",&p,&q)!=EOF) {
    r=q-p;
 	if(r<0)
 	       r*=-1;
    printf("%ld\n",r);
    }
	return 0;
}
