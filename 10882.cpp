#include <bits/stdc++.h>

using namespace std;

/*
 * AUTHOR : benbendog
 * DATE   : 2011/3/13
 * PROBLEM: 3 people having 100 numbers with label(0-100) on it
 *          given intersection of A^B, A^C, B^C of the same label
 *          find the range of A^B^C
 * SOLUTION: the max is min(A^B,A^C,B^C)
             the min is A^B + A^C + B^C - 2x <= 100
             x is min
 *           split 100 numbers into 4 parts
              Xi Yi Zi Ii, i = (1~3)
              X1 and X2 is A^B - A^B^C, Y1 and Y3 is A^C - A^B^C , Z2 and Z3 is
              B^C - A^B^C
             since each people has exactly 100 numbers
             so Xi + Yi+ Zi can not  > 100,  Ii = A^B^C
             => A^B + A^C + B^C - 2x <= 100
 */
int main()
{
	int cas;
	int cnt = 1;
	cin >> cas;
	while (cas--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int lb, ub;
		lb = (a + b + c + 1 - 100) >> 1;
		if (lb < 0)
		{
			lb = 0;
		}
		ub = min(a, b);
		ub = min(ub, c);
		cout << "Case #" << cnt++ << ": ";
		if (lb > ub)
		{
			cout << "The records are faulty." << endl;
		}
		else
		{
			cout << "Between " << lb << " and " << ub << " times." << endl;
		}
	}
	return 0;
}
