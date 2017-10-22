#include <bits/stdc++.h>

using namespace std;

const int MAX = 16;
const int MAXNODES = 256 + 64 + 16 + 4 + 1;
struct node
{
	int val;
	int kids[4];
	int minkid;
};
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void processTree(node t[], node map[], int i, int size)
{
	if (4 * i + 1 < size)
	{
		processTree(t, map, 4 * i + 1, size);
		processTree(t, map, 4 * i + 2, size);
		processTree(t, map, 4 * i + 3, size);
		processTree(t, map, 4 * i + 4, size);
		int m[4] = {0, 1, 2, 3};
		if (t[t[i].kids[m[0]]].minkid > t[t[i].kids[m[1]]].minkid)
		{
			swap(m[0], m[1]);
		}
		if (t[t[i].kids[m[1]]].minkid > t[t[i].kids[m[2]]].minkid)
		{
			swap(m[1], m[2]);
		}
		if (t[t[i].kids[m[2]]].minkid > t[t[i].kids[m[3]]].minkid)
		{
			swap(m[2], m[3]);
		}
		if (t[t[i].kids[m[0]]].minkid > t[t[i].kids[m[1]]].minkid)
		{
			swap(m[0], m[1]);
		}
		if (t[t[i].kids[m[1]]].minkid > t[t[i].kids[m[2]]].minkid)
		{
			swap(m[1], m[2]);
		}
		if (t[t[i].kids[m[0]]].minkid > t[t[i].kids[m[1]]].minkid)
		{
			swap(m[0], m[1]);
		}
		for (int j = 0; j < 4; j++)
		{
			map[i].kids[j] = m[j];
		}
		t[i].minkid = t[t[i].kids[m[0]]].minkid;
	}
	else
	{
		map[i].kids[0] = -1;
		map[i].kids[1] = -1;
		map[i].kids[2] = -1;
		map[i].kids[3] = -1;
		t[i].minkid = t[i].val;
	}
}
void buildImage(node image[], node mapping[], int grid[][MAX], int size,
								int i, int row, int col)
{
	if (image[i].val != -1)
	{
		for (int r = row; r < row + size; r++)
			for (int c = col; c < col + size; c++)
			{
				grid[r][c] = image[i].val;
			}
	}
	else
	{
		size /= 2;
		buildImage(image, mapping, grid, size, 4 * i + mapping[i].kids[0] + 1,
							 row, col);
		buildImage(image, mapping, grid, size, 4 * i + mapping[i].kids[1] + 1,
							 row, col + size);
		buildImage(image, mapping, grid, size, 4 * i + mapping[i].kids[2] + 1,
							 row + size, col);
		buildImage(image, mapping, grid, size, 4 * i + mapping[i].kids[3] + 1,
							 row + size, col + size);
	}
}
int main()
{
	int cases, size, nkids;
	node tree[MAXNODES], image[MAXNODES];
	int grid[MAX][MAX];
	cin >> cases;
	for (int c = 1; c <= cases; c++)
	{
		int s;
		cin >> s;
		size = 0;
		for (int i = 1; i <= s; i *= 2)
		{
			size += i * i;
		}
		for (int i = 0; i < size; i++)
		{
			tree[i].val = image[i].val = -1;
		}
		cin >> nkids;
		for (int i = 0; i < nkids; i++)
		{
			int k, intensity;
			cin >> k >> intensity;
			tree[k].val = intensity;
		}
		for (int k = 0; k < size; k++)
		{
			if (tree[k].val == -1)
			{
				tree[k].kids[0] = 4 * k + 1;
				tree[k].kids[1] = 4 * k + 2;
				tree[k].kids[2] = 4 * k + 3;
				tree[k].kids[3] = 4 * k + 4;
			}
			else
			{
				tree[k].kids[0] = -1;
				tree[k].kids[1] = -1;
				tree[k].kids[2] = -1;
				tree[k].kids[3] = -1;
			}
		}
		cin >> nkids;
		for (int i = 0; i < nkids; i++)
		{
			int k, intensity;
			cin >> k >> intensity;
			image[k].val = intensity;
		}
		for (int k = 0; k < size; k++)
		{
			if (image[k].val == -1)
			{
				image[k].kids[0] = 4 * k + 1;
				image[k].kids[1] = 4 * k + 2;
				image[k].kids[2] = 4 * k + 3;
				image[k].kids[3] = 4 * k + 4;
			}
			else
			{
				image[k].kids[0] = -1;
				image[k].kids[1] = -1;
				image[k].kids[2] = -1;
				image[k].kids[3] = -1;
			}
		}
		node mapping[MAXNODES];
		processTree(tree, mapping, 0, size);
		buildImage(image, mapping, grid, s, 0, 0, 0);
		cout << "Case " << c << endl
				 << endl;
		for (int r = 0; r < s; r++)
		{
			for (int c = 0; c < s; c++)
			{
				cout << setw(4) << grid[r][c];
			}
			cout << endl;
		}
		if (c < cases)
		{
			cout << endl;
		}
	}
}
