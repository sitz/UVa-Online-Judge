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

#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)

bool isInc(int arr[]){
	int i;
	FOI(i, 0, 8)
		if( arr[i] > arr[i+1] )
			return false;
	return true;
}

bool isDec(int arr[]){
	int i;
	FOI(i, 0, 8)
		if( arr[i] < arr[i+1] )
			return false;
	return true;
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int T, i, arr[10];
	cin >> T;
	cout << "Lumberjacks:\n";
	while( T-- ){
		FOI(i, 0, 9) cin >> arr[i];
		if( isInc(arr) || isDec(arr) )
			cout << "Ordered\n";
		else
			cout << "Unordered\n";
	}
	return 0;
}
