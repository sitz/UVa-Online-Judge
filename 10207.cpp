#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 69
#define MAX_VALUE 1000000000
#define MAX_DIGIT "9"
#define MAX_DIGIT_ 9

struct BCD_Type
{
	unsigned data[MAX_SIZE];

	int get_left()
	{
		for (int i = MAX_SIZE - 1; i > 0; i--)
			if (data[i])
			{
				break;
			}
		return i;
	}

	void carry()
	{
		int i;
		for (i = 0; i < MAX_SIZE - 1; i++)
		{
			data[i + 1] += data[i] / MAX_VALUE, data[i] %= MAX_VALUE;
		}
		data[i] %= MAX_VALUE;
	}

	BCD_Type()
	{
	}
	BCD_Type(const BCD_Type &a)
	{
		memcpy(data, a.data, MAX_SIZE * sizeof(unsigned));
	}
	BCD_Type(unsigned a)
	{
		memset(data, 0, MAX_SIZE * sizeof(unsigned));
		data[0] = a % MAX_VALUE;
		a /= MAX_VALUE;
		data[1] = a % MAX_VALUE;
		a /= MAX_VALUE;
		data[2] = a % MAX_VALUE;
		a /= MAX_VALUE;
	}

	//ADD
	BCD_Type &operator+=(unsigned n)//O(n)
	{
		data[0] += n % MAX_VALUE;
		n /= MAX_VALUE;
		data[1] += n;
		carry();
		return *this;
	}
	BCD_Type &operator+=(BCD_Type &n)//O(n)
	{
		int i, carry = 0;
		for (i = 0; i < MAX_SIZE; i++)
		{
			data[i] += n.data[i] + carry,
					carry = data[i] / MAX_VALUE,
					data[i] %= MAX_VALUE;
		}
		return *this;
	}

	void print()
	{
		int i = get_left();
		printf("%u", data[i]);
		while (--i >= 0)
		{
			printf("%0" MAX_DIGIT "u", data[i]);
		}
	}
};

bool ok[1024][1024];//init=false
double val[1024][1024];
double p, q;

void P(int i, int j)
{
	if (ok[i][j])
	{
		return;
	}
	ok[i][j] = true;
	if (i == 0)
	{
		val[i][j] = 1;
		return;
	}
	if (j == 0)
	{
		val[i][j] = 0;
		return;
	}
	P(i - 1, j);
	P(i, j - 1);
	val[i][j] = p * val[i - 1][j] + q * val[i][j - 1];
	return;
}

BCD_Type recur[2][1024];

struct InputStruct
{
	double p;
	vector<int> pos;
};

vector<InputStruct> input;
map<int, BCD_Type> res;

int main()
{
	memset(ok, 0, 1024 * 1024);
	int maxx = 1, maxy = 1;
	char line[128];
	while (gets(line))
	{
		InputStruct t;
		t.p = atof(strtok(line, " \t"));
		int n = atoi(strtok(NULL, " \t"));
		if (n == 0)
		{
			continue;
		}
		while (--n >= 0)
		{
			int y, x;
			gets(line);
			char *yy = strtok(line, " \t");
			char *xx = strtok(NULL, " \t");
			y = atoi(yy);
			x = atoi(xx);
			maxx = max(maxx, x);
			maxy = max(maxy, y);
			t.pos.push_back((y << 16) | x);
			ok[y][x] = true;
		}
		input.push_back(t);
	}

	// init mk tbl
	BCD_Type one(1);
	recur[0][0] = one;
	for (int x = 1; x <= maxx; x++)
	{
		recur[0][x] = one;
	}
	int now = 1, prev = 0;
	for (int y = 1; y <= maxy; y++)
	{
		recur[now][0] = one;
		for (int x = 1; x <= maxx; x++)
		{
			recur[now][x] = recur[prev][x];
			recur[now][x] += recur[now][x - 1];
			if (ok[y][x])
			{
				res[(y << 16) | x] = recur[now][x];
			}
			recur[now][x] += 1;
		}
		now ^= 1, prev ^= 1;
	}

	// proc input
	for (int c = 0; c < input.size(); c++)
	{
		memset(ok, 0, 1024 * 1024);
		p = input[c].p;
		q = 1 - p;
		if (c)
		{
			printf("\n");
		}
		vector<int> &pos = input[c].pos;
		for (int n = 0; n < pos.size(); n++)
		{
			if (pos[n] == 0)
			{
				printf("-1.00000\n0\n");
				continue;
			}
			int i = pos[n] >> 16, j = pos[n] & 0xffff;
			if (i == 0)
			{
				printf("1.00000\n0\n");
				continue;
			}
			if (j == 0)
			{
				printf("0.00000\n0\n");
				continue;
			}
			P(i, j);
			printf("%.5f\n", val[i][j]);
			res[pos[n]].print();
			printf("\n");
		}
	}
	return 0;
}
