#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define N 10001
#define TREE 2002

int is_exist_x[10001];
int is_exist_y[10001];
int x[TREE];
int y[TREE];
int inx[TREE];
int iny[TREE];
int mapping[TREE];
int list_up[TREE];
int list_down[TREE];
vector<int> y_at_x[TREE]; // [(x,y)]
int t_list_up[TREE], t_list_down[TREE];
int t_mapping[TREE];

int solve(int r, int c, int maxheight)
{
	int ret = 0;
	for (int i = c - 1; i > 0; i--)
	{
		int c_width = x[i] - x[0];
		int cut = i;
		c_width = x[cut] - x[0];
		rep(j, y_at_x[cut].size())
		{
			int now = y_at_x[cut][j];
			mapping[now]--;
			if (mapping[now] == 0)
			{
				list_up[list_down[now]] = list_up[now];
				list_down[list_up[now]] = list_down[now];
				maxheight = max(maxheight, y[list_up[now]] - y[list_down[now]]);
				ret = max(ret, maxheight * c_width);
			}
		}
		int tmp_height = maxheight;
		ret = max(ret, c_width * tmp_height);
		// copy list
		rep(j, r)
		{
			t_mapping[j] = mapping[j];
			t_list_up[j] = list_up[j];
			t_list_down[j] = list_down[j];
		}
		// check all value
		REP(j, 0, i)
		{
			c_width = x[i] - x[j];
			rep(k, y_at_x[j].size())
			{
				int now = y_at_x[j][k];
				t_mapping[now]--;
				if (t_mapping[now] == 0)
				{
					t_list_up[t_list_down[now]] = t_list_up[now];
					t_list_down[t_list_up[now]] = t_list_down[now];
					tmp_height = max(tmp_height, y[t_list_up[now]] - y[t_list_down[now]]);
					ret = max(ret, tmp_height * c_width);
				}
			}
		}
	}
	return ret;
}
inline void make_list(int r)
{
	list_up[0] = 1;
	list_down[0] = -1;
	REP(i, 1, r - 1)
	{
		list_up[i] = i + 1;
		list_down[i] = i - 1;
	}
	list_up[r - 1] = -1;
	list_down[r - 1] = r - 2;
	return;
}
inline int calc_maxheight(int r)
{
	int maxheight = 0;
	rep(i, r - 1) maxheight = max(maxheight, y[i + 1] - y[i]);
	return maxheight;
}
void put_tree(int k, int sx, int sy, int dx, int dy, int height, int width, int &p)
{
	rep(i, k)
	{
		if (sx != 0 && sy != 0 && sx != width && sy != height)
		{
			is_exist_x[sx] = true;
			is_exist_y[sy]++;
			inx[p] = sx;
			iny[p++] = sy;
		}
		sx += dx;
		sy += dy;
	}
}
void construct_data(int &r, int &c, int &p, int height, int width)
{
	r = 0;
	c = 0;
	x[c++] = 0;
	y[r++] = 0;
	rep(i, 10001)// is_exist changes to point index
	{
		if (is_exist_x[i] == true)
		{
			is_exist_x[i] = c;
			x[c++] = i;
		}
		if (is_exist_y[i] > 0)
		{
			mapping[r] = is_exist_y[i];
			is_exist_y[i] = r;
			y[r++] = i;
		}
	}
	y[r++] = height;
	x[c++] = width;
	rep(i, c) y_at_x[i].clear();
	rep(i, p)
	{
		y_at_x[is_exist_x[inx[i]]].push_back(is_exist_y[iny[i]]);
		assert(is_exist_y[iny[i]] != 0);
	}
	rep(i, c) sort(y_at_x[i].begin(), y_at_x[i].end());
}

int main()
{
	int width, height;
	int te;
	cin >> te;
	while (te--)
	{
		rep(i, 10001) is_exist_x[i] = is_exist_y[i] = 0;
		cin >> width >> height;
		int p = 0;
		int r = 0, c = 0;
		while (true)
		{
			int k, x, y, dx, dy;
			cin >> k;
			if (k == 0)
			{
				break;
			}
			cin >> x >> y;
			if (k > 1)
			{
				cin >> dx >> dy;
			}
			put_tree(k, x, y, dx, dy, height, width, p);
		}
		construct_data(r, c, p, height, width);
		make_list(r);
		int maxheight = calc_maxheight(r);
		cout << solve(r, c, maxheight) << endl;
	}
	return 0;
}
