#include <bits/stdc++.h>

using namespace std;

#define MAXROBOTS 20
#define MAXREQUESTS 5000

const int debug = 0;

typedef struct {int time, origin, dest, weight, done;} request;
request r[MAXREQUESTS];

typedef struct {int idle, loaded, pos, wait, util, req, origin, dest, capacity;} transrob;
transrob t[MAXROBOTS];

int m, n, rnum, beg, end_, case_no = 1;
FILE *inp;

int read_data()
{
	int i;
	scanf("%d %d", &n, &m);
	if (n == 0 && m == 0)
	{
		return 0;
	}
	for (i = 0; i < m; i++)
	{
		t[i].idle = 1;
		t[i].pos = 0;
		t[i].util = 0;
		scanf("%d", &t[i].capacity);
	}
	for (rnum = 0;; rnum++)
	{
		scanf("%d %d %d %d", &r[rnum].time, &r[rnum].origin, &r[rnum].dest, &r[rnum].weight);
		if (r[rnum].time == -1)
		{
			break;
		}
		r[rnum].origin--;
		r[rnum].dest--;
		r[rnum].done = 0;
	}
	return 1;
}

int assign_requests(int tim)
{
	int ass, i, j, tr, dist;
	ass = 0;
	for (i = 0; i < rnum && r[i].time <= tim; i++)
		if (r[i].done == 0)
		{
			tr = -1;
			dist = n + 1;
			for (j = 0; j < m; j++)
				if (t[j].idle && t[j].capacity >= r[i].weight &&
						(r[i].origin - t[j].pos + n) % n < dist)
				{
					tr = j;
					dist = (r[i].origin - t[j].pos + n) % n;
				}
			if (tr != -1)
			{
				ass++;
				t[tr].idle = 0;
				t[tr].wait = (r[i].origin - t[tr].pos + n) % n +
										 (r[i].dest - r[i].origin + n) % n + 2 * 5;
				t[tr].util += t[tr].wait;
				t[tr].pos = r[i].dest;
				r[i].done = tim + t[tr].wait;
			}
		}
	return ass;
}

void move_robot(int rob)
{
	if (t[rob].idle)
	{
		return;
	}
	t[rob].wait--;
	if (t[rob].wait == 0)
	{
		t[rob].idle = 1;
	}
}

void do_simulation()
{
	int i, reqleft, idlenum;
	reqleft = rnum;
	idlenum = m;
	beg = r[0].time;
	end_ = beg;
	while (reqleft > 0 || idlenum < m)
	{
		reqleft -= assign_requests(end_++);
		idlenum = 0;
		for (i = 0; i < m; i++)
		{
			move_robot(i);
			idlenum += t[i].idle;
		}
	}
}

void output_stats()
{
	int i, s1, s2;
	printf("Simulation %d\n", case_no++);
	s1 = s2 = 0;
	for (i = 0; i < rnum; i++)
	{
		s1 += r[i].done - r[i].time;
	}
	for (i = 0; i < m; i++)
	{
		s2 += t[i].util;
	}
	printf("Average wait time   = %.3f minutes\n", (double)s1 / (double)rnum);
	printf("Average utilization = %.3f %%\n",
				 100.0 * (double)s2 / ((double)(end_ - beg) * (double)m));
	printf("\n");
}

int main()
{
	while (read_data())
	{
		do_simulation();
		output_stats();
	}
	return 0;
}
