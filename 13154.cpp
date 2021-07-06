#include <bits/stdc++.h>

using namespace std;

// given a str len 10 ^ 4 elements <10 ^ 9
// define the xor sum within the interval to be xor for the left and right neighbors
// and then do the same until there is only one element for the xor sum
// there will be 30,000 interval query

// first observe the behavior of the interval xor
// 1 2 3
// 1 ^ 2 2 ^ 3
// 1 ^ 2 ^ 2 ^ 3

// 1 of which was xor 1, 2 2, 3 1 times
// in 1 to 4 was 1 1 times, 2 3 times, 3 3 times, 4 times
// in fact, pascal triangle corresponds to the first few lines up
// then the xor is evenly zero
// so set the pascal odd to an even number to zero
// we're going to a sierpinski triangle
// @ https://en.wikipedia.org/wiki/file:sierpinski_triangle.svg
// then because he is broken, for example, the first of the fifth line can correspond to the first line of the first
// so we can know in log n that this is 1 or 0 within the triangle
// apply o (nqlgn) => tle
// but this is not enough
// so do observe in n <10000 triangles within the interval 01 not more than 1024
// so the first section of the triangle pretreatment 01
// then the prefix can be optimized

// DO NOT RE-ORDER VAR DECL; somehow, will RE //
int a[10010], psum[10010], n, q;
bool p[10010][10010];
vector<pair<int, int> > v[10000];
// //

void gen()
{
	for (int i = 1; (1 << (i - 1)) < 10000; i++)
	{
		for (int j = (1 << (i - 1)) + 1; j <= 10000 && j <= (1 << i); j++)
		{
			for (int k = 0; k < j; k++)
			{
				p[j][k] = p[j - (1 << (i - 1))][k >= j / 2 ? j - k - 1 : k];
			}
		}
	}
	for (int i = 1; i <= 10000; i++)
	{
		int head = 0;
		bool finding = false;
		for (int j = 0; j < i; j++)
		{
			if (!finding && p[i][j] == 0)
			{
				v[i].push_back({head, j - 1});
				finding = true;
			}
			else if (finding && p[i][j] == 1)
			{
				head = j;
				finding = false;
			}
		}
		v[i].push_back({head, i - 1});
	}
}

int main()
{
	p[1][0] = 1;
	gen();
	int T;
	scanf("%d", &T);
	for (int I = 1; I <= T; I++)
	{
		fill(psum, psum + 10010, 0);
		printf("Case %d:\n", I);
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", a + i);
			psum[i + 1] = a[i] ^ psum[i];
		}
		scanf("%d", &q);
		for (int J = 0; J < q; J++)
		{
			int b, c;
			scanf("%d%d", &b, &c);
			int sum = 0;
			for (const auto &x : v[c - b + 1])
			{
				sum ^= psum[b + x.first] ^ psum[b + x.second + 1];
			}
			printf("%d\n", sum);
		}
	}
	return 0;
}
