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

#define INF			 1<<30
#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)

string mat[500];
string use[500];
int N;

void display(string matrix[]){
	int i;
	FOI(i, 0, N-1)
		cout << matrix[i] << endl;
	
	cout << endl;
}
			

struct Node{
	int II, JJ, DD;
	Node(){};
	Node(int _I, int _J, int _D){
		II = _I; JJ = _J; DD = _D;
	}
};

int dI[] = {0, -1, 0, 1};
int dJ[] = {-1, 0, 1, 0};

int bfs(int I, int J){
	queue<Node> q;
	q.push(Node(I, J, 0));
	while( !q.empty() ){
		Node n = q.front();
		q.pop();
		if( n.II < 0 || n.II >= N )
			continue;
		if( n.JJ < 0 || n.JJ >= N )
			continue;
		if( use[n.II][n.JJ] == '0' )
			continue;
		
		if( use[n.II][n.JJ] == '3' )
			return n.DD;
		use[n.II][n.JJ] = '0';
		int j;
		FOI(j, 0, 3)
			q.push( Node(n.II + dI[j], n.JJ + dJ[j], n.DD + 1) );
	}
	return 0;
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	while( cin >> N ){
		int i, j, k;
		FOI(i, 0, N-1)
			cin >> mat[i];
		int gmin = 1;
		FOI(i, 0, N-1){
			FOI(j, 0, N-1){
				if( mat[i][j] == '1' ){
					FOI(k, 0, N-1)
						use[k] = mat[k];
					//display(use);
					gmin = max(gmin, bfs(i, j));
				}
			}
		}
		//display(use);
		cout << gmin << endl;
	}
	return 0;
}
