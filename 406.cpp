#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <sstream>
using namespace std;

#define MAX 1010
bool prime[MAX];
vector< int > P;

void sieve() {
	memset(prime, true, sizeof prime);
	prime[1] = prime[0] = false;
	P.push_back(1);
	for (int i = 2; i < MAX; i++) {
		if (prime[i]) {
			P.push_back(i);
			for (int j = i * i; j < MAX; j += i)
				prime[j] = false;
		}
	}
	//printf("%d\n", P.size());
}


int main() {
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	sieve();
	
	int N, C;
	while (scanf("%d%d", &N, &C) != EOF) {
		printf("%d %d:", N, C);
		vector< int > V;
		for (int i = 0; i < P.size() && P[i] <= N; i++)
			V.push_back(P[i]);
		
		C *= 2;
		if (V.size() & 1) C -= 1;
		int A = floor(C / 2.0);
		int B = ceil(C / 2.0);
		
		for (int i = max(0, (int) V.size() / 2 - A); i < min((int)V.size(), (int)V.size() / 2 + B); i++)
			printf(" %d", V[i]);
		printf("\n\n");
	}
	return 0;
}
