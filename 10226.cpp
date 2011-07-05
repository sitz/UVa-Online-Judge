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
		string str;
		map<string, double> Tree;
		map<string, double>::iterator it;
		double tot = 0;
		while (true){
			getline(cin, str);
			if (str == "")
				break;
			Tree[str] += 1.0;
			tot 	  += 1.0;
		}
		tot /= 100.0;
		for (it = Tree.begin(); it != Tree.end(); it++)
			printf("%s %.4lf\n", ((*it).first).c_str(), ((*it).second) / tot);
		if (T)
			cout << endl;
	}
	return 0;
}

