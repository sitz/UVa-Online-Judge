#include <bits/stdc++.h>

using namespace std;

#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL unsigned long long

int main()
{
	int p, c;
	int cases = 0;
	while (scanf("%d %d", &p, &c))
	{
		if (p == 0 && c == 0)
		{
			break;
		}
		list<int> l;
		p = min(c, p);
		for (int i = 1; i <= p; i++)
		{
			l.push_back(i);
		}
		char ch[10];
		printf("Case %d:\n", ++cases);
		for (int i = 0; i < c; i++)
		{
			scanf("%s", ch);
			if (ch[0] == 'N')
			{
				printf("%d\n", l.front());
				l.push_back(l.front());
				l.pop_front();
			}
			else
			{
				int num;
				scanf("%d", &num);
				l.remove(num);
				l.push_front(num);
			}
		}
	}
	return 0;
}
