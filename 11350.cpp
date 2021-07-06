#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int N;
const int MAXLEN = 91;
char brocot[MAXLEN];
ll left_num, left_den, right_num, right_den, x_num, x_den;
int main()
{
	scanf("%d", &N);
	while (N--)
	{
		scanf("%s", brocot);
		// base case
		if (brocot[0] == 'L')
		{
			left_num = 0;
			left_den = 1;
			right_num = 1;
			right_den = 1;
		}
		else
		{
			left_num = 1;
			left_den = 1;
			right_num = 1;
			right_den = 0;
		}
		x_num = left_num + right_num;
		x_den = left_den + right_den;
		// recursive case
		for (int j = 1; brocot[j] != '\0'; ++j)
		{
			if (brocot[j] == 'L')
			{
				right_num = x_num;
				right_den = x_den;
			}
			else
			{
				left_num = x_num;
				left_den = x_den;
			}
			x_num = left_num + right_num;
			x_den = left_den + right_den;
		}
		printf("%lld/%lld\n", x_num, x_den);
	}
	return 0;
}
