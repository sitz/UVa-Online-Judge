#include <bits/stdc++.h>

using namespace std;

struct Rect
{
	int x1, y1, x2, y2;

	Rect(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) : x1(x1), y1(y1), x2(x2), y2(y2) {}

	friend istream &operator>>(istream &in, Rect &r)
	{
		return in >> r.x1 >> r.y1 >> r.x2 >> r.y2;
	}

	friend bool intersect(const Rect &r1, const Rect &r2)
	{
		if (r1.x1 > r2.x2 || r2.x1 > r1.x2)
		{
			return false;
		}
		if (r1.y1 > r2.y2 || r2.y1 > r1.y2)
		{
			return false;
		}
		return true;
	}
};

int N;
Rect rect[100];
bool visit[100];
vector<Rect> R;

void DFS(int now)
{
	if (visit[now])
	{
		return;
	}
	visit[now] = true;
	R.push_back(rect[now]);
	for (int i = 0; i < N; ++i)
		if (!visit[i])
			if (intersect(rect[now], rect[i]))
			{
				DFS(i);
			}
}

int discrete()
{
	int i, j, k;
	vector<int> X, Y;
	for (i = 0; i < R.size(); ++i)
	{
		X.push_back(R[i].x1);
		X.push_back(R[i].x2);
	}
	for (i = 0; i < R.size(); ++i)
	{
		Y.push_back(R[i].y1);
		Y.push_back(R[i].y2);
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	int ans = 0;
	for (i = 0; i < X.size() - 1; ++i)
		for (j = 0; j < Y.size() - 1; ++j)
			for (k = 0; k < R.size(); ++k)
				if (R[k].x1 <= X[i] && R[k].x2 >= X[i + 1] && R[k].y1 <= Y[j] && R[k].y2 >= Y[j + 1])
				{
					ans += (X[i + 1] - X[i]) * (Y[j + 1] - Y[j]);
					break;
				}
	return ans;
}

int main()
{
	int cases;
	cin >> cases;
	while (cases--)
	{
		int i;
		for (i = 0; i < 100; ++i)
		{
			visit[i] = false;
		}
		R.clear();
		cin >> N;
		for (i = 0; i < N; ++i)
		{
			cin >> rect[i];
		}
		DFS(0);
		cout << discrete() << endl;
		if (cases)
		{
			cout << endl;
		}
	}
	return 0;
}
