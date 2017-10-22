#include <bits/stdc++.h>

using namespace std;

//===============================
//  Simplex Method
//  UVa 10498
//    AC on 22/11/07
//    Code by kn
//===============================
#define EPSILON 1e-8
int n;// # of unknwons
int m;// # of constraints

int main()
{
	while (scanf("%d%d", &n, &m) > 0)
	{
		double arr[m + 1][n + m + 1];
		double rhs[m + 1];
		int var[m + 1];
		for (int j = 0; j < m + 1; j++)
			for (int i = 0; i < m + n + 1; i++)
			{
				arr[j][i] = 0.00;
			}
		// Objective fct
		for (int i = 1; i <= n; i++)
		{
			scanf("%lf", &arr[0][i]);
		}
		for (int i = 1; i <= n; i++)
		{
			arr[0][i] = -arr[0][i];
		}
		rhs[0] = 0;
		// m constraints
		for (int row = 1; row <= m; row++)
		{
			for (int i = 1; i <= n; i++)
			{
				scanf("%lf", &arr[row][i]);
			}
			scanf("%lf", &rhs[row]);
		}
		arr[0][0] = 1;
		for (int row = 1; row <= m; row++)
		{
			arr[row][n + row] = 1;
		}
		// Each row, which variable is dependent
		// 0   : Z
		// 1   : x1,   2   : x2,   ...
		// n+1 : S1,   n+2 : S2,   ...
		var[0] = 0;
		for (int row = 1; row <= m; row++)
		{
			var[row] = n + row;
		}
		// Print
		/*
		for(int row=0; row<=m; row++){
		for(int col=0; col<=n+m; col++)
		printf("%10.4lf", arr[row][col]);
		printf("%10.4lf", rhs[row]);
		puts("");
		}
		puts("");
		*/
		while (true)
		{
			// Find entering variable
			bool quit = false;
			double min = 0.000;
			int enter_col = -1;// col index
			for (int i = 0; i <= n + m; i++)
			{
				if (arr[0][i] < min - EPSILON)
				{
					min = arr[0][i];
					enter_col = i;
				}
			}
			// Check if iteration ends
			if (enter_col == -1 || fabs(min) < EPSILON)
			{
				//          puts("Iteration ends");
				break;
			}
			// Find entering variables
			// Perform minimum ratio test
			double mrt = -1;
			int mrt_row = -1;
			for (int row = 1; row <= m; row++)
			{
				if (fabs(arr[row][enter_col]) < EPSILON)
				{
					continue;
				}
				double tmp = rhs[row] / arr[row][enter_col];
				if (tmp >= EPSILON || fabs(tmp) < EPSILON)
					if (mrt < 0 || tmp < mrt)
					{
						mrt = tmp;
						mrt_row = row;
					}
			}
			/*
			printf("mrt_row = %d, enter_col = %d\n", mrt_row, enter_col);
			printf("mrt=%lf\n", mrt);

			if(mrt_row==-1 || mrt < 0){
			printf("BUG at 76\n");
			return 1;
			}
			*/
			// Gaussian Elimination for other rows
			for (int row = 0; row <= m; row++)
			{
				if (row == mrt_row)
				{
					continue;
				}
				if (fabs(arr[row][enter_col]) < EPSILON)
				{
					continue;
				}
				double factor = -arr[row][enter_col] / arr[mrt_row][enter_col];
				arr[row][enter_col] = 0.0000;
				for (int col = 1; col <= n + m; col++)
				{
					if (col == enter_col)
					{
						continue;
					}
					arr[row][col] += factor * arr[mrt_row][col];
				}
				rhs[row] += factor * rhs[mrt_row];
			}
			// Normalize row - mrt_row
			for (int col = 1; col <= n + m; col++)
			{
				if (col == enter_col)
				{
					continue;
				}
				arr[mrt_row][col] /= arr[mrt_row][enter_col];
			}
			rhs[mrt_row] /= arr[mrt_row][enter_col];
			arr[mrt_row][enter_col] = 1;
			/*
			for(int row=0; row<=m; row++){
			for(int col=0; col<=n+m; col++)
			printf("%10.4lf", arr[row][col]);
			printf("%10.4lf", rhs[row]);
			puts("");
			}
			*/
			var[mrt_row] = enter_col;
		}
		printf("Nasa can spend %d taka.\n", (int)ceil(rhs[0] * m));
	}
	return 0;
}
