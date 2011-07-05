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

struct Team{
	string name;
	int X, Y;
};

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	while( true ){
		int N;
		cin >> N;
		if( N == 0 )
			break;
		Team team[N];
		FOI(i, 0, N-1)
			cin >> team[i].name >> team[i].X >> team[i].Y;
		sort(team, team + N, comp);
	}
	return 0;
}
