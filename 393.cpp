#include <bits/stdc++.h>

using namespace std;

const double maxdist = 0x7FFFFFFF;
int wall_num;
int edge_num;
int point_num;
double precision = 0.00000001;//用来控制判断精度
double dist[100];
double point_dist[100][100];
struct edge_node
{
	double x1, x2, y1, y2;
} edge[80];
struct point_node
{
	double x, y;
} point[100];

/*
 *在边的集合里添加边
 *在点的集合里添加点
 */
void add_edge(double x1, double y1, double x2, double y2)
{
	edge[edge_num].x1 = x1;
	edge[edge_num].x2 = x2;
	edge[edge_num].y1 = y1;
	edge[edge_num].y2 = y2;
	++edge_num;
}
void add_point(double x, double y)
{
	point[point_num].x = x;
	point[point_num].y = y;
	point_num++;
}

/*
 *使用dijkstra求两点之间
 */
void dijkstra()
{
	for (int i = 1; i < point_num; i++)
	{
		dist[i] = maxdist;
	}
	bool reach[100];
	memset(reach, true, sizeof(reach));
	for (int i = 1; i <= point_num; i++)
	{
		int pos;
		double value = maxdist;
		for (int j = 0; j < point_num; j++)
			if (dist[j] < value && reach[j])
			{
				value = dist[j];
				pos = j;
			}
		reach[pos] = false;
		for (int j = 0; j < point_num; j++)
			if (reach[j] &&
					dist[pos] + point_dist[pos][j] < dist[j])
			{
				dist[j] = dist[pos] + point_dist[pos][j];
			}
	}
}

/*
 *以下一连串子程序用叉积来判断两条线段是否相交
 */
double det(double x1, double y1, double x2, double y2)
{
	return x1 * y2 - x2 * y1;
}
double cross(point_node a, point_node b, point_node c)
{
	return det(b.x - a.x, b.y - a.y, c.x - a.x, c.y - a.y);
}
int cmp(double d)
{
	if (fabs(d) < precision)
	{
		return 0;
	}
	return (d > 0) ? 1 : -1;
}
bool segment_cross_simple(point_node a, point_node b, point_node c, point_node d)
{
	if (((cmp(cross(a, c, d)) ^ cmp(cross(b, c, d))) == -2) &&
			((cmp(cross(c, a, b)) ^ cmp(cross(d, a, b))) == -2))
	{
		return true;
	}
	else
	{
		return false;
	}
}
/*
 *解决过程
 */
void solve()
{
	/*
	 *初始化过程
	 */
	memset(edge, 0, sizeof(edge));
	memset(point, 0, sizeof(point));
	memset(dist, 0, sizeof(dist));
	memset(point_dist, 0, sizeof(point_dist));
	//点集和边集清零
	edge_num = 0;
	point_num = 0;
	add_point(0, 5);
	add_point(10, 5);
	//增加起点和终点
	for (int i = 1; i <= wall_num; i++)
	{
		double x, y1, y2, y3, y4;
		cin >> x >> y1 >> y2 >> y3 >> y4;
		//输入每个墙，并添加墙所对应的边
		add_edge(x, 0, x, y1);
		add_edge(x, y2, x, y3);
		add_edge(x, y4, x, 10);
		//添加墙所对应的新增顶点
		add_point(x, y1);
		add_point(x, y2);
		add_point(x, y3);
		add_point(x, y4);
	}
	for (int i = 0; i < point_num; i++)
		for (int j = 0; j < point_num; j++)//枚举任意两个点
			if (i != j)											 //如果他们不是同一个点
			{
				bool link = true;
				for (int k = 0; k < edge_num; k++)
				{
					point_node lv, lv2;
					lv.x = edge[k].x1;
					lv.y = edge[k].y1;
					lv2.x = edge[k].x2;
					lv2.y = edge[k].y2;
					if (segment_cross_simple(point[i], point[j], lv, lv2))
					{
						link = false;
					}
				}
				if (link)
					point_dist[i][j] = sqrt(pow(point[i].x - point[j].x, 2) +
																	pow(point[i].y - point[j].y, 2));
				else
				{
					point_dist[i][j] = maxdist;
				}
			}
	//对于任意两个顶点求他们之间的路径
	dijkstra();
	//求出源点开始的dijkstra
	cout << setiosflags(ios::fixed)
			 << setprecision(2)
			 << dist[1] << endl;
}

/*
 *主过程
 */
int main()
{
	cin >> wall_num;
	while (wall_num != -1)
	{
		solve();
		cin >> wall_num;
	}
}
