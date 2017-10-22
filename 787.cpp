#include <bits/stdc++.h>

using namespace std;

int numlen(int *arr)
{
	for (int i = 499; i >= 0; --i)
	{
		if (arr[i])
		{
			return i;
		}
	}
	return 0;
}

class Num
{
public:
	Num();
	char min[500], max[500], in[6];
	int num, digit;
	bool mp, Mp;
} *arr = NULL;

Num::Num()
{
	for (int i = 0; i < 500; ++i)
		min[i] = max[i] = 0;
	mp = Mp = true;
}

bool cmp(char *a, char *b)
{
	if (a[0] == '-')
		if (b[0] == '-')
			if (strlen(a) > strlen(b))
				return true;
			else if (strlen(a) < strlen(b))
				return false;
			else
				return (strcmp(a, b) > 0);
		else
			return true;
	else if (a[0] != '-')
		if (b[0] != '-')
			if (strlen(a) > strlen(b))
				return false;
			else if (strlen(a) < strlen(b))
				return true;
			else
				return (strcmp(a, b) < 0);
		else
			return false;
}

char *findmax(char *a, char *b, char *c)
{
	char *tmp[3] = {a, b, c};
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 2; ++j)
			if (cmp(tmp[j], tmp[j + 1]))
				swap(tmp[j], tmp[j + 1]);
	return tmp[0];
}

char *findmin(char *a, char *b, char *c)
{
	char *tmp[3] = {a, b, c};
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 2; ++j)
			if (cmp(tmp[j], tmp[j + 1]))
				swap(tmp[j], tmp[j + 1]);
	return tmp[2];
}

int main()
{
	int offset = -1;
	char in[10];
	while (cin >> in)
	{
		if (!arr)
			arr = new Num[100];
		if (strcmp(in, "-999999"))
		{
			strcpy(arr[++offset].in, in);
			arr[offset].num = atoi(in);
			reverse(arr[offset].in, arr[offset].in + strlen(arr[offset].in));
			arr[offset].digit = strlen(arr[offset].in);
			if (arr[offset].in[arr[offset].digit] == '-')
				--arr[offset].digit;
		}
		else
		{
			strcpy(arr[offset].min, arr[offset].in);
			strcpy(arr[offset].max, arr[offset].in);

			if (arr[offset].num < 0)
				arr[offset].min[strlen(arr[offset].min) - 1] = 0;
			if (arr[offset].num < 0)
				arr[offset].max[strlen(arr[offset].max) - 1] = 0;
			if (arr[offset].num < 0)
				arr[offset].mp = arr[offset].Mp = false;
			for (int i = offset - 1; i >= 0; --i)
			{
				bool ap = true, bp = true, cp = true;
				char a[600] = {0}, b[600] = {0}, c[600] = {0};
				int k, I[500] = {0}, M[500] = {0}, m[500] = {0};

				for (k = 0; isdigit(arr[i].in[k]); ++k)
					I[k] = arr[i].in[k] - '0';
				if (arr[i].in[strlen(arr[i].in) - 1] == '-')
					ap = false;
				if (!ap)
					*a = '-';
				for (int x = numlen(I); x >= 0; --x)
					a[x + (ap ? 0 : 1)] = I[x] + '0';
				reverse(a + (ap ? 0 : 1), a + strlen(a));
				for (k = 0; isdigit(arr[i + 1].min[k]); ++k)
					m[k] = (arr[i + 1].min[k] - '0') * abs(arr[i].num);
				for (k = 0; k < 500; ++k)
					if (m[k] > 9)
					{
						m[k + 1] += m[k] / 10;
						m[k] %= 10;
					}
				if ((arr[i].num < 0 ^ !arr[i + 1].mp) && arr[i].num)
					bp = false;
				if (!bp)
					*b = '-';
				for (int x = numlen(m); x >= 0; --x)
					b[x + (bp ? 0 : 1)] = m[x] + '0';
				reverse(b + (bp ? 0 : 1), b + strlen(b));

				for (k = 0; isdigit(arr[i + 1].max[k]); ++k)
					M[k] = (arr[i + 1].max[k] - '0') * abs(arr[i].num);
				for (k = 0; k < 500; ++k)
					if (M[k] > 9)
					{
						M[k + 1] += M[k] / 10;
						M[k] %= 10;
					}
				if ((arr[i].num < 0 ^ !arr[i + 1].Mp) && arr[i].num)
					cp = false;
				if (!cp)
					*c = '-';
				for (int x = numlen(M); x >= 0; --x)
					c[x + (cp ? 0 : 1)] = M[x] + '0';
				reverse(c + (cp ? 0 : 1), c + strlen(c));

				char *max = findmax(a, b, c), *min = findmin(a, b, c);
				strcpy(arr[i].min, min + (*min == '-' ? 1 : 0));
				strcpy(arr[i].max, max + (*max == '-' ? 1 : 0));
				reverse(arr[i].min, arr[i].min + strlen(arr[i].min));
				reverse(arr[i].max, arr[i].max + strlen(arr[i].max));
				if (*max == '-')
					arr[i].Mp = false;
				if (*min == '-')
					arr[i].mp = false;
			}

			for (int i = 0; i <= offset; ++i)
			{
				if (!arr[i].Mp)
					arr[i].max[strlen(arr[i].max)] = '-';
				reverse(arr[i].max, arr[i].max + strlen(arr[i].max));
			}

			char out[600] = {0};
			strcpy(out, arr[offset].max);
			for (int i = offset - 1; i >= 0; --i)
				if (cmp(out, arr[i].max))
					strcpy(out, arr[i].max);
			cout << out << endl;

			offset = -1;
			delete[] arr;
			arr = NULL;
		}
	}

	return 0;
}
