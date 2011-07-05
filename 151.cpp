#include <cstdio>
#include <list>
using namespace std;

int N;

int simulation (int m){
    list <int> l;
	int i;
    for (i = 1; i <= N; i++)
		l.push_back (i);

    while ( l.size () > 1 ) {
        l.pop_front ();
        for (i = 1; i < m; i++) {
            l.push_back ( l.front () );
			l.pop_front ();
        }
    }
    return l.front ();
}

int main (){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
    while (scanf ("%d", &N)) {
        if (N == 0) break;
        int m = 1;
        int region = 0;
        while (true) {
            region = simulation (m);
			if (region == 13) break;
			m++;
        }
        printf("%d\n", m);
    }
    return 0;
}

