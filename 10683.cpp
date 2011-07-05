#include <cstdio>
using namespace std;

int main(){
	char str[10];
	while( scanf("%s", str) != EOF ){
		int sec  = ( (str[0] - '0') * 10 + (str[1] - '0') ) * 60 * 60 * 100;
			sec += ( (str[2] - '0') * 10 + (str[3] - '0') ) * 60 * 100;
			sec += ( (str[4] - '0') * 10 + (str[5] - '0') ) * 100;
			sec += ( (str[6] - '0') * 10 + (str[7] - '0') );
			
			printf("%07d\n", (sec * 125) / 108);
	}
	return 0;
}
