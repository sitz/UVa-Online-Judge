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

struct Type{
	int tt;
	string ss;
	int ii;
	Type(int _t, int _i, string _s){
		tt = _t; ii = _i; ss = _s;
	}
};

bool comp(Type A, Type B){
	if( A.tt != B.tt )
		return A.tt < B.tt;
	return A.ii < B.ii;
}

int main(){
	freopen("testI.txt", "r", stdin);
	freopen("testO.txt", "w", stdout);
	int T;
	cin >> T;
	while( T-- ){
		int N, t, M;
		cin >> N >> t >> M;
		int i;
		queue< Type > q;
		vector<Type> V;
		map<int, int> Map;
		int tot = 0;
		string side = "left";
		FOI(i, 0, M-1){
			int I;
			string S;
			cin >> I >> S;
			V.push_back( Type(I, i, S) );
		}
		sort(V.begin(), V.end(), comp);
		FOI(i, 0, M-1)
			q.push(V[i]);
		while( !q.empty() ){
			Type p = q.front();
			
			tot += max(0, p.tt - tot);
			if( p.ss != side ){
				tot += t;
				side = p.ss;
			}
			int cnt = 0;
			while( !q.empty() && p.tt <= tot && cnt <= N && p.ss == side ){
				q.pop();
				++cnt;
				Map[p.ii] = tot + t;
				if( q.empty() )
					break;
				p = q.front();
			}
			tot += t;
			if( side == "left" )
				side = "right";
			else
				side = "left";
		}
		FOI(i, 0, M-1)
			cout << Map[i] << endl;
		if( T > 0 )
			cout << endl;
	}
	return 0;
}
