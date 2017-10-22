#include <bits/stdc++.h>

using namespace std;

int main()
{
	priority_queue<int, vector<int>, greater<int>> ugly;
	ugly.push(2);
	ugly.push(3);
	ugly.push(5);
	int cnt = 1, curr = 1;
	while (cnt < 1500)
	{
		int tmp = 0;
		while (tmp <= curr)
		{
			tmp = ugly.top();
			ugly.pop();
		}
		ugly.push(2 * tmp);
		ugly.push(3 * tmp);
		ugly.push(5 * tmp);
		curr = tmp;
		cnt++;
	}
	printf("The 1500'th ugly number is %d.\n", curr);
	return 0;
}
