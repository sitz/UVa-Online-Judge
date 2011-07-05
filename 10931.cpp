#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int Parity(int N){
	int cnt = 0;
	while( N ){
		cnt += N%2;
		N /= 2;
	}
	return cnt;
}

string toBinary(int N){
	string str = "";
	while( N ){
		if( N%2 )
			str = "1" + str;
		else
			str = "0" + str;
		N /= 2;
	}
	return str;
}

int main(){
	while( true ){
		int N;
		cin >> N;
		if( N == 0 )
			break;
		string bin = toBinary(N);
		int P = Parity(N);
		cout << "The parity of " << bin << " is " << P << " (mod 2)." << endl;
	}
	return 0;
}
