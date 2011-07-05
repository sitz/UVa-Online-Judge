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

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	vector< int > V;
	map<int, int> Map;
	map<int, int>::iterator it;
	int I, i, j;
	while (cin >> I){
		it = Map.find(I);
		if (it != Map.end())
			++Map[I];
		else{
			Map[I] = 1;
			V.push_back(I);
		}
	}
	FOI(i, 0, V.size()-1)
		cout << V[i] << " " << Map[V[i]] << endl;
	return 0;
}
