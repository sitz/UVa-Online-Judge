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
#include <complex>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <ctime>
using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

#define PI				acos(-1.0)
#define EPS				1e-9
#define INF				1<<30

#define FOI(I, A, B)	for (I=A; I<=B; I++)
#define FOD(I, A, B)	for (I=A; I>=B; I--)

void showGraph(vector< vector <int> > G){
	int i, j;
	FOI(i, 0, G.size()-1){
		FOI(j, 0, G[i].size()-1)
			cout << G[i][j] << " ";
			
		cout << endl;
	}
}

void showVector( vector <int> vec ){
	int i;
	FOI(i, 0, vec.size()-1)
		cout << vec[i] << " ";
}

int toInt(string s){
	stringstream ss;
	int I;
	ss << s;
	ss >> I;
	return I;
}

void Tokenize(const string& str, vector<int>& tokens, const string& delimiters = " -,\n"){

    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos){
        tokens.push_back(toInt(str.substr(lastPos, pos - lastPos)));
        lastPos = str.find_first_not_of(delimiters, pos);
        pos = str.find_first_of(delimiters, lastPos);
    }
}

int main(){
	freopen("testI.txt", "r", stdin);
	freopen("testO.txt", "w", stdout);
	int N, n;
    while( scanf("%d", &N) ){
    	vector< vector <int> > graph(N);
    	FOI(n, 1, N){
			string str;
			vector<int> tokens;
			getline(cin, str);
			Tokenize(str, tokens);
			int I = n - 1;
			tokens.erase(tokens.begin());
			graph[I] = tokens;
    	}
    	cout << "-----" << endl;
    	int Q, S, D;
    	cin >> Q;
    	while( Q-- )
    		cin >> S >> D;
    	showGraph(graph);
    }
	return 0;
}
