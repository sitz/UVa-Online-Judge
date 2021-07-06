#include <bits/stdc++.h>

using namespace std;

// give you a binary string of length <10 ^ 5
// define the grow operation to insert its xor value between two compartments
// queries the number of modals 0,1 in the interval after g <10 ^ 4 growth

// ideas
// the first query interval [a, b] can be [0, b] - [0, a-1] to calculate so the problem can be streamlined into a one-way growth
// then in a growth process 0 increase the number of the same neighbor 1 on the contrary
// so i can only calculate the same after each growth and the number of different can know the number of 0,1
// so list the possible relationships
// 00 -> 000 (with 0 will produce 2x with 0)
// 11 -> 101 (with 1 will produce 2x different)
// 10 -> 110 (different will produce 1x different 1x same 1)
// next, because his query range is not directly to the index but the growth path and start index

// growth path for the d, r form
// 1 1
//   | d
// 101
// 1 1
//  \ r
// 101

// so the rdd starting at 1 in 10010 would be
// 10010
// 1 0 0 1 0
//           \ r
// 1 1 0 0 0 1 1 1 0
//             | d
// 1 0 1 1 0 0 0 0 0 1 1 0 1 0 1 1 0
//             | d
// 110110110000000001101101110110110
//             ^

// d is the way in front of the maintenance can be
// however, the current need to end r and the next one can know what information
// so the need to maintain the end and the next value (end_val, nxt_val)
// in the d when nxt_val = end_val ^ nxt_val
// in the r end_val = end_val ^ nxt_val
// then remember to maintain the number of similarities and differences in the r when the relationship

const long long prime = 342307123;

bool dat[100010];
char str[100010], gf[10010], gt[10010];
int g, gpf, gpt;

tuple<long long, long long, bool> get_cnt(const char *path, int idx)
{
	long long diff = 0, zsame = 0, osame = 0, one = 0, zero = 0;
	bool end_val = dat[idx], nxt_val = dat[idx + 1];
	for (int i = 0; i <= idx; i++)
	{
		if (dat[i])
		{
			one++;
		}
		else
		{
			zero++;
		}
	}
	for (int i = 1; i <= idx; i++)
	{
		if (dat[i - 1] == dat[i] && !dat[i])
		{
			zsame++;
		}
		else if (dat[i - 1] == dat[i] && dat[i])
		{
			osame++;
		}
		else
		{
			diff++;
		}
	}
	for (int i = 0; i < g - 1; i++)
	{
		long long ndiff = diff + 2 * osame, nzsame = 2 * zsame, nosame = diff;
		zero += osame + zsame;
		one += diff;
		diff = ndiff % prime;
		zsame = nzsame % prime;
		osame = nosame % prime;
		if (path[i] == 'R')
		{
			end_val = end_val ^ nxt_val;
			if (end_val)
			{
				one++;
			}
			else
			{
				zero++;
			}
			if ((end_val ^ nxt_val) == end_val && end_val)
			{
				osame++;
			}
			else if ((end_val ^ nxt_val) == end_val && !end_val)
			{
				zsame++;
			}
			else
			{
				diff++;
			}
		}
		else
		{
			nxt_val = end_val ^ nxt_val;
		}
		one %= prime;
		zero %= prime;
	}
	zero %= prime;
	one %= prime;
	return make_tuple(zero, one, end_val);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		scanf("%s%d", str, &g);
		scanf("%d", &gpf);
		if (g > 1)
		{
			scanf("%s", gf);
		}
		scanf("%d", &gpt);
		if (g > 1)
		{
			scanf("%s", gt);
		}
		int len = strlen(str);
		for (int i = 0; i < len; i++)
		{
			dat[i] = str[i] == '1';
		}
		long long tone, tzero, tend_val, fone, fzero, fend_val;
		tie(fzero, fone, fend_val) = get_cnt(gf, gpf);
		tie(tzero, tone, tend_val) = get_cnt(gt, gpt);
		long long one = tone - fone, zero = tzero - fzero;
		if (fend_val)
		{
			one++;
		}
		else
		{
			zero++;
		}
		zero %= prime;
		one %= prime;
		if (zero < 0)
		{
			zero += prime;
		}
		if (one < 0)
		{
			one += prime;
		}
		printf("Case %d: %lld %lld\n", i, zero, one);
	}
	return 0;
}
