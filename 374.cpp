#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long int64;

#define square(x) (x)*(x)

int64 BigMod(int64 B, int64 E, int64 N) {
	if(E == 0)
		return 1;
		
	int64 V = BigMod(B, E/2, N);
	V = (V %N * V %N) %N;
	
	if(E % 2 == 1)
		V = (B %N * V %N) %N;
	return V %N;
}

int main(){
    int64 B, E, N;
	while (scanf("%lld%lld%lld", &B, &E, &N) != EOF)
		printf("%lld\n", BigMod(B, E, N);

    return 0;
}
