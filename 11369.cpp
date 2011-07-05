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

bool comp(int A, int B){
	return A >= B;
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int T;
	cin >> T;
	while( T-- ){
		int N;
		cin >> N;
		int price[N];
		int i, profit = 0;
		FOI(i, 0, N-1)
			cin >> price[i];
		sort(price, price + N, comp);
		for (i = 2; i < N; i += 3)
			profit += price[i];
		cout << profit << endl;
	}
	return 0;
}

