#include <bits/stdc++.h>

using namespace std;

int N;

struct Rect
{
	double x, y, w, d, h;

	friend istream &operator>>(istream &in, Rect &r)
	{
		return in >> r.x >> r.y >> r.w >> r.d >> r.h;
	}
} R[100];

int seq[100];

bool comp1(const int &i, const int &j)
{
	return R[i].y < R[j].y || R[i].y == R[j].y && R[i].x < R[j].x;
}

vector<int> ans;

bool comp2(const int &i, const int &j)
{
	return R[i].x < R[j].x || R[i].x == R[j].x && R[i].y < R[j].y;
}

void discrete()
{
	int i, j, k;
	bool taken[100] = {0};
	ans.clear();
	vector<double> X, Y;
	for (i = 0; i < N; ++i)
	{
		X.push_back(R[i].x);
		X.push_back(R[i].x + R[i].w);
	}
	for (i = 0; i < N; ++i)
	{
		Y.push_back(R[i].h);
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());
	for (j = 0; j < Y.size(); ++j)
		for (i = 0; i < X.size() - 1; ++i)
			for (k = 0; k < N; ++k)
			{
				Rect &r = R[seq[k]];
				if (r.x <= X[i] && r.x + r.w >= X[i + 1] && r.h >= Y[j])
				{
					if (!taken[seq[k]])
					{
						ans.push_back(seq[k]);
						taken[seq[k]] = true;
					}
					break;
				}
			}
}

int main()
{
	int cn = 0;
	while (cin >> N && N)
	{
		if (cn++)
		{
			cout << endl;
		}
		int i;
		for (i = 0; i < N; ++i)
		{
			cin >> R[i];
			seq[i] = i;
		}
		sort(seq, seq + N, comp1);
		discrete();
		sort(ans.begin(), ans.end(), comp2);
		cout << "For map #" << cn << ", the visible buildings are numbered as follows:" << endl;
		cout << ans[0] + 1;
		for (i = 1; i < ans.size(); ++i)
		{
			cout << " " << ans[i] + 1;
		}
		cout << endl;
	}
	return 0;
}
