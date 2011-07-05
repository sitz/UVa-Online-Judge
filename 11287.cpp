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
#define PI     acos(-1.0)
#define INF    1<<30
#define EPS    1e-9
#define sqr(x) (x)*(x)
#define MAX	32000

bool prime[MAX + 1];
vector< int64 > Prime;
int64 SZ;

void seive(){
	memset(prime, true, sizeof prime);
	prime[0] = false; prime[1] = false;
	int64 i, j;
	FOI(i, 2, MAX){
		if (prime[i]){
			Prime.push_back(i);
			for(j = 2 * i; j <= MAX; j += i)
				prime[j] = false;
		}
	}
	SZ = Prime.size() - 1;
}

int64 Bigmod(int64 a, int64 b, int64 n){
	int64 c=0,d=1,k=0;
	int64 arr[100];
	while(b){
		arr[k++]=b%2;      
		b/=2;
	}
	while(k--){
		c=2*c;
		d=(d*d)%n;
		if(arr[k]==1){
			c=c+1;
			d=(d*a)%n;
		}
	}
	return d;
}

int64 modPow(int64 A, int64 P, int64 M){
	if (P == 0)
		return 1;
	if( P == 1 )
		return A%M;
	int64 V = modPow(A, P/2, M);
	V = (V%M * V%M) %M;
	if( P % 2 == 1 )
		V = (V%M * A%M) %M;
	return V%M;
}

bool checkPrime(int64 P){
	int64 S = sqrt(P + 0.5);
	int64 i, j;
	FOI(i, 2, S)
		if (P % i == 0)
			return true;
	return false;
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	//seive();
	while (true){
		int64 P, A;
		cin >> P >> A;
		if (P == 0 && A == 0)
			break;
		bool stat = checkPrime(P);
		int64 V = modPow(A, P, P);
		if (stat && V == A)
			cout << "yes";
		else
			cout << "no";
		cout << endl;
	}
	return 0;
}

