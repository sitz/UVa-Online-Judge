#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)
#define MAX	25

int main(){
	map<string, int> Map;
	string alpha[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", 					  "w", "x", "y", "z" };
	
	int ID = 1;
	int a, b, c, d, e;
	
	FOI(a, 0, MAX)
		Map[""+alpha[a]] = ID++;

	FOI(a, 0, MAX)
		FOI(b, a+1, MAX)
			Map[""+alpha[a]+alpha[b]] = ID++;
		
	FOI(a, 0, MAX)
		FOI(b, a+1, MAX)
			FOI(c, b+1, MAX)
				Map[""+alpha[a]+alpha[b]+alpha[c]] = ID++;

	FOI(a, 0, MAX)
		FOI(b, a+1, MAX)
			FOI(c, b+1, MAX)
				FOI(d, c+1, MAX)
					Map[""+alpha[a]+alpha[b]+alpha[c]+alpha[d]] = ID++;

	FOI(a, 0, MAX)
		FOI(b, a+1, MAX)
			FOI(c, b+1, MAX)
				FOI(d, c+1, MAX)
					FOI(e, d+1, MAX)
						Map[""+alpha[a]+alpha[b]+alpha[c]+alpha[d]+alpha[e]] = ID++;

	string S;
	while( cin >> S )
		cout << Map[S] << endl;
	return 0;
}
