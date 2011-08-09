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

#define MAXN 1027

int Field[MAXN][MAXN];
int rad, MaxR, MaxC, MaxRat;

void Select(int x, int y, int rat) {
	if(x > MaxR) return;
	if(x < MaxR) {
		MaxR = x;
		MaxC = y;
		return;
	}
	if(x == MaxR) {
		if(y > MaxC) return;
		MaxC = y;
	}
}

void Set(int x, int y, int rat) {
	int tempx, tempy, i, j;
	tempx = x - rad;
	tempy = y - rad;
	for (i = tempx; i<= x + rad; i++) {
		if (i < 0) continue;
		if (i > 1024) break;
		for (j = tempy; j <= y + rad; j++){
			if (j < 0) continue;
			if (j > 1024) break;
			Field[i][j] += rat;
			if (Field[i][j] > MaxRat) {
				MaxR = i;
				MaxC = j;
				MaxRat = Field[i][j];
			}
			else if (Field[i][j] == MaxRat)
				Select(i, j, Field[i][j]);
		}
	}
}

int main() {
	int kase, popu;
	int i, x, y, rat;
	scanf("%d", &kase);
	while (kase--) {
		scanf("%d", &rad);
		scanf("%d", &popu);
		MaxRat = 0;
		MaxR = MaxC = 1024;
		for (i = 0; i < popu; i++){
			scanf("%d%d%d",&x, &y, &rat);
			Set(x, y, rat);
		}
		printf("%d %d %d\n",MaxR, MaxC, MaxRat);
		for (i = 0; i <= 1025; i++)
			memset(Field[i],0,sizeof(int)*1026);
	}
	return 0;
}
