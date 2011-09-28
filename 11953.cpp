#include <stack>
#include <cstdio>
using namespace std;

char Mat[110][110];
int N;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void dfs(int i, int j) {
	stack< pair<int, int> > S;
	S.push(make_pair(i, j));
	while (!S.empty()) {
		pair<int, int> P = S.top();
		S.pop();
		i = P.first;
		j = P.second;
		if (i < 0 || i >= N) continue;
		if (j < 0 || j >= N) continue;
		if (Mat[i][j] == '.')continue;
	
		Mat[i][j] = '.';
		for (int I = 0; I < 4; I++)
			S.push(make_pair(i + dx[I], j + dy[I]));
	}
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		scanf("%d", &N);
		int i, j;
		int cnt = 0;
		
		for (i = 0; i < N; i++)
			scanf("%s", Mat[i]);

		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				if (Mat[i][j] == 'x') {
					cnt++;
					dfs(i, j);
				}
				
		printf("Case %d: %d\n", t, cnt);
	}
	return 0;
}
