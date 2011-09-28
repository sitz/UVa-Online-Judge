#include <set>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    //freopen("testI.txt", "r", stdin);
    //freopen("testO.txt", "w", stdout);
    while (true) {
        int N, B;
        scanf("%d%d", &N, &B);
        if (!N && !B) break;

        set< int > Set;
        int Arr[B];
        for (int i = 0; i < B; i++) scanf("%d", &Arr[i]);

        for (int i = 0; i < B; i++)
            for (int j = i; j < B; j++) {
                int T = (int)abs(Arr[i] - Arr[j]);
                if (T <= N) Set.insert(T);
            }
        if (Set.size() == N + 1) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
