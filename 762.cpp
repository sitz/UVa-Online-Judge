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

struct Node{
	string str;
	int cost;
	vector< pair<string, string> > vec;
};

map< string, list<string> > adj;
map< string, bool > used;

int bfs(string src, string des){
	queue< Node > q;
	Node node;
	node.str = src;
	node.cost = 0;
	q.push( node );
	while( !q.empty() ){
		n = q.front();
		q.pop();
		
		if( n.str == des )
			return n;
		if( used[n.str] )
			continue;
		
		for (lit = adj[n.str].begin(); lit != adj[n.str].end(); lit++){
			Node nod;
			nod.str = 
		
		used[p.first] = true;
	}
	return -1;
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	bool multi = false;
	int N;
	while( cin >> N ){
		string src, des;
		FOI(i, 1, N){
			cin >> src >> des;
			adj[src].push_back(des);
			adj[des].push_back(src);
		}
		cin >> src >> des;
		int cost = bfs(src, des);
		if( cost < 0 )
			cout << "No route" << endl;
		else{
			
		}
	}
	return 0;
}
