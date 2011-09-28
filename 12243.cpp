#include <cstdio>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

int main(){
    //freopen("testI.txt", "r", stdin);
    //freopen("testO.txt", "w", stdout);
    while (true) {
        string SS, S;
        getline(cin, SS);
        if (SS == "*") break;

        bool flag = true;
        stringstream ss(SS);
        ss >> S;
        char C = tolower(S[0]);
        while (ss >> S) {
            if (tolower(S[0]) != C) {
                flag = false;
                break;
            }
        }
        if (flag) cout << "Y\n";
        else cout << "N\n";
    }
    return 0;
}
