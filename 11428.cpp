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
	vector<int> cube;
	map<int, int> Map;
	int i, j;
	for (i = 0; i <= 200; i++){
		int val = i * i * i;
		Map[val] = i;
		cube.push_back(val);
	}
	while( true ){
		int N;
		cin >> N;
		if( N == 0 )
			break;
		bool flag = false;
		FOI(i, 0, 100){
			if( Map.find(N + cube[i]) != Map.end() ){
				cout << Map[N + cube[i]] << " " << i << endl;
				flag = true;
				break;
			}
		}
		if ( !flag )
			cout << "No solution\n";
	}
	return 0;
}
