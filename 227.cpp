#include <string>
#include <iostream>
using namespace std;

int main() {
	for (int p = 1; ; p++) {		
		string str;
		string mat[5];
		bool valid = true;
		while (true) {
			getline(cin, mat[0]);
			if (mat[0] == "Z") {
				return 0;
			}
			getline(cin, mat[1]);
			getline(cin, mat[2]);
			getline(cin, mat[3]);
			getline(cin, mat[4]);
			
			int I, J;
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (mat[i][j] == ' ') {
						I = i; J = j;
						i = j = 5;
					}
				}
			}
					
			bool endPuzzle = false;
			while (!endPuzzle && getline(cin, str)) {
				
				for (int i = 0; i < str.length(); i++) {
				
					if (str[i] == '0' || !valid) {
						endPuzzle = true;
						break;
					}
					
					if (str[i] == 'A') {
						if (I <= 0) valid = false;
						else {
							mat[I][J] = mat[I - 1][J];
							--I;
							mat[I][J] = ' ';
						}
					}
					if (str[i] == 'B') {
						if (I >= 4) valid = false;
						else {
							mat[I][J] = mat[I + 1][J];
							++I;
							mat[I][J] = ' ';
						}
					}
					if (str[i] == 'L') {
						if (J <= 0) valid = false;
						else {
							mat[I][J] = mat[I][J - 1];
							--J;
							mat[I][J] = ' ';
						}
					}
					if (str[i] == 'R') {
						if (J >= 4) valid = false;
						else {
							mat[I][J] = mat[I][J + 1];
							++J;
							mat[I][J] = ' ';
						}
					}
				}
			}
		}
		
		if (p > 1)
			cout << endl;
			
		cout << "Puzzle #" << p << ":\n";
		if (!valid) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (j) cout << " ";
					cout << mat[i][j];
				}
				cout << endl;
			}
		}
		else {
			cout << "This puzzle has no final configuration.\n";
		}
	}
	return 0;
}
