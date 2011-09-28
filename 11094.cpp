#include <cstdio>
#include <stack>
#include <cmath>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

string Map[50];
int M, N;
char land;

int dI[] = {-1, 0, 1, 0};
int dJ[] = {0, 1, 0, -1};
int dfs(int A, int B) {
	stack< pair<int, int> > S;
	S.push(make_pair(A, B));
	int V = 0;
	while (!S.empty()) {
		pair<int, int> P = S.top();
		S.pop();
		int I = P.first;
		int J = P.second;
		if (I < 0 || I >= M)  continue;
		if (J < 0 || J >= N)  continue;
		if (Map[I][J] != land)continue;
	
		Map[I][J] = ' ';
		++V;
		for (int i = 0; i < 4; i++)
			S.push(make_pair(I + dI[i], (J + dJ[i] + N) % N));
	}
	return V;
}

int main() {
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	
	while (cin >> M >> N) {
		string str;
		for (int i = 0; i < M; i++)
			cin >> Map[i];

		int A, B, Max = 0;
		cin >> A >> B;
		
		land = Map[A][B];
		dfs(A, B);
		
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
					Max = max(Max, dfs(i, j));

		cout << Max << endl;
	}
	return 0;
}
