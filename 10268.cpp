#include <bits/stdc++.h>

using namespace std;

const long MX = 1000001;

char str1[MX], str2[MX], *ptr;
double arr[MX], arrD[MX], result, temp;

double horner(int n, double arr[], double x)
{
	// compute val of polynomial of ord n
	double p;
	p = arr[n];
	for (int i = n - 1; i >= 0; --i)
	{
		p = p * x + arr[i];
	}
	return p;
}

int main()
{
	int x, i, order;
	while (cin.getline(str1, sizeof(str1)))
	{
		cin.getline(str2, sizeof(str2));
		sscanf(str1, "%d", &x);
		i = -1;
		ptr = strtok(str2, " \t\n");
		while (ptr)
		{
			++i;
			sscanf(ptr, "%lf", &arr[i]);
			ptr = strtok(NULL, " \t\n");
		}
		temp = i;
		order = --i;
		for (int j = 0; j <= order; ++j)
		{
			arrD[j] = temp-- * arr[j];
		}
		reverse(arrD, arrD + order + 1);
		result = horner(order, arrD, x);
		printf("%.0lf\n", result);
	}
	return 0;
}
