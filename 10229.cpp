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

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;

#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)
#define PI		acos(-1.0)
#define INF		1<<30
#define EPS		1e-9
#define sqr(x)	(x)*(x)

int64[][2] multiply(int64 A[2][2], int64 B[2][2], int64 MOD){
	int64 M[2][2];	
	M[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD;
	M[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD;
	M[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD;
	M[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD;
	return M;
}

int64[][2] power(int64 N, int64 MOD){
	int64 F[2][2] = {{1, 1}, {1, 0}};
	int64 A[2][2];
	if (N == 0)
		return A;
	if (N == 1)
		return F;
	else if (N & 1)
		return multiply(F, power(N - 1, MOD), MOD);
	else{
		int64 M[][] = power(N / 2);
		return multiply(M, M, MOD);
	}
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	while (true){
		int64 N, M;
		cin >> N >> M;
		int64 MOD = 1 << M;
		cout << power(B, N, MOD)[0][1] % MOD << endl;
	}
	return 0;
}

