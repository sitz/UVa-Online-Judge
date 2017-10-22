#include <bits/stdc++.h>

using namespace std;

/*-----------------------------------------------------------------------
 *
 * File Name:   p2.c
 *
 * Author:      A. Lumsdaine
 *
 *-----------------------------------------------------------------------
 *
 * DESCRIPTION
 *     Source code file for problem #2 of 1996 ACM
 *     East-Central Regional Programming contest.
 *
 * DIAGNOSTICS
 *     More trigonometry (three-dimensional) needed here.  The main
 *     difficulty is calculating the volume of each quadrant.  The
 *     quadrant can be divided into three tetrahedrons, each of whose
 *     volume can be calculated using determinants.
 *
 *-----------------------------------------------------------------------
 */
typedef double set_of_criteria[100];
static void
polar_to_rectangular(double r, double theta, double *x, double *y)
{
	*x = r * cos(theta);
	*y = r * sin(theta);
}
static double
det2x2(double a, double b,
			 double c, double d)
{
	return (a * d - b * c);
}
static double
volume_of_tetrahedron(double px, double py, double pz,
											double qx, double qy, double qz,
											double rx, double ry, double rz)
{
	return (px * det2x2(qy, qz, ry, rz) - py * det2x2(qx, qz, rx, rz) +
					pz * det2x2(qx, qy, rx, ry)) /
				 6.0;
}
static double
annual_volume(int num_criteria, double previous_year[], double current_year[])
{
	int i, j;
	double sum = 0, ivol;
	double px, py, pz, qx, qy, qz, rx, ry, rz;
	double theta = 2.0 * M_PI / num_criteria;
	/* for each pie slice */
	for (i = 0; i < num_criteria; i++)
	{
		/* calculate the volume of the slice */
		/* There are three tetrahedra in the slice: abx, abc, bcd */
		/* det a b x -> p q r */
		polar_to_rectangular(previous_year[i], theta * i, &px, &py);
		j = (i + 1) % num_criteria;
		polar_to_rectangular(previous_year[j], theta * j, &qx, &qy);
		pz = qz = rz = 1;
		rx = ry = 0;
		ivol = volume_of_tetrahedron(px, py, pz, qx, qy, qz, rx, ry, rz);
		sum += fabs(ivol);
		/* det a b c -> p q r */
		polar_to_rectangular(current_year[i], theta * i, &rx, &ry);
		rz = 0;
		ivol = volume_of_tetrahedron(px, py, pz, qx, qy, qz, rx, ry, rz);
		sum += fabs(ivol);
		/* det b c d -> q r p */
		polar_to_rectangular(current_year[j], theta * j, &px, &py);
		pz = 0;
		ivol = volume_of_tetrahedron(px, py, pz, qx, qy, qz, rx, ry, rz);
		sum += fabs(ivol);
	}
	return sum;
}
int main()
{
	set_of_criteria current_year, previous_year;
	int i, config;
	char buffer[BUFSIZ], *cptr;
	int num_criteria, num_years, year, max_config = 0;
	double vol, total_vol, max_vol = 0, sum;
	/* Read number of criteria and number of years */
	(void)scanf("%d %d\n", &num_criteria, &num_years);
	config = 1;
	while (1)
	{
		total_vol = 0;
		/* For each configuration */
		/* Read first year */
		(void)gets(buffer);
		cptr = strtok(buffer, " ");
		for (i = 0, sum = 0; i < num_criteria; i++)
		{
			(void)sscanf(cptr, "%lf", &previous_year[i]);
			cptr = strtok(NULL, " ");
			sum += previous_year[i];
		}
		if (sum == 0)
		{
			break;
		}
		/* For each subsequent year */
		for (year = 1; year < num_years; year++)
		{
			/*  Read a line of criteria */
			(void)gets(buffer);
			cptr = strtok(buffer, " ");
			for (i = 0; i < num_criteria; i++)
			{
				(void)sscanf(cptr, "%lf", &current_year[i]);
				cptr = strtok(NULL, " ");
			}
			/* Calculate annual volume using present year and prev year */
			vol = annual_volume(num_criteria, previous_year, current_year);
			/* update previous year */
			for (i = 0; i < num_criteria; i++)
			{
				previous_year[i] = current_year[i];
			}
			/* update total volume */
			total_vol += vol;
		}
		/* If volume is largest, save configuration number */
		if (total_vol > max_vol)
		{
			max_vol = total_vol;
			max_config = config;
		}
		config++;
	}
	(void)fprintf(stdout, "%d %.2f\n", max_config, max_vol);
	return 0;
}
