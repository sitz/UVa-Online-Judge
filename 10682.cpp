#include <bits/stdc++.h>

using namespace std;

class Coord
{
public:
	int i, step, path;
	Coord() {}
	Coord(int a, int b, int c) : i(a), step(b), path(c) {}
};

template <class T>
class Queue_
{
public:
	int front, rear;
	T space[5500];
	Queue_()
	{
		front = 0;
		rear = 0;
	}
	void init()
	{
		front = 0;
		rear = 0;
	}
	void add(T element)
	{
		if (!full())
		{
			space[++rear] = element;
		}
		else
		{
			printf("FULL\n");
		}
	}
	T del()
	{
		if (!empty())
		{
			return space[++front];
		}
		else
		{
			return T();
		}
	}
	bool empty()
	{
		return front == rear;
	}
	bool full()
	{
		return rear + 1 == front;
	}
};

Queue_<Coord> queue_;
string name[1000];
int map_[1000][1000];

int find_pos(string, int &);
void find_path(int);
int BFS(int, int, int &);

int main()
{
	int cs = 0, m, n;
	while (scanf("%d", &m) == 1)
	{
		if (cs++)
		{
			printf("\n");
		}
		int p, q, i;
		for (p = 0; p < 1000; p++)
		{
			for (q = 0; q < 1000; q++)
			{
				map_[p][q] = -1;
			}
		}
		queue_.init();
		n = 0;
		string sa, sb;
		int a, b, c;
		for (i = 0; i < m; i++)
		{
			cin >> sa >> sb >> c;
			a = find_pos(sa, n);
			b = find_pos(sb, n);
			map_[a][b] = c;
			map_[b][a] = c;
		}
		string sstart, send;
		cin >> sstart >> send;
		int start = find_pos(sstart, n), end = find_pos(send, n);
		int pos = BFS(start, end, n);
		if (pos == -1)
		{
			printf("No valid route.\n");
		}
		else
		{
			cout << sstart;
			find_path(pos);
			printf("\n");
		}
	}
	return 0;
}

int find_pos(string s, int &n)
{
	for (int i = 0; i < n; i++)
	{
		if (name[i] == s)
		{
			return i;
		}
	}
	name[n] = s;
	return n++;
}

void find_path(int pos)
{
	if (queue_.space[queue_.space[pos].path].i != queue_.space[pos].i)
	{
		find_path(queue_.space[pos].path);
		cout << " " << name[queue_.space[pos].i];
	}
}

int BFS(int start, int end, int &n)
{
	Coord pos(start, 0, 1);
	queue_.add(pos);
	while (!queue_.empty() && pos.i != end)
	{
		pos = queue_.del();
		for (int i = 0; i < n; i++)
		{
			if (i != queue_.space[pos.path].i && i != pos.i)
			{
				if (map_[pos.i][i] > 0)
				{
					if (map_[pos.i][i] >= pos.step)
					{
						queue_.add(Coord(i, map_[pos.i][i], queue_.front));
						if (i == end)
						{
							return queue_.rear;
						}
					}
				}
			}
		}
	}
	if (pos.i == end)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
