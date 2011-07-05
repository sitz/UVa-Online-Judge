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

typedef long long int64;
typedef unsigned long long uint64;

#define INF	1LL<<60
#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)

map<int, vector<int> >adj;
map<int, vector<int> >::iterator it1, it2, it3;
map<int, bool> use;
		
int bfs(int src, int des){
	queue< pair<int, int> > q;
	q.push(make_pair(src, 0));
	while( !q.empty() ){
		pair<int, int> p = q.front();
		q.pop();
		if( use[p.first] )
			continue;
		if( p.first == des )
			return p.second;
		int i;
		FOI(i, 0, adj[p.first].size()-1)
			q.push( make_pair(adj[p.first][i], p.second + 1) );
		use[p.first] = true;
	}
	return 0;
}

int main(){
	freopen("testI.txt", "r", stdin);
	freopen("testO.txt", "w", stdout);
	for(int T = 1; ; T++){
		adj.clear();
		int i, j, k;
		int A, B;
		scanf("%d%d", &A, &B);
		if(A == 0 && B == 0)
			break;
		adj[A-1].push_back(B-1);
		while( true ){
			scanf("%d%d", &A, &B);
			if(A == 0 && B == 0)
				break;
			adj[A-1].push_back(B-1);
		}
		int N = adj.size();
		double den = 0;
		double num = 0;
			
		for (it1 = adj.begin(); it1 != adj.end(); it1++){
			for (it2 = adj.begin(); it2 != adj.end(); it2++){
				if((*it1).first != (*it2).first){
					use.clear();
					for (it3 = adj.begin(); it3 != adj.end(); it3++)
						use[(*it3).first] = false;
					num += bfs((*it1).first, (*it2).first);
					den += 1;
				}
			}
		}
					
		printf("Case %d: average length between pages = %.3lf clicks\n", T, num/den);
	}
	return 0;
}
