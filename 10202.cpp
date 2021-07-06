#include <bits/stdc++.h>

using namespace std;

#define MAX 10

typedef long int Int;

Int a[MAX * MAX], b[MAX];
int n, n2, prev_[MAX * MAX], nxt[MAX * MAX], first_item, search_start;

// init the singly linked list that chains the sum S altogether
void init_list()
{
	prev_[2] = 0;// zero indicates end of list
	nxt[2] = 3;// The 'nxt' of S3 is S4
	for (int i = 3; i < n2; i++)
	{
		prev_[i] = i - 1;
		nxt[i] = i + 1;
	}
	first_item = 2;// first_item is the zero-based index of the current smallest sum S
}

// remove a node (sum S) from the singly linked list
void remove(int i)
{
	// are we at the end of the linked list?
	if (prev_[i] == 0)
	{
		// Yes.
		prev_[nxt[i]] = 0;
		first_item = nxt[i];
	}
	else
	{
		// No.
		nxt[prev_[i]] = nxt[i];
		prev_[nxt[i]] = prev_[i];
	}
}

// gets the current smallest sum and remove it from the linked list
Int get_smallest()
{
	Int x = a[first_item];
	remove(first_item);
	return x;
}

// search the linked list for the sum x and remove it from the list
bool find_and_remove(Int x)
{
	// assign the sum at the end so that the while loop below will stop
	a[n2] = x;
	int i = search_start;
	while (a[i] < x)
	{
		i = nxt[i];
	}
	// Is the sum found? Did we reach the end of the list?
	if (i == n2)
	{
		return false;
	}
	// Is the sum found?
	if (a[i] != x)
	{
		return false;
	}
	remove(i);
	// The nxt search  shall start at the  smallest sum that is bigger than x
	// so as to ensure that all sums are in ascending order
	search_start = nxt[i];
	return true;
}

bool test(int t)
{
	// a[0] is S1 = N1 + N2 and a[1] is S2 = N1 + N3
	// here we assume a[t] is N2 + N3
	// a[t] is S[t+1]
	// so x will be 2 N1 + N2 + N3 - (N2 + N3)
	Int x = a[0] + a[1] - a[t];
	if (x % 2 != 0)
	{
		return false;
	}
	// b is the array of integers that are the solution
	b[0] = x / 2;			 // N1
	b[1] = a[0] - b[0];// N2
	b[2] = a[t] - b[1];// N3
	init_list();
	// remove a[t]  ( S[t+1] ) from the linked list.
	remove(t);
	// now we try to figure out whats N4, N5 ... etc.
	// by brute force
	// we start from N4 first
	// This is the main algorithm
	for (int i = 3; i < n; i++)
	{
		// Assume the current smallest sum is N1 + N[i + 1]
		x = get_smallest();
		b[i] = x - b[0];// subtract from N1 to calculate N[i + 1]
		search_start = first_item;
		// Compute the possible pair wise sums of  N[i + 1]
		// The pair wise sums computed are:
		// N[i + 1] + N2
		// N[i + 1] + N3
		// ...
		// N[i + 1] + N[i ]
		// Basically, the loop below will check whether the sums are in ascending order in the linked list.
		for (int j = 1; j < i; j++)
		{
			// Calculate the sum of  N[i+1] and  N[j + 1] and check whether it exists in the input
			// if exists, then remove it from the linked list
			// if does not exist, assumption fails.
			if (!find_and_remove(b[i] + b[j]))
			{
				return false;
			}
		}
	}
	return true;
}

// compare function to sort out the array
int compare(Int *v1, Int *v2)
{
	return *v1 - *v2;
}

void solve()
{
	// sort the sums from smallest to biggest
	qsort(a, n2, sizeof(Int), (int (*)(const void *, const void *))compare);
	// brute force
	for (int i = 2; i < n; i++)
	{
		// we assume a[i] is N2 + N3 and then we will go from there
		// if things doesn't work out, that means the assumption is false
		// note that a[i] is N[i+1]
		if (test(i))
		{
			// we reach here when we solved it, that means our assumption is correct
			// print out solution
			printf("%ld", b[0]);
			for (int j = 1; j < n; j++)
			{
				printf(" %ld", b[j]);
			}
			printf("\n");
			return;
		}
	}
	printf("Impossible\n");
}

int main()
{
	while (scanf("%d", &n) == 1)
	{
		n2 = n * (n - 1) / 2; // calculate the no. of sums
		for (int i = 0; i < n2; i++)
		{
			scanf("%ld", &a[i]);
		}
		solve();
	}
	return 0;
}
