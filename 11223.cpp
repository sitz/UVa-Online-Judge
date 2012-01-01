#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char *argv[]) {
    int T;
    char ar[2005], tmp[10];

    cin >> T;
    getchar();
    memset(tmp, '\0', sizeof(tmp));

    for(int i = 1; i <= T; i++) {
        memset(ar, '\0', sizeof(ar));
        gets(ar);
        int len = strlen(ar), index = 0;

        cout << "Message #" << i << endl;

        for(int j = 0; j < len; j++) {
            if(ar[j] != ' ' )
                tmp[index++] = ar[j];
            if(ar[j] == ' ' || j == len - 1) {
                if(strcmp(tmp,".-" ) == 0)
                    cout << "A";
                else if(strcmp(tmp,"-..." ) == 0)
                    cout << "B";
                else if(strcmp(tmp,"-.-." ) == 0)
                    cout << "C";
                else if(strcmp(tmp,"-.." ) == 0)
                    cout << "D";
                else if(strcmp(tmp,"." ) == 0)
                    cout << "E";
                else if(strcmp(tmp,"..-." ) == 0)
                    cout << "F";
                else if(strcmp(tmp,"--." ) == 0)
                    cout << "G";
                else if(strcmp(tmp,"...." ) == 0)
                    cout << "H";
                else if(strcmp(tmp,".." ) == 0)
                    cout << "I";
                else if(strcmp(tmp,".---" ) == 0)
                    cout << "J";
                else if(strcmp(tmp,"-.-" ) == 0)
                    cout << "K";
                else if(strcmp(tmp,".-.." ) == 0)
                    cout << "L";
                else if(strcmp(tmp,"--" ) == 0)
                    cout << "M";
                else if(strcmp(tmp,"-." ) == 0)
                    cout << "N";
                else if(strcmp(tmp,"---" ) == 0)
                    cout << "O";
                else if(strcmp(tmp,".--." ) == 0)
                    cout << "P";
                else if(strcmp(tmp,"--.-" ) == 0)
                    cout << "Q";
                else if(strcmp(tmp,".-." ) == 0)
                    cout << "R";
                else if(strcmp(tmp,"..." ) == 0)
                    cout << "S";
                else if(strcmp(tmp,"-" ) == 0)
                    cout << "T";
                else if(strcmp(tmp,"..-" ) == 0)
                    cout << "U";
                else if(strcmp(tmp,"...-" ) == 0)
                    cout << "V";
                else if(strcmp(tmp,".--" ) == 0)
                    cout << "W";
                else if(strcmp(tmp,"-..-" ) == 0)
                    cout << "X";
                else if(strcmp(tmp,"-.--" ) == 0)
                    cout << "Y";
                else if(strcmp(tmp,"--.." ) == 0)
                    cout << "Z";
                else if(strcmp(tmp,"-----" ) == 0)
                    cout << "0";
                else if(strcmp(tmp,".----" ) == 0)
                    cout << "1";
                else if(strcmp(tmp,"..---" ) == 0)
                    cout << "2";
                else if(strcmp(tmp,"...--" ) == 0)
                    cout << "3";
                else if(strcmp(tmp,"....-" ) == 0)
                    cout << "4";
                else if(strcmp(tmp,"....." ) == 0)
                    cout << "5";
                else if(strcmp(tmp,"-...." ) == 0)
                    cout << "6";
                else if(strcmp(tmp,"--..." ) == 0)
                    cout << "7";
                else if(strcmp(tmp,"---.." ) == 0)
                    cout << "8";
                else if(strcmp(tmp,"----." ) == 0)
                    cout << "9";
                else if(strcmp(tmp,".-.-.-" ) == 0)
                    cout << ".";
                else if(strcmp(tmp,"--..--" ) == 0)
                    cout << ",";
                else if(strcmp(tmp,"..--.." ) == 0)
                    cout << "?";
                else if(strcmp(tmp,".----." ) == 0)
                    cout << "'";
                else if(strcmp(tmp,"-.-.--" ) == 0)
                    cout << "!";
                else if(strcmp(tmp,"-..-." ) == 0)
                    cout << "/";
                else if(strcmp(tmp,"-.--." ) == 0)
                    cout << "(";
                else if(strcmp(tmp,"-.--.-" ) == 0)
                    cout << ")";
                else if(strcmp(tmp,".-..." ) == 0)
                    cout << "&";
                else if(strcmp(tmp,"---..." ) == 0)
                    cout << ":";
                else if(strcmp(tmp,"-.-.-." ) == 0)
                    cout << ";";
                else if(strcmp(tmp,"-...-" ) == 0)
                    cout << "=";
                else if(strcmp(tmp,".-.-." ) == 0)
                    cout << "+";
                else if(strcmp(tmp,"-....-" ) == 0)
                    cout << "-";
                else if(strcmp(tmp,"..--.-" ) == 0)
                    cout << "_";
                else if(strcmp(tmp,".-..-." ) == 0)
                    cout << char(34);
                else if(strcmp(tmp,".--.-." ) == 0)
                    cout << "@";
                if(ar[j+1] == ' ' ) {
                    cout << " ";
                    j++;
                }
                memset(tmp,'\0',sizeof(tmp));
                index = 0;
            }
        }
        cout << endl;
        if(i != T) cout << endl;
    }
    return EXIT_SUCCESS;
}

