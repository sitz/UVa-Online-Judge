#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

int valueOf(char c) {
    switch(c) {
        case 'M': return 1000;
        case 'D': return 500;
        case 'C': return 100;
        case 'L': return 50;
        case 'X': return 10;
        case 'V': return 5;
        case 'I': return 1;
        default: return 0;
    }
}

int romanToDecimal(string S) {
    int decimalNumeral = 0;
    S += "0";
    for(int i = 0; i + 1 < S.length(); i++) {
        int current = valueOf(S[i]);
        int next = valueOf(S[i + 1]);
        if(current >= next) decimalNumeral += current;
        else decimalNumeral -= current;
    }
    return decimalNumeral;
}

string decimalToRoman(int value) {
	string roman[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	int decimal[13]  = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	
    string romanNumeral = "";
    /*
	if (value <= 0 || value >= 4000)
		return value;
  	*/
    for (int i = 0; i < 13; i++) {
      while (value >= decimal[i]) {
        value -= decimal[i];
        romanNumeral += roman[i];
      }
    }
    return romanNumeral;
}

int main() {
	int I;
	string S;
	stringstream ss;
	while (cin >> S) {
		if (isdigit(S[0])) {
			ss.clear();
			ss << S;
			ss >> I;
			cout << decimalToRoman(I) << endl;
		}
		else {
			cout << romanToDecimal(S) << endl;
		}
	}
	return 0;
}
