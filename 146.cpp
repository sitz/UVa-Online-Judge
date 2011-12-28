#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {
	while (true) {
		char ch[51];
		scanf("%s", ch);
		int L = strlen(ch);
		
		if (strcmp(ch, "#") == 0)
			return 0;
		
		if (next_permutation(ch, ch + L))
			printf("%s\n", ch);
		else
			printf("No Successor\n");
   }
   return 0;
}
