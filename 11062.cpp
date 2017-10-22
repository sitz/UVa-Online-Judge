#include <bits/stdc++.h>

using namespace std;

set<string>S;
char ss[100000];
char W[503][1000];
int ind;

void Parse()
{
    int i, j;
    char *p, xx[1000];

    for(i = 0; ss[i]; i++) {
        ss[i] = tolower(ss[i]);

        if(!isalpha(ss[i]) && ss[i] != '-')
            ss[i] = ' ';
    }

    p = strtok(ss, " ");

    while(p) {
        strcpy(W[ind++], p);
        p = strtok(NULL, " ");
    }
}
void Cal()
{
    int p = 1, l;
    char xx[1000];
    strcpy(xx, W[0]);

    while(p < ind) {
        l = strlen(W[p - 1]);

        if(W[p - 1][l - 1] == '-') {
            l = strlen(xx);
            xx[l - 1] = NULL;
            strcat(xx, W[p]);
        } else {
            S.insert(xx);
            strcpy(xx, W[p]);
        }

        p++;
    }

    S.insert(xx);
    set<string>::iterator d;

    for(d = S.begin(); d != S.end(); d++) {
        cout << *d << endl;
    }
}
int main()
{
//  freopen("c:\\h.txt","r",stdin);
    ind = 0;

    while(gets(ss)) {
        Parse();
    }

    Cal();
    return 0;
}

