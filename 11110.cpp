#include <cstdio>
#include <sstream>
#include <cstring>
#include <iostream>
using namespace std;

int Mat[101][101];
int N = 0;

int dI[] = {-1, 0, 1, 0};
int dJ[] = {0, 1, 0, -1};
void dfs(int I, int J, int C) {
	if (I < 0 || I >= N) return;
	if (J < 0 || J >= N) return;
	if (Mat[I][J] == -1) return;
	if (Mat[I][J] != C)  return;
	
	Mat[I][J] = -1;
	for (int i = 0; i < 4; i++)
		dfs(I + dI[i], J + dJ[i], C);
}

int main() {
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	
	while (true) {
		scanf("%d\n", &N);
		if (!N) break;
		
		memset(Mat, 0, sizeof (Mat));
		
		for (int i = 1; i < N; i++) {
			string str;
			getline(cin, str);
			stringstream ss(str);
			int A, B;
			while (ss >> A >> B)
				Mat[A - 1][B - 1] = i;
		}
		
		int arr[N];
		memset(arr, 0, sizeof arr);
		
		bool flag = true;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (Mat[i][j] < 0) continue;
				
				if (arr[Mat[i][j]] > 0) {
					flag = false;
					break;
				}
				
				++arr[Mat[i][j]];
				dfs(i, j, Mat[i][j]);
			}
			if (!flag) break;
		}
		
		if (flag)	printf("good\n");
		else		printf("wrong\n");
	}
}
