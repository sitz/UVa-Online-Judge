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

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;

#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)
#define PI	acos(-1.0)
#define INF	1<<30
#define EPS	1e-9
#define sqr(x)	(x)*(x)

struct Point{
	int64 X;
	int64 Y;
	int64 I;
};

bool comp(Point A, Point B){
	return A.I < B.I;
}

bool isSquare(Point point[]){
	do{
		int64 A = sqr(point[0].X - point[1].X) + sqr(point[0].Y - point[1].Y);
		int64 B = sqr(point[1].X - point[2].X) + sqr(point[1].Y - point[2].Y);
		int64 C = sqr(point[2].X - point[3].X) + sqr(point[2].Y - point[3].Y);
		int64 D = sqr(point[3].X - point[0].X) + sqr(point[3].Y - point[0].Y);
		if( A != B || B != C || C != D || D != A )
			continue;
	int64 P = (point[0].Y - point[1].Y) * (point[1].Y - point[2].Y) + (point[0].X - point[1].X) * (point[1].X - point[2].X);
	int64 Q = (point[1].Y - point[2].Y) * (point[2].Y - point[3].Y) + (point[1].X - point[2].X) * (point[2].X - point[3].X);
	int64 R = (point[2].Y - point[3].Y) * (point[3].Y - point[0].Y) + (point[2].X - point[3].X) * (point[3].X - point[0].X);
	int64 S = (point[3].Y - point[0].Y) * (point[0].Y - point[1].Y) + (point[3].X - point[0].X) * (point[0].X - point[1].X);
		if( P == 0 && Q == 0 && R == 0 && S == 0 )
			return true;
	}while( next_permutation(point, point + 4, comp) );
	
	return false;
}

bool isRectangle(Point point[]){
	do{
		int64 A = sqr(point[0].X - point[1].X) + sqr(point[0].Y - point[1].Y);
		int64 B = sqr(point[1].X - point[2].X) + sqr(point[1].Y - point[2].Y);
		int64 C = sqr(point[2].X - point[3].X) + sqr(point[2].Y - point[3].Y);
		int64 D = sqr(point[3].X - point[0].X) + sqr(point[3].Y - point[0].Y);
		if( A != C || B != D )
			continue;
	int64 P = (point[0].Y - point[1].Y) * (point[1].Y - point[2].Y) + (point[0].X - point[1].X) * (point[1].X - point[2].X);
	int64 Q = (point[1].Y - point[2].Y) * (point[2].Y - point[3].Y) + (point[1].X - point[2].X) * (point[2].X - point[3].X);
	int64 R = (point[2].Y - point[3].Y) * (point[3].Y - point[0].Y) + (point[2].X - point[3].X) * (point[3].X - point[0].X);
	int64 S = (point[3].Y - point[0].Y) * (point[0].Y - point[1].Y) + (point[3].X - point[0].X) * (point[0].X - point[1].X);
		if( P == 0 && Q == 0 && R == 0 && S == 0 )
			return true;
	}while( next_permutation(point, point + 4, comp) );
	
	return false;
}

bool isRhombus(Point point[]){
	do{
		int64 A = sqr(point[0].X - point[1].X) + sqr(point[0].Y - point[1].Y);
		int64 B = sqr(point[1].X - point[2].X) + sqr(point[1].Y - point[2].Y);
		int64 C = sqr(point[2].X - point[3].X) + sqr(point[2].Y - point[3].Y);
		int64 D = sqr(point[3].X - point[0].X) + sqr(point[3].Y - point[0].Y);
		if( A != B || B != C || C != D || D != A )
			continue;
	int64 P = (point[0].Y - point[1].Y) * (point[1].Y - point[2].Y) + (point[0].X - point[1].X) * (point[1].X - point[2].X);
	int64 Q = (point[1].Y - point[2].Y) * (point[2].Y - point[3].Y) + (point[1].X - point[2].X) * (point[2].X - point[3].X);
	int64 R = (point[2].Y - point[3].Y) * (point[3].Y - point[0].Y) + (point[2].X - point[3].X) * (point[3].X - point[0].X);
	int64 S = (point[3].Y - point[0].Y) * (point[0].Y - point[1].Y) + (point[3].X - point[0].X) * (point[0].X - point[1].X);
		if( P == R && Q == S )
			return true;
	}while( next_permutation(point, point + 4, comp) );
	
	return false;
}

bool isParallelogram(Point point[]){
	do{
		int64 A = sqr(point[0].X - point[1].X) + sqr(point[0].Y - point[1].Y);
		int64 B = sqr(point[1].X - point[2].X) + sqr(point[1].Y - point[2].Y);
		int64 C = sqr(point[2].X - point[3].X) + sqr(point[2].Y - point[3].Y);
		int64 D = sqr(point[3].X - point[0].X) + sqr(point[3].Y - point[0].Y);
		if( A != C || B != D )
			continue;
	int64 P = (point[0].Y - point[1].Y) * (point[1].Y - point[2].Y) + (point[0].X - point[1].X) * (point[1].X - point[2].X);
	int64 Q = (point[1].Y - point[2].Y) * (point[2].Y - point[3].Y) + (point[1].X - point[2].X) * (point[2].X - point[3].X);
	int64 R = (point[2].Y - point[3].Y) * (point[3].Y - point[0].Y) + (point[2].X - point[3].X) * (point[3].X - point[0].X);
	int64 S = (point[3].Y - point[0].Y) * (point[0].Y - point[1].Y) + (point[3].X - point[0].X) * (point[0].X - point[1].X);
	int64 U = (point[0].Y - point[1].Y) * (point[2].X - point[3].X);
	int64 V = (point[0].X - point[1].X) * (point[2].Y - point[3].Y);
	int64 W = (point[1].Y - point[2].Y) * (point[0].X - point[3].X);
	int64 X = (point[1].X - point[2].X) * (point[0].Y - point[3].Y);
		if( P != 0 && Q != 0 && R != 0 && S != 0 && U == V && W == X )
			return true;
	}while( next_permutation(point, point + 4, comp) );
	
	return false;
}

bool isTrapezium(Point point[]){
	do{
		int64 P = (point[0].Y - point[1].Y) * (point[2].X - point[3].X);
		int64 Q = (point[0].X - point[1].X) * (point[2].Y - point[3].Y);
		int64 R = (point[1].Y - point[2].Y) * (point[0].X - point[3].X);
		int64 S = (point[1].X - point[2].X) * (point[0].Y - point[3].Y);
		if( (P == Q) || (R == S) )
			return true;
	}while( next_permutation(point, point + 4, comp) );
	
	return false;
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int T;
	cin >> T;	
	for(int t = 1; t <= T; t++){
		Point point[4];
		int i;
		FOI(i, 0, 3){
			cin >> point[i].X >> point[i].Y;
			point[i].I = i;
		}
		cout << "Case " << t << ": ";
		if( isSquare(point) )
			cout << "Square\n";
		else if( isRectangle(point) )
			cout << "Rectangle\n";
		else if( isRhombus(point) )
			cout << "Rhombus\n";
		else if( isParallelogram(point) )
			cout << "Parallelogram\n";
		else if( isTrapezium(point) )
			cout << "Trapezium\n";
		else
			cout << "Ordinary Quadrilateral\n";
		
	}
	return 0;
}
