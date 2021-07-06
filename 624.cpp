#include <bits/stdc++.h>

using namespace std;

/**
 * Dynamic Programming, 0/1 Knapsack
 */

enum
{
	MAX_TRACK = 20,
	MAX_LEN = 10005
};

int c[MAX_LEN];
bool p[MAX_TRACK][MAX_LEN];

void solve_knapsack(int tape_len, int *track, int track_num)
{
	memset(c, 0, sizeof(c));
	memset(p, 0, sizeof(p));
	for (int i = track_num - 1; i >= 0; --i)// for all tracks
	{
		for (int j = tape_len; j >= track[i]; --j)// 1-d array: bug at j>track[i]
		{
			p[i][j] = (c[j - track[i]] + track[i] > c[j]);
			c[j] = max(c[j - track[i]] + track[i], c[j]);
		}
	}
}

void print_tracks(int tape_len, int *track, int track_num)
{
	int k = tape_len;
	for (int i = 0; i < track_num; ++i)
	{
		if (p[i][k])
		{
			printf("%d ", track[i]);
			k = k - track[i];
		}
	}
	printf("sum:%d\n", c[tape_len]);
}

int main()
{
	int tape_len;
	while (scanf("%d", &tape_len) == 1)
	{
		int track_num, track[MAX_TRACK];
		scanf("%d", &track_num);
		for (int i = 0; i < track_num; ++i)
		{
			scanf("%d", &track[i]);
		}
		solve_knapsack(tape_len, track, track_num);
		print_tracks(tape_len, track, track_num);
	}
	return 0;
}
