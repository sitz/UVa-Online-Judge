#include <bits/stdc++.h>

using namespace std;

template <typename tx>
inline void swap(tx &a, tx &b)
{
	tx c(a);
	a = b;
	b = c;
}

template <typename tx>
inline int cmp(tx const &a, tx const &b)
{
	return a < b ? -1 : a == b ? 0 : 1;
}

struct point
{
	int16_t x, y;
};

inline float dist(point const &a, point const &b)
{
	return hypotf(a.x - (float)b.x, a.y - (float)b.y);
}

inline int compare_y(void const *a, void const *b)
{
	point const &p = *((point *)a);
	point const &q = *((point *)b);
	return (cmp(p.y, q.y) << 1) + cmp(p.x, q.x);
}

inline int compare_x(void const *a, void const *b)
{
	point const &p = *((point *)a);
	point const &q = *((point *)b);
	return (cmp(p.x, q.x) << 1) + cmp(p.y, q.y);
}

float closest_pair_distance(point const *const &PX,
														ptrdiff_t const &x0, ptrdiff_t const &x1,
														point *const &P, ptrdiff_t const &len, point &best)
{
	static point L[16384];
	static point R[16384];
	float ret = std::numeric_limits<float>::infinity();
	if (len > 2)
	{
		ptrdiff_t si = (x0 + x1 - 1) >> 1;
		int16_t sx = PX[si].x;
		int16_t sy = PX[si].y;
		float dr, dl;
		ptrdiff_t l = 0, r = 0;
		ptrdiff_t i = 0, j = 0, k = 0;
		point lp, rp;
		for (ptrdiff_t i = 0; i < len; ++i)
		{
			if (sx < P[i].x || (sx == P[i].x && sy < P[i].y))
			{
				R[r++] = P[i];
			}
			else
			{
				L[l++] = P[i];
			}
		}
		memcpy(P, L, l * sizeof(point));
		memcpy(P + l, R, r * sizeof(point));
		dl = closest_pair_distance(PX, x0, x0 + l, P, l, lp);
		dr = closest_pair_distance(PX, x0 + l, x1, P + l, r, rp);
		if (dl < dr)
		{
			best = lp;
			ret = dl;
		}
		else
		{
			best = rp;
			ret = dr;
		}
		memcpy(L, P, l * sizeof(point));
		memcpy(R, P + l, r * sizeof(point));
		while (i < l && j < r)
		{
			if (i < l && (L[i].y < R[j].y || (L[i].y == R[j].y && L[i].x < R[j].x)))
			{
				P[k++] = L[i++];
			}
			else
			{
				P[k++] = R[j++];
			}
		}
		while (i < l)
		{
			P[k++] = L[i++];
		}
		while (j < r)
		{
			P[k++] = R[j++];
		}
		for (ptrdiff_t i = 0; i < len; ++i)
		{
			if (fabs(P[i].x - sx) < ret)
			{
				ptrdiff_t j = i + 1;
				for (int k = 0; k < 7 && j < len; ++j)
				{
					if (fabs(P[j].x - sx) < ret)
					{
						float t = dist(P[i], P[j]);
						if (t < ret)
						{
							ret = t;
							best = P[i];
						}
						++k;
					}
				}
			}
		}
	}
	else if (len == 2)
	{
		ret = dist(P[0], P[1]);
		best = P[0];
	}
	return ret;
}

void test_case()
{
	static point P[16384];
	static point PX[16384];
	float result = std::numeric_limits<float>::infinity();
	point best;
	uint16_t N;
	scanf("%hu", (short unsigned int *)&N);
	for (uint16_t i = 0; i < N; ++i)
	{
		scanf("%hd %hd", (short int *)&(P[i].x), (short int *)&(P[i].y));
	}
	memcpy(PX, P, N * sizeof(point));
	qsort(P, N, sizeof(point), compare_y);
	qsort(PX, N, sizeof(point), compare_x);
	result = closest_pair_distance(PX, 0, N, P, N, best);
	printf("%.3f %.3f\n\n", (float)best.x, (float)best.y);
}

int main()
{
	uint16_t T;
	scanf("%hu", (short unsigned int *)&T);
	while (T--)
	{
		test_case();
	}
	return EXIT_SUCCESS;
}
