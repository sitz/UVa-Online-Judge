#include <bits/stdc++.h>

using namespace std;

// greedy

struct interval
{
	int low, high;
	int num; // rook number
	int rook;// position within interval rook should take
};

inline int intervalCompare(const void *r1, const void *r2)
{
	// compare intervals by high end
	const interval *x1 = static_cast<const interval *>(r1);
	const interval *x2 = static_cast<const interval *>(r2);
	return x1->high - x2->high;
}

inline int numCompare(const void *r1, const void *r2)
{
	// compare by num field
	const interval *x1 = static_cast<const interval *>(r1);
	const interval *x2 = static_cast<const interval *>(r2);
	return x1->num - x2->num;
}

int main()
{
	int n;
	cin >> n;
	while (n)
	{
		// Read the input into two arrays of intervals (the two dimensions
		// of the problem are totally independent of each other).
		interval LR[n];// stores left and right ends of rectangles
		interval TB[n];// stores top and bottom ends of rectangles
		for (int i = 0; i < n; i++)
		{
			cin >> LR[i].low;
			cin >> TB[i].low;
			cin >> LR[i].high;
			cin >> TB[i].high;
			LR[i].num = i;
			TB[i].num = i;
			LR[i].rook = 0;
			TB[i].rook = 0;
		}
		bool fail = 0;
		// First, compute y coordinates of rooks greedily:  put each
		// rook in topmost unused row inside its rectangle
		qsort(TB, sizeof(TB) / sizeof(TB[0]), sizeof(TB[0]), intervalCompare);
		int usedrow[5005] = {0};
		for (int i = 0; i < n; i++)
		{
			for (int j = TB[i].low; j <= TB[i].high; j++)
				if (!usedrow[j])// could use fancy data structure to make this
				{
					// linear search go faster, but why bother?
					TB[i].rook = j;
					usedrow[j] = 1;
					j = n + 1;
				}
			if (!TB[i].rook)
			{
				fail = 1;
				i = n + 1;
			}
		}
		// Next, do exactly the same thing to compute x coordinates.
		qsort(LR, sizeof(LR) / sizeof(LR[0]), sizeof(LR[0]), intervalCompare);
		int usedcol[5005] = {0};
		for (int i = 0; i < n; i++)
		{
			for (int j = LR[i].low; j <= LR[i].high; j++)
				if (!usedcol[j])// could use fancy data structure to make this
				{
					// linear search go faster, but why bother?
					LR[i].rook = j;
					usedcol[j] = 1;
					j = n + 1;
				}
			if (!LR[i].rook)
			{
				fail = 1;
				i = n + 1;
			}
		}
		// Produce output
		if (fail)
		{
			cout << "IMPOSSIBLE\n";
		}
		else
		{
			// unsort the arrays so that the outputs come in right order
			qsort(LR, sizeof(LR) / sizeof(LR[0]), sizeof(LR[0]), numCompare);
			qsort(TB, sizeof(TB) / sizeof(TB[0]), sizeof(TB[0]), numCompare);
			for (int i = 0; i < n; i++)
			{
				cout << LR[i].rook << " " << TB[i].rook << "\n";
			}
		}
		cin >> n;
	}
	return 0;
}
