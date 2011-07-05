#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

const int MAX = 1000001;
static int NOD[MAX+10], pre[MAX+10];
bool stat[MAX+100];

int N;

int DivCnt(int M){
	int i;
	int cnt = 0;
	for( i=1; i*i < M; i++ )
		if( M % i == 0 )
			cnt += 2;
	if( i * i == M )
		cnt++;
	return cnt;
}

void NODCalculate(){
	memset( stat, false, sizeof stat );
	NOD[0] = 1;
	stat[1] = true;
	for ( int i=1; i < MAX; i++ ){
		NOD[i] = NOD[i-1] + DivCnt( NOD[i-1] );
		stat[NOD[i]] = true;
		//cout << NOD[i] << "\t";
		if( NOD[i] >= MAX ){
			//cout << i <<endl;
			N = i;
			return;
		}
	}
}

int main(){
	NODCalculate();
	pre[0] = 0;
	int i=1, j=1;
	bool flag = true;
	
	for( i=1; i<=MAX; i++ ){
		if( stat[i] )
			pre[i] = pre[i-1] + 1;
		else
			pre[i] = pre[i-1];
	}
	
	int T;
	scanf("%d", &T);
	for (int t=1; t<=T; t++){
		int A, B, sum=0;
		scanf("%d%d", &A, &B);
		printf("Case %d: %d\n", t, pre[B] - pre[A-1]);
	}
	return 0;
}
