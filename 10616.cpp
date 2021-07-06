#include <bits/stdc++.h>

using namespace std;

/**
 * DP Subset Sum
 */

using std::vector;

enum
{
	MAX_NUM = 200,
	MAX_DIVISOR = 20,
	MAX_M = 10
};
vector<int> n;// the number set
int D;				// the divisor
int M;				// the take number
int c[MAX_NUM][MAX_DIVISOR + 1][MAX_M];
bool v[MAX_NUM][MAX_DIVISOR + 1][MAX_M];// already in table or not

int mod(int s)
{
	if (s >= 0)
	{
		return s % D;
	}
	else
	{
		return D - (abs(s) % D);
	}
}

// Top-down DP
// (i,j,k) = (i+1, j+n[i], k-1)  or (i+1, j, k)
// i   : current index
// sum : current sum
// k   : numbers left to pick
int recur_subset(int i, int sum, int k)
{
	sum = mod(sum);
	if (v[i][sum][k])
		return c[i][sum][k];
	if (k == 0)
		return ((sum % D == 0) ? 1 : 0);
	if (i == n.size())
		return 0;
	int ans_count = 0;
	ans_count += recur_subset(i + 1, sum + n[i], k - 1);// take n[i] or
	ans_count += recur_subset(i + 1, sum, k);						// not take n[i]
	c[i][sum][k] = ans_count;
	v[i][sum][k] = true;
	return ans_count;
}

int solve()
{
	memset(c, 0, sizeof(c));
	memset(v, 0, sizeof(v));
	return recur_subset(0, 0, M);
}

int main()
{
	int set_no = 1;
	int num_num;	// the number of input numbers
	int num_query;// the number of queries
	while (scanf("%d%d", &num_num, &num_query) == 2)
	{
		if (num_num == 0 && num_query == 0)
			break;
		n.resize(num_num);
		for (int i = 0; i < num_num; ++i)
			scanf("%d", &n[i]);
		printf("SET %d:\n", set_no++);
		for (int i = 1; i <= num_query; ++i)
		{
			scanf("%d%d", &D, &M);
			printf("QUERY %d: %d\n", i, solve());
		}
	}
	return 0;
}
