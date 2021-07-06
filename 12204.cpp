#include <bits/stdc++.h>

using namespace std;

// O(linear in the size of the output)

const int maxn = 13;

int perm[1 << maxn], inv[1 << maxn];				 // current permutation, inverse permutation
char switched[2 * maxn - 1][1 << (maxn - 1)],// state of switches
		path[1 << maxn];												 // 0 for left path, 1 for right

void dfs(int v, int r)
{
	path[v] = r;
	if (path[v ^ 1] < 0)
	{
		dfs(v ^ 1, r ^ 1);
	}
	v = perm[inv[v] ^ 1];
	if (path[v] < 0)
	{
		dfs(v, r ^ 1);
	}
}

int perfectshuffle(int i, int n)
{
	return ((i & 1) << (n - 1)) | (i >> 1);
}

/* Solve the routing problem with n nodes, where src[i] is matched to dest[i]
 * and switch submatrix starting at (ypos, xpos), and store the state of the switches. */
void route_all(int n, int ypos, int xpos, const vector<int> &src, const vector<int> &dest)
{
	if (n == 1)
	{
		switched[ypos][xpos] = src[0] != dest[0];
		return;
	}
	int xlen = 1 << n, ylen = 2 * n - 1;
	/* Write dest as a permutation of src and compute the inverse.
	 * From now on we pretend the values of src are 0, 1, .., xlen -1. */
	for (int i = 0; i < xlen; ++i)
	{
		inv[src[i]] = i;
	}
	for (int i = 0; i < xlen; ++i)
	{
		perm[i] = inv[dest[i]];
	}
	for (int i = 0; i < xlen; ++i)
	{
		inv[perm[i]] = i;
	}
	/* Find a bicoloring (to select which messages will go through the left half of the network).
	 * The order is chosen so that low-numbered switches are turned off if possible. */
	memset(path, -1, sizeof(path));
	for (int i = 0; i < xlen; ++i)
		if (path[i] < 0)
		{
			dfs(i, 0);
		}
	// Compute new src/dest pairs (1 is the upper part, 2 the lower part).
	vector<int> left1, right1;
	for (int i = 0; i < xlen; i += 2)// upper part
	{
		switched[ypos][xpos + i / 2] = path[i];
		for (int j = 0; j < 2; ++j)
		{
			int x = perfectshuffle((i | j) ^ path[i], n);
			if (x < xlen / 2)
			{
				left1.push_back(i | j);
			}
			else
			{
				right1.push_back(i | j);
			}
		}
	}
	vector<int> left2(xlen / 2), right2(xlen / 2);
	for (int i = 0; i < xlen; i += 2)// lower part
	{
		int s = switched[ypos + ylen - 1][xpos + i / 2] = path[perm[i]];
		for (int j = 0; j < 2; ++j)
		{
			int x = perfectshuffle((i | j) ^ s, n);
			if (x < xlen / 2)
			{
				left2[x] = perm[i | j];
			}
			else
			{
				right2[x - xlen / 2] = perm[i | j];
			}
		}
	}
	// Recurse on the left and right parts
	route_all(n - 1, ypos + 1, xpos, left1, left2);
	route_all(n - 1, ypos + 1, xpos + xlen / 4, right1, right2);
}

int main()
{
	int n;
	bool first = true;
	while (scanf("%i", &n) == 1, n)
	{
		int xlen = 1 << n, ylen = 2 * n - 1;
		vector<int> dest(xlen), src(xlen);
		for (int i = 0; i < xlen; ++i)
		{
			src[i] = i;
		}
		for (int i = 0; i < xlen; ++i)
		{
			scanf("%i", &dest[i]);
		}
		route_all(n, 0, 0, src, dest);
		if (!first)
		{
			puts("");
		}
		else
		{
			first = false;
		}
		for (int y = 0; y < ylen; ++y)
		{
			for (int x = 0; x < xlen / 2; ++x)
			{
				putchar('0' + switched[y][x]);
			}
			puts("");
		}
	}
	return 0;
}
