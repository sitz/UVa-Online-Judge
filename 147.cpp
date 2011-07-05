#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <cmath>
#define N 1000000
using namespace std;

int main (){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
    int coins [] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
    double dp [6000 + 10];

    memset (dp, 0, sizeof (dp));

    dp [0] = 1;

    for ( int i = 0; i < 11; i++ ) {
        for ( int j = 1; j <= 6000; j++ ) {
            if ( j - coins [i] >= 0 )
                dp [j] += dp [j - coins [i]];
        }
    }

    double c;

    while ( scanf ("%lf", &c) ) {
        if ( c <= 0 ) break;
        int index = c * 20;

        printf ("%6.2lf%17.lf\n", c, dp [index]);
    }

    return 0;
}
