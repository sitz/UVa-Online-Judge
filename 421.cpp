#include <bits/stdc++.h>

using namespace std;

/*-----------------------------------------------------------------------
 *
 * File Name:   p3.c
 *
 * Author:      A. Lumsdaine
 *
 *-----------------------------------------------------------------------
 *
 * DESCRIPTION
 *     Source code file for problem #3 of 1996 ACM
 *     East-Central Regional Programming contest.
 *
 * DIAGNOSTICS
 *     This is probably the hardest problem of the contest.  To sort
 *     the polygons, one needs to match them up polygon to polygon
 *     and then vertex by vertex.  Initial matches can be made by
 *     calculating the distance between vertices of each polygon and
 *     then normalizing the distances by the total circumference.
 *     Candidate matches found this way must then be further checked on
 *     a vertex by vertex basis.
 *
 *-----------------------------------------------------------------------
 */
typedef double polygon[100];
static int
to_try_match(int num_edges, double p1[], double p2[], int *shift)
{
	int i, j, xshift, match = 0;
	for (xshift = 0; xshift < num_edges; xshift++)
	{
		match = 1;
		for (i = 0; i < num_edges; i++)
		{
			j = (i + xshift) % num_edges;
			if (fabs(p1[i] - p2[j]) > 1.e-3)
			{
				match = 0;
				break;
			}
		}
		if (match == 1)
		{
			break;
		}
	}
	if (match == 1)
	{
		*shift = xshift;
		return 0;
	}
	return -1;
}
static int
find_distance_match(int i, int num_edges,
										polygon d1[], polygon d2[], int *shift, int start)
{
	int idx;
	for (idx = start; idx < 100; idx++)
		if (to_try_match(num_edges, d1[idx], d2[i], shift) == 0)
		{
			break;
		}
	return idx;
}
static void
polar_to_rectangular(double r, double theta, double *x, double *y)
{
	*x = r * cos(theta);
	*y = r * sin(theta);
}
static int
align_vertices(int num_edges, polygon x, polygon y, polygon r,
							 int shift, double *angle)
{
	int i = 0, j, j1, match, to_try;
	double xangle[2], abs1, abs2, iprod, rat;
	double vx1, vx2, vy1, vy2, theta = 2 * M_PI / num_edges, scale;
	j = shift;
	j1 = (shift + 1) % num_edges;
	polar_to_rectangular(r[0], M_PI_2, &vx1, &vy1);
	polar_to_rectangular(r[1], M_PI_2 - theta, &vx2, &vy2);
	vx1 = vx2 - vx1;
	vy1 = vy2 - vy1;
	vx2 = x[j1] - x[j];
	vy2 = y[j1] - y[j];
	abs1 = sqrt(vx1 * vx1 + vy1 * vy1);
	abs2 = sqrt(vx2 * vx2 + vy2 * vy2);
	scale = abs2 / abs1;
	iprod = vx1 * vx2 + vy1 * vy2;
	rat = iprod / (abs1 * abs2);
	xangle[0] = acos(rat);
	xangle[1] = 2. * M_PI - xangle[0];
	for (to_try = 0; to_try < 2; to_try++)
	{
		/* Calculate shift */
		polar_to_rectangular(r[0] * scale, M_PI_2 + xangle[to_try], &vx1, &vy1);
		vx2 = vx1 - x[shift];
		vy2 = vy1 - y[shift];
		/* Now see if the other vertices line up */
		match = 1;
		for (i = 0; i < num_edges; i++)
		{
			j = (shift + i) % num_edges;
			polar_to_rectangular(r[i] * scale, M_PI_2 + xangle[to_try] - theta * i,
													 &vx1, &vy1);
			vx1 -= vx2;
			vy1 -= vy2;
			if (fabs(x[j] - vx1) > 1.e-3 || fabs(y[j] - vy1) > 1.e-3)
			{
				match = 0;
				break;
			}
		}
		if (match == 1)
		{
			*angle = xangle[to_try];
			break;
		}
		else
		{
			*angle = 0.0;
		}
	}
	return match;
}
int main()
{
	char buffer[BUFSIZ], *cptr;
	int i, j, k, num_polygons, num_edges, candidate;
	polygon r[100], x[100], y[100], d1[100], d2[100];
	double theta, sum, u, v, angle;
	int index[100], matched, shift;
	double rotate[100];
	/* Read number of polygons and number of edges of each polygon */
	(void)scanf("%d %d\n", &num_polygons, &num_edges);
	theta = 2.0 * M_PI / num_edges;
	/* Read polygons */
	for (i = 0; i < num_polygons; i++)
	{
		(void)gets(buffer);
		cptr = strtok(buffer, " ");
		for (j = 0; j < num_edges; j++)
		{
			(void)sscanf(cptr, "%lf", &r[i][j]);
			cptr = strtok(NULL, " ");
		}
		/* Convert (r, theta) to normalized distances */
		/* c = sqrt(a^2+b^2-2 ab cos(theta)) */
		for (j = 0, sum = 0; j < num_edges; j++)
		{
			k = (j + 1) % num_edges;
			d1[i][j] = sqrt(r[i][j] * r[i][j] + r[i][k] * r[i][k] - 2 * r[i][j] * r[i][k] * cos(theta));
			sum += d1[i][j];
		}
		for (j = 0; j < num_edges; j++)
		{
			d1[i][j] /= sum;
		}
	}
	for (i = 0; i < num_polygons; i++)
	{
		(void)gets(buffer);
		cptr = strtok(buffer, " ");
		for (j = 0; j < num_edges; j++)
		{
			(void)sscanf(cptr, "%lf", &x[i][j]);
			cptr = strtok(NULL, " ");
			(void)sscanf(cptr, "%lf", &y[i][j]);
			cptr = strtok(NULL, " ");
		}
		/* Convert (x, y) to normalized distances */
		for (j = 0, sum = 0; j < num_edges; j++)
		{
			k = (j + 1) % num_edges;
			u = x[i][j] - x[i][k];
			v = y[i][j] - y[i][k];
			d2[i][j] = sqrt(u * u + v * v);
			sum += d2[i][j];
		}
		for (j = 0; j < num_edges; j++)
		{
			d2[i][j] /= sum;
		}
	}
	/* Match up normalized distances */
	for (i = 0; i < num_polygons; i++)
	{
		matched = 0;
		candidate = -1;
		do
		{
			candidate =
					find_distance_match(i, num_edges, d1, d2, &shift, candidate + 1);
			matched = align_vertices(num_edges, x[i], y[i], r[candidate],
															 shift, &angle);
		} while (matched == 0);
		rotate[i] = angle;
		index[i] = candidate;
	}
	for (i = 0; i < num_polygons; i++)
	{
		(void)printf("%d %.1f\n", index[i] + 1, 180 * rotate[i] / M_PI);
	}
	return 0;
}
