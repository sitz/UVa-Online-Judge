#include <bits/stdc++.h>

using namespace std;

#define MAX_TOWN 35

typedef long long unsigned LLUINT;

bool finish;
int minimum;
vector<LLUINT> edge;
LLUINT target_tag, origin_tag;

void check(int flag[], int position)
{
	int index = 0;
	LLUINT new_tag = origin_tag, old_tag = origin_tag;
	for (int i = 0; i < edge.size(); i++)
	{
		if ((index < position) && (flag[index] == i))
		{
			new_tag |= edge[i];
			if (new_tag > old_tag)
			{
				old_tag = new_tag;
			}
			else
			{
				return;
			}
			index++;
		}
	}
	if (new_tag == target_tag)
	{
		minimum = index;
		finish = true;
	}
}
void generate(int flag[], int position, int positions)
{
	if (finish)
	{
		return;
	}
	if (position < positions)
	{
		if (position == 0)
		{
			for (int i = 0; i < edge.size(); i++)
			{
				flag[position] = i;
				generate(flag, position + 1, positions);
			}
		}
		else
		{
			for (int i = flag[position - 1] + 1; i < edge.size(); i++)
			{
				flag[position] = i;
				generate(flag, position + 1, positions);
			}
		}
	}
	else
	{
		check(flag, position);
	}
}
void enumerating_subset()
{
	for (int i = 1; i <= edge.size(); i++)
	{
		int *flag = new int[edge.size()];
		generate(flag, 0, i);
		delete[] flag;
		if (finish)
		{
			return;
		}
	}
}
bool cmp(LLUINT x, LLUINT y)
{
	return x > y;
}
int mdsn(vector<vector<int>> &vertex)
{
	int base = 0;
	origin_tag = 0;
	target_tag = 0;
	vector<bool> dirty(vertex.size());
	fill(dirty.begin(), dirty.end(), false);
	for (int i = 0; i < vertex.size(); i++)
	{
		if (vertex[i].size() == 0)
		{
			base++;
			origin_tag |= ((LLUINT)1 << i);
		}
		if (vertex[i].size() == 1 && dirty[i] == false)
		{
			dirty[i] = true;
			if (dirty[vertex[i][0] - 1] == false)
			{
				base++;
				dirty[vertex[i][0] - 1] = true;
			}
		}
		target_tag |= ((LLUINT)1 << i);
	}
	edge.clear();
	for (int i = 0; i < vertex.size(); i++)
	{
		if (dirty[i] == true)
		{
			origin_tag |= ((LLUINT)1 << i);
			for (int j = 0; j < vertex[i].size(); j++)
			{
				origin_tag |= ((LLUINT)1 << (vertex[i][j] - 1));
			}
		}
		if (dirty[i] == false && vertex[i].size() > 0)
		{
			LLUINT t = ((LLUINT)1 << i);
			for (int j = 0; j < vertex[i].size(); j++)
			{
				t |= ((LLUINT)1 << (vertex[i][j] - 1));
			}
			edge.push_back(t);
		}
	}
	sort(edge.begin(), edge.end(), cmp);
	minimum = 0;
	finish = false;
	enumerating_subset();
	return (base + minimum);
}
int servicing_stations(vector<vector<int>> &vertex)
{
	int total = 0;
	while (vertex.size() > 0)
	{
		vector<vector<int>> open;
		set<int> close;
		int size = 0;
		open.push_back(vertex[0]);
		close.insert(vertex[0][0]);
		vertex.erase(vertex.begin());
		while (open.size() > size)
		{
			int origin = size;
			int current = open.size() - 1;
			size = open.size();
			for (int i = origin; i <= current; i++)
			{
				for (int j = 1; j < open[i].size(); j++)
				{
					if (close.find(open[i][j]) == close.end())
					{
						close.insert(open[i][j]);
						for (int m = 0; m < vertex.size(); m++)
						{
							if (vertex[m][0] == open[i][j])
							{
								open.push_back(vertex[m]);
								vertex.erase(vertex.begin() + m);
								break;
							}
						}
					}
				}
			}
		}
		vector<vector<int>> tmp;
		for (int c = 1; c <= MAX_TOWN; c++)
			if (close.find(c) != close.end())
			{
				for (int i = 0; i < open.size(); i++)
					if (open[i][0] == c)
					{
						tmp.push_back(open[i]);
					}
			}
		for (int i = 0; i < tmp.size(); i++)
		{
			int current = tmp[i][0];
			for (int m = 0; m < tmp.size(); m++)
				for (int n = 1; n < tmp[m].size(); n++)
					if (tmp[m][n] == current)
					{
						tmp[m][n] = (i + 1);
					}
		}
		for (int i = 0; i < tmp.size(); i++)
		{
			tmp[i].erase(tmp[i].begin());
		}
		total += mdsn(tmp);
	}
	return total;
}
int main(int ac, char *av[])
{
	int n;
	int m;
	int x, y;
	vector<vector<int>> vertex;
	while (cin >> n >> m, n && m)
	{
		vertex.clear();
		vertex.resize(n);
		for (int i = 0; i < n; i++)
		{
			vertex[i].push_back((i + 1));
		}
		for (int i = 0; i < m; i++)
		{
			cin >> x >> y;
			if (x != y)
			{
				vertex[x - 1].push_back(y);
				vertex[y - 1].push_back(x);
			}
		}
		cout << servicing_stations(vertex) << endl;
	}
	return 0;
}
