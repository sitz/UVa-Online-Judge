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

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int T;
	scanf("%d\n", &T);
	while (T--){
		int N;
		scanf("%d\n", &N);
		string str;
		vector< vector<int> >  V(N);
		int M = N, i, j;
		FOI(i, 0, N-1){
			getline(cin, str);
			stringstream ss;
			int I;
			ss << str;
			while (ss >> I)
				V[i].push_back(I);
			M = min((int)V[i].size(), M);
		}
		vector< int > vec;
		FOI(i, 0, N-1)
			if (V[i].size() == M)
				vec.push_back(i + 1);
		FOI(i, 0, vec.size()-1){
			cout << vec[i];
			if (i < vec.size() - 1)
				cout << " ";
			else
				cout << "\n";
		}
		if (T)
			getline(cin, str);
	}
	return 0;
}

