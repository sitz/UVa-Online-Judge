#include <bits/stdc++.h>

using namespace std;

struct XCoord
{
	bool start;
	double x;
	int id;
	XCoord(int _id, double _x, bool _start) : id(_id), x(_x), start(_start) {}
};

inline bool cmp(const XCoord *a, const XCoord *b)
{
	return a->x < b->x;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		vector<XCoord*> vx;
		map<int, pair<double, double> > my;

		int NR;
		scanf("%d", &NR);
		while (NR > 0)
		{
			NR--;
			double x1, y1, x2, y2;
			scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			if (x1 > x2)
			{
				swap(x1, x2);
			}
			if (y1 > y2)
			{
				swap(y1, y2);
			}
			vx.push_back(new XCoord(NR, x1, true));
			vx.push_back(new XCoord(NR, x2, false));
			my[NR] = make_pair(y1, y2);
		}
		sort(vx.begin(), vx.end(), cmp);

		int NL;
		scanf("%d", &NL);
		while (NL--)
		{
			double y_l;
			scanf("%lf", &y_l);
			int overlap = 0, max_overlap = 0;
			double x_left = -1.0f, x_right = -1.0f, x_prev = vx[0]->x;// only upd when y_l is used
			int n = vx.size();
			for (int i = 0; i < n; i++)
			{
				double x_curr = vx[i]->x;
				int id = vx[i]->id;
				if (my[id].first <= y_l && my[id].second >= y_l)
				{
					if (vx[i]->start)
					{
						overlap++;
					}
					else
					{
						if (overlap > max_overlap)
						{
							max_overlap = overlap;
							x_left = x_prev;
							x_right = x_curr;
						}
						overlap--;
					}
					x_prev = x_curr;
				}
			}

			if (max_overlap > 0)
			{
				printf("%d %.2lf %.2lf\n", max_overlap, x_left, x_right);
			}
			else
			{
				printf("0\n");
			}
		}

		if (T)
		{
			printf("\n");
		}
	}
}
