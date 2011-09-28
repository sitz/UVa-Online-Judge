#include <map>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    //freopen("testI.txt", "r", stdin);
    //freopen("testO.txt", "w", stdout);

    map<string, string> Map;
    Map["HELLO"] = "ENGLISH";  Map["HOLA"] = "SPANISH"; Map["HALLO"] = "GERMAN";
    Map["BONJOUR"] = "FRENCH"; Map["CIAO"] = "ITALIAN"; Map["ZDRAVSTVUJTE"] = "RUSSIAN";

    for (int t = 1; ; t++){
        string str;
        cin >> str;
        if (str == "#") break;

        if (Map.find(str) != Map.end())
            cout << "Case " << t << ": " << Map[str] << endl;
        else
            cout << "Case " << t << ": UNKNOWN" << endl;
    }
    return 0;
}
