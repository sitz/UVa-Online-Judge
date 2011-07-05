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

map< string, list< string > > Map;
list< string >::iterator lit;
map< string, bool > used;
vector< string > dict;

int bfs(string src, string des){
	queue< pair<string, int> > q;
	q.push( make_pair(src, 0) );
	while( !q.empty() ){
		pair<string, int> p = q.front();
		q.pop();
		
		if( p.first == des )
			return p.second;
		if( used[p.first] )
			continue;
		
		for (lit = Map[p.first].begin(); lit != Map[p.first].	end(); lit++)
			q.push( make_pair(*lit, p.second + 1) );
		
		used[p.first] = true;
	}
	return -1;
}

bool diff(string A, string B){
	int i, cnt = 0;
	int AL = A.length();
	int BL = B.length();
	if( AL != BL )
		return false;
	FOI(i, 0, AL-1)
		if( A[i] != B[i] )
			cnt++;
	if( cnt ==  1 )
		return true;
	return false;
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int T, i, j;
	cin >> T;
	string str;
	getline(cin, str); getline(cin, str);
	while( T-- ){
		Map.clear(); dict.clear(); used.clear();
		while( true ){
			getline(cin, str);
			if( str == "*" )
				break;
			dict.push_back(str);
		}
		sort(dict.begin(), dict.end());
		FOI(i, 0, dict.size()-1){
			FOI(j, 0, dict.size()-1){
				if( diff(dict[i], dict[j]) ){
					Map[ dict[i] ].push_back( dict[j] );
					Map[ dict[j] ].push_back( dict[i] );
				}
			}
			used[ dict[i] ] = false;
		}
		while( getline(cin, str) ){
			if( str.empty() )
				break;
			used.clear();
			stringstream ss(str);
			string src, des;
			ss >> src >> des;
			cout << src << " " << des << " " << bfs(src, des) << endl;
		}
		if( T )
			cout << endl;
	}
	return 0;
}
