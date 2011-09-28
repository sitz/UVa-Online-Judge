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
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX 1000000
static bool prime[MAX + 1];
static int cPrime[MAX + 1];

void sieve() {
	prime[0] = true;
	prime[1] = true;
	
	for (int i = 2; i * i <= MAX; i++) {
		if (!prime[i]) {
			for (int j = i; i * j <= MAX; j++) {
				prime[i * j] = true;
			}
		}
	}
}

vector< int > digits(int I) {
	vector< int > V;
	while (I > 0) {
		V.push_back(I % 10);
		I /= 10;
	}
	reverse(V.begin(), V.end());
	return V;
}

void cal() {
	for (int i = 1; i <= MAX; i++) {
		cPrime[i] = cPrime[i - 1];
		if (!prime[i]) {
			bool flag = true;
			vector< int > V = digits(i);
			for (int j = 0; j < V.size(); j++) {
				int I = 0;
				for (int k = 0; k < V.size(); k++)
					I = I * 10 + V[(j + k) % V.size()];
				if (prime[I])
					flag = false;
			}
			if (flag)
				++cPrime[i];
		}
	}
}

int main() {
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	sieve();
	cal();
	while (true) {
		int A, B;
		scanf("%d", &A);
		if (A == -1) break;
		scanf("%d", &B);
		
		int C = cPrime[B] - cPrime[A - 1];
		if (C <= 0)
			printf("No Circular Primes.\n");
		else if (C == 1)
			printf("1 Circular Prime.\n");
		else
			printf("%d Circular Primes.\n", C);
	}
	return 0;
}
