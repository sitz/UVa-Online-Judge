#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = 0; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define N 26
#define COLOR 10
#define ITEM 10

#define NOT_DECIDE -1

class Info
{
public:
	int x, y;
	vector<int> data;
};

bool same_color[ITEM][N][N];
int decide[N][ITEM];
bool possible[N][ITEM][COLOR];

void reset(int n, int item, int color)
{
	rep(i, item)
	{
		rep(j, n)
		{
			rep(k, n)
			{
				same_color[i][j][k] = false;
			}
			same_color[i][j][j] = true;
		}
	}
	rep(i, n)
	{
		rep(j, item) decide[i][j] = NOT_DECIDE;
	}
	rep(i, n)
	{
		rep(j, item)
		{
			rep(k, color)
			{
				possible[i][j][k] = true;
			}
		}
	}
}

void tc(int n, int item)
{
	rep(l, item)
			rep(k, n)
					rep(i, n)
							rep(j, n) same_color[l][i][j] = (same_color[l][i][j] | (same_color[l][i][k] & same_color[l][k][j]));
}

bool item_x_is_y(Info &in)
{
	int item = in.x, color = in.y;
	rep(i, in.data.size())
	{
		int now = in.data[i];
		if (decide[now][item] == NOT_DECIDE || decide[now][item] == color)
		{
			decide[now][item] = color;
		}
		else
		{
			return false;
		}
	}
	return true;
}

bool item_x_is_not_y(Info &in)
{
	int item = in.x, color = in.y;
	rep(i, in.data.size())
	{
		int now = in.data[i];
		if (decide[now][item] == NOT_DECIDE || decide[now][item] != color)
		{
			possible[now][item][color] = false;
		}
		else
		{
			return false;
		}
	}
	return true;
}

bool is_same_color(int n, int me, int item, int numcolor)
{
	//decide color check
	int color = decide[me][item];
	rep(i, n)
	{
		if (same_color[item][me][i] && decide[i][item] != NOT_DECIDE)
		{
			if (color == NOT_DECIDE)
			{
				color = decide[i][item];
			}
			else if (color != decide[i][item])
			{
				return false;//two colors
			}
		}
	}
	int tmp = color, cnt = color == NOT_DECIDE ? 0 : 1;
	if (color == NOT_DECIDE)
	{
		//possible color check
		bool can[numcolor];
		rep(j, numcolor)
		{
			can[j] = true;
			rep(i, n)
			{
				if (same_color[item][me][i])
				{
					can[j] &= possible[i][item][j];
				}
			}
			if (can[j])
			{
				tmp = j, cnt++;
			}
		}
	}
	//if possible color is one then decide.
	if (cnt == 1)
	{
		rep(i, n)
		{
			if (same_color[item][me][i] == true)
			{
				decide[i][item] = tmp;
			}
		}
	}
	else if (cnt == 0)
	{
		return false;//all person doesn't have same color
	}
	return true;
}

void solve(int n, int item, int color, vector<Info> &xisy, vector<Info> &xisny,
					 bool *is_here)
{
	tc(n, item);
	rep(i, xisy.size())
	{
		if (item_x_is_y(xisy[i]) == false)
		{
			puts("Contradiction");
			return;
		}
	}
	//cout << "item x is y end" << endl;
	rep(i, xisny.size())
	{
		if (item_x_is_not_y(xisny[i]) == false)
		{
			puts("Contradiction");
			return;
		}
	}
	//cout << "item x is not y end " << endl;
	/*
	rep(i,n){
	  if ( is_here[i]==true){
	    rep(j,item){
	cout << "person " << i << " item " << j <<" ";
	rep(k,color)
	  if( possible[i][j][k])cout << k;
	cout << endl;
	    }
	  }
	}
	*/
	rep(i, n)
	{
		rep(j, item)
		{
			if (is_same_color(n, i, j, color) == false)
			{
				puts("Contradiction");
				return;
			}
		}
	}
	//cout << "same color item x is end "<<endl;
	rep(i, n)
	{
		if (is_here[i] == true)
		{
			cout << (char)(i + 'A');
			rep(j, item)
			{
				if (decide[i][j] == NOT_DECIDE)
				{
					cout << " ?";
				}
				else
				{
					cout << ' ' << decide[i][j];
				}
			}
			cout << endl;
		}
	}
}

void get_input(string &tmp, bool *is_here, vector<Info> *a)
{
	int index;
	Info in;
	stringstream sin(tmp);
	string dummy;
	if (tmp[0] == 'S')
	{
		sin >> dummy >> dummy >> dummy >> dummy >> in.x >> dummy;
		index = 0;
	}
	else if (tmp[0] == 'C')
	{
		sin >> dummy >> in.y >> dummy >> dummy >> in.x >> dummy;
		index = 1;
	}
	else if (tmp[0] == 'N')
	{
		sin >> dummy >> dummy >> in.y >> dummy >> dummy >> in.x >> dummy;
		index = 2;
	}
	char member;
	while (sin >> member)
	{
		in.data.push_back(member - 'A');
		is_here[member - 'A'] = true;
	}
	a[index].push_back(in);
}

main()
{
	int te, tc = 0;
	cin >> te;
	while (te--)
	{
		if (tc)
		{
			puts("");
		}
		tc = 1;
		int n, item, color, query;
		bool is_here[26] = {false};
		cin >> n >> item >> color >> query;
		reset(n, item, color);
		string tmp;
		getline(cin, tmp);
		vector<Info> in[3];
		rep(i, query)
		{
			getline(cin, tmp);
			get_input(tmp, is_here, in);
		}
		rep(i, in[0].size())
		{
			int now = in[0][i].x;
			rep(j, in[0][i].data.size())
			{
				rep(k, in[0][i].data.size())
				{
					same_color[now][in[0][i].data[j]][in[0][i].data[k]] = true;
				}
			}
		}
		solve(26, item, color, in[1], in[2], is_here);
	}
	return false;
}
