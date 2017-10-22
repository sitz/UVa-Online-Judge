#include <bits/stdc++.h>

using namespace std;

#define DIM 35
int matrix[DIM * DIM];
int m, n;
int flooded_regions;
int level;

static void msort_merge(void *base, size_t nmemb1, size_t nmemb2, size_t size,
												int (*compar)(const void *, const void *))
{
	void *copy;
	int i, j;
	copy = malloc((nmemb1 + nmemb2) * size);
	if (!copy)
	{
		abort(); /* should exit with error code... */
	}
	memcpy(copy, base, (nmemb1 + nmemb2) * size);
	i = j = 0;
	for (i = j = 0; i + j < nmemb1 + nmemb2;)
	{
		if (j == nmemb2 ||
				(i != nmemb1 &&
				 compar((char *)copy + i * size, (char *)copy + (nmemb1 + j) * size) < 0))
		{
			memcpy((char *)base + (i + j) * size, (char *)copy + i * size, size);
			i++;
		}
		else
		{
			memcpy((char *)base + (i + j) * size, (char *)copy + (nmemb1 + j) * size, size);
			j++;
		}
	}
}

void msort(void *base, size_t nmemb, size_t size,
					 int (*compar)(const void *, const void *))
{
	if (nmemb == 1)
	{
		return;
	}
	/* sort 2 parts */
	msort(base, nmemb / 2, size, compar);
	msort(((char *)(base) + (nmemb / 2 * size)), nmemb - nmemb / 2, size, compar);
	/* merge them */
	msort_merge(base, nmemb / 2, nmemb - nmemb / 2, size, compar);
}

static int compar_int(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

double calculate(void)
{
	int i;
	int curlevel = level;
	if (level <= 0)
	{
		flooded_regions = 0;
		return 0.0;
	}
	for (i = 0; i < m * n - 1; i++)
	{
		if (100 * (i + 1) * (matrix[i + 1] - matrix[i]) >= curlevel)
		{
			break;
		}
		curlevel -= 100 * (i + 1) * (matrix[i + 1] - matrix[i]);
	}
	flooded_regions = i + 1;
	return (double)(matrix[i]) + (double)curlevel / (double)(100 * (i + 1));
}

int main()
{
	int region = 1;
	int i, j;
	while (1)
	{
		scanf("%d %d", &m, &n);
		if (m == 0 && n == 0)
		{
			break;
		}
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf("%d", &matrix[i * n + j]);
			}
		}
		scanf("%d", &level);
		msort(matrix, m * n, sizeof(int), compar_int);
		printf("Region %d\n", region++);
		printf("Water level is %.2f meters.\n", calculate());
		printf("%.2f percent of the region is under water.\n",
					 100.0 * (double)flooded_regions / (m * n));
		printf("\n");
	}
	return 0;
}
