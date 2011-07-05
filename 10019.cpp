#include <iostream>
using namespace std;

int hexa[] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2};

int countHex(int N){
	int cnt = 0;
	while( N ){
		cnt += hexa[N%10];
		N /= 10;
	}
	return cnt;
}

int countDec(int N){
	int cnt = 0;
	while( N ){
		cnt += N%2;
		N /= 2;
	}
	return cnt;
}

int main(){
	int T;
	cin >> T;
	while( T-- ){
		int N;
		cin >> N;
		int B1 = countDec(N);
		int B2 = countHex(N);
		//int V = N ^ ( B1 * B2 );
		cout << B1 << " " << B2 << endl;
	}
}
