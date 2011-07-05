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

#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)
#define MAX	1000000

bool prime[MAX + 5];

void seive(){
	memset(prime, true, sizeof prime);
	prime[0] = false; prime[1] = false;
	int i, j;
	FOI(i, 2, MAX)
		if( prime[i] )
			for (j = 2*i; j <= MAX; j += i)
				prime[j] = false;
}

int reverse(int N){
	int R = 0;
	while( N > 0 ){
		R = R*10 + N%10;
		N /= 10;
	}
	return R;
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	seive();
	int N;
	while( cin >> N ){
		if( !prime[N] )
			cout << N << " is not prime." << endl;
		else{
			int R = reverse(N);
			if( prime[R] && N != R )
				cout << N << " is emirp." << endl;
			else
				cout << N << " is prime." << endl;
		}
	}
	return 0;
}
