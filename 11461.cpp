#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b;
	while (scanf("%d %d", &a, &b) == 2)
	{
		if (!a)
		{
			break;
		}
		int counter = 0;
		int i = ceil(sqrt(a));
		while (i * i <= b)
		{
			counter++, i++;
		}
		printf("%d\n", counter);
	}
	return 0;
}
