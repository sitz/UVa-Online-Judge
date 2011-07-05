#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	while (true){
		int L, C, R1, R2;
		scanf("%d%d%d%d", &L, &C, &R1, &R2);
		if (L == 0 && C == 0 && R1 == 0 && R2 == 0)
			break;
		double R = R1 + R2;
		double newL = L - R;
		double newC = C - R;
		double dia = sqrt(newL * newL + newC * newC);
		if(dia >= R && 2 * max(R1, R2) <= min(L, C))
			printf("S\n");
		else
			printf("N\n");
	}
	return 0;
}
