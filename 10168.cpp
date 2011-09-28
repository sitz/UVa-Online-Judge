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

#define FOI(i, A, B) for (i = A; i <= B; i++)
#define FOD(i, A, B) for (i = A; i >= B; i--)
#define MAX 3165

int N;
vector< int > Prime;
bool P[MAX + 1];
map<int, vector< int > > Map;

void seive() {
	memset(P, true, sizeof P);
	P[0] = false; P[1] = false;
	int i, j;
	FOI(i, 2, MAX) {
		if (P[i]) {
			Prime.push_back(i);
			for (j = i * i; j <= MAX; j+= i)
				P[j] = false;
		}
	}
	N = Prime.size() - 1;
	cout << N << endl;
}

void Cal() {
	FOI(a, 0, N) {
		int V = Prime[a];
		FOI(b, a, N) {
			V += Prime[b];
			FOI(c, b, N) {
				V += Prime[c];
				FOI(d, c, N) {
					V += Prime[d];
				}
			}
		}
	}
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	seive();
	Cal();
	return 0;
}
