#include <bits/stdc++.h>

using namespace std;

/*   @JUDGE_ID:   2905EH   783   C++ "trivial"  */
//2002/8/6 a_q783.cpp <ACCEPTED>

int main()
{
	int d, v1, v2, t1, t2, tf;
	while (scanf("%d %d %d %d %d %d", &d, &v1, &v2, &t1, &t2, &tf) == 6)
	{
		int counter = 0;
		for (int s1 = 0; s1 <= tf; s1 += t1)
		{
			for (int s2 = 0; s2 <= tf; s2 += t2)
			{
				float aa = (float)s2 * v1 * v2 + (float)d * v1 - (float)s1 * v1 * v2;
				float bb = (float)v2 + v1;
				float x = aa / bb;
				if (0 <= x && x <= d && s1 + x / v1 <= tf)
				{
					counter++;
				}
			}
		}
		printf("%d\n", counter);
	}
}
/*@END_OF_SOURCE_CODE*/
