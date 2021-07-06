#include <bits/stdc++.h>

using namespace std;

#define MAXN 30005

int MaxHeap[MAXN], MinHeap[MAXN], Com[MAXN], Num[MAXN];
int N, com, headN, headC, MaxHeapSize, MinHeapSize;

void InsMax(int key)
{
	int i, temp;
	i = MaxHeapSize;
	MaxHeap[MaxHeapSize] = key;
	MaxHeapSize++;
	while (i > 1 && MaxHeap[i / 2] < MaxHeap[i])
	{
		temp = MaxHeap[i / 2];
		MaxHeap[i / 2] = MaxHeap[i];
		MaxHeap[i] = temp;
		i /= 2;
	}
}

void InsMin(int key)
{
	int i, temp;
	i = MinHeapSize;
	MinHeap[MinHeapSize] = key;
	MinHeapSize++;
	while (i > 1 && MinHeap[i / 2] > MinHeap[i])
	{
		temp = MinHeap[i / 2];
		MinHeap[i / 2] = MinHeap[i];
		MinHeap[i] = temp;
		i /= 2;
	}
}

void MinHeapi(int n)
{
	int l, r, sm, temp;
	l = n * 2;
	r = l + 1;
	sm = n;
	if (l <= MinHeapSize && MinHeap[l] < MinHeap[n])
		sm = l;
	if (r <= MinHeapSize && MinHeap[r] < MinHeap[sm])
		sm = r;
	if (sm != n)
	{
		temp = MinHeap[sm];
		MinHeap[sm] = MinHeap[n];
		MinHeap[n] = temp;
		MinHeapi(sm);
	}
}

void MaxHeapi(int n)
{
	int l, r, sm, temp;
	l = n * 2;
	r = l + 1;
	sm = n;
	if (l <= MaxHeapSize && MaxHeap[l] > MaxHeap[n])
		sm = l;
	if (r <= MaxHeapSize && MaxHeap[r] > MaxHeap[sm])
		sm = r;
	if (sm != n)
	{
		temp = MaxHeap[sm];
		MaxHeap[sm] = MaxHeap[n];
		MaxHeap[n] = temp;
		MaxHeapi(sm);
	}
}

int ExtracMin()
{
	int min;
	min = MinHeap[1];
	MinHeap[1] = MinHeap[MinHeapSize - 1];
	MinHeapSize--;
	MinHeapi(1);
	return min;
}

void Print()
{
	int k;
	printf("%d\n", MaxHeap[1]);
	if (MinHeapSize > 1)
	{
		k = ExtracMin();
		InsMax(k);
	}
}

int Operation(int ind)
{
	int val;
	val = Num[ind];
	if (MaxHeapSize <= headC)
		InsMax(val);
	else if (MaxHeapSize == headC + 1)
	{
		if (MaxHeap[1] > val)
		{
			InsMin(MaxHeap[1]);
			MaxHeap[1] = val;
			MaxHeapi(1);
		}
		else
			InsMin(val);
	}
	if (ind == Com[headC])
	{
		Print();
		headC++;
		if (headC > com)
			return 1;
		while (Com[headC] == Com[headC - 1] && headC <= com)
		{
			Print();
			headC++;
		}
	}
	return 0;
}

void Cal()
{
	int i;
	MaxHeapSize = MinHeapSize = headC = 1;
	for (i = 1; i <= N; i++)
		if (Operation(i))
			break;
	memset(MaxHeap, 0, sizeof(int) * MAXN);
	memset(MinHeap, 0, sizeof(int) * MAXN);
}

int main()
{
	int i, j, Kase = 1;
	scanf("%d", &Kase);
	while (Kase--)
	{
		scanf("%d%d", &N, &com);
		for (i = 1; i <= N; i++)
			scanf("%d", &Num[i]);
		for (j = 1; j <= com; j++)
			scanf("%d", &Com[j]);
		Cal();
		if (Kase)
			printf("\n");
	}
	return 0;
}
