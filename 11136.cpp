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

typedef long long int64;
#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)

template <class ReverseIterator>
typename ReverseIterator::iterator_type make_forward(ReverseIterator rit){
    return --rit.base();
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	while (true){
		int64 N;
		scanf("%lld", &N);
		if (N == 0)
			break;
		multiset< int64 > mset;
		multiset< int64 >::iterator mit, rit;
		int64 T = 0;
		while (N--){
			int64 K;
			scanf("%lld", &K);
			while (K--){
				int64 I;
				scanf("%lld", &I);
				mset.insert(I);
			}
			mit = mset.begin();
			rit = make_forward( mset.rbegin() );	
			T += (*rit - *mit);
			mset.erase(mit);
			mset.erase(rit);
		}
		printf("%lld\n", T);
	}
	return 0;
}

