#include <bits/stdc++.h>

using namespace std;

struct Node
{
	char digits[25];
	int len;
	void operator=(Node a)
	{
		strcpy(this->digits, a.digits);
		this->len = a.len;
	}
	bool operator>(Node &a)
	{
		if (this->len > a.len)
		{
			return true;
		}
		else if ((this->len == a.len) && (strcmp(this->digits, a.digits) > 0))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator<(Node &a)
	{
		if (this->len < a.len)
		{
			return true;
		}
		else if ((this->len == a.len) && (strcmp(this->digits, a.digits) < 0))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
Node heap[50000];
int size;
void insert(Node newnode)
{
	for (int i = 1; i <= size; i++)
		if (strcmp(newnode.digits, heap[i].digits) == 0)
		{
			return;
		}
	int k = ++size;
	while (k != 1 && newnode > heap[k / 2])
	{
		heap[k] = heap[k / 2];
		k /= 2;
	}
	heap[k] = newnode;
}
void vertify(int m)
{
	int k = m;
	if (2 * m <= size && heap[2 * m] > heap[m])
	{
		k = 2 * m;
	}
	if (2 * m + 1 <= size && heap[2 * m + 1] > heap[k])
	{
		k = 2 * m + 1;
	}
	if (k != m)
	{
		Node temp = heap[k];
		heap[k] = heap[m];
		heap[m] = temp;
		vertify(k);
	}
}
Node deleteMax()
{
	Node p = heap[1];
	heap[1] = heap[size--];
	vertify(1);
	return p;
}
bool isempty()
{
	return size == 0;
}
bool check(Node p)
{
	if (strcmp(p.digits, "0") == 0)
	{
		return true;
	}
	int s, i;
	s = 0;
	for (i = 0; i < p.len; i++)
	{
		s = (s * 10 + p.digits[i] - '0') % 3;
	}
	if (s == 0)
	{
		return false;
	}
	s = 0;
	for (i = 0; i < p.len; i++)
	{
		s = (s * 10 + p.digits[i] - '0') % 7;
	}
	if (s == 0)
	{
		return false;
	}
	for (i = 0; i < p.len; i++)
		if (p.digits[i] == '3' || p.digits[i] == '7')
		{
			return false;
		}
	for (i = 0; i < p.len; i++)
	{
		int j;
		for (j = i + 1; p.digits[j] == p.digits[i]; j++)
			;
		if (j - i == 3 || j - i == 7)
		{
			return false;
		}
	}
	return true;
}
void check3(Node u)
{
	char temp[25];
	int carry = 0;
	int i;
	for (i = 0; i < u.len; i++)
	{
		int t = u.digits[i] - '0' + carry * 10;
		carry = t % 3;
		temp[i] = (t / 3) + '0';
	}
	if (carry)
	{
		return;
	}
	temp[u.len] = 0;
	for (i = 0; i < u.len; i++)
		if (temp[i] != '0')
		{
			break;
		}
	Node v;
	strcpy(v.digits, temp + i);
	v.len = strlen(temp + i);
	insert(v);
}
void check7(Node u)
{
	char temp[25];
	int carry = 0;
	int i;
	for (i = 0; i < u.len; i++)
	{
		int t = u.digits[i] - '0' + carry * 10;
		carry = t % 7;
		temp[i] = (t / 7) + '0';
	}
	if (carry)
	{
		return;
	}
	temp[u.len] = 0;
	for (i = 0; i < u.len; i++)
		if (temp[i] != '0')
		{
			break;
		}
	Node v;
	strcpy(v.digits, temp + i);
	v.len = strlen(temp + i);
	insert(v);
}
void BFS(Node start)
{
	char temp[25];
	size = 0;
	insert(start);
	Node u, v;
	int i, j, k;
	while (!isempty())
	{
		u = deleteMax();
		/*puts(u.digits);*/
		if (check(u))
		{
			printf("%s\n", u.digits);
			return;
		}
		check3(u);
		check7(u);
		for (i = 0; i < u.len; i++)
		{
			if (u.digits[i] == '3')
			{
				int p = 0;
				for (j = 0; j < i; j++)
				{
					temp[p++] = u.digits[j];
				}
				for (j = i + 1; j < u.len; j++)
				{
					temp[p++] = u.digits[j];
				}
				temp[p] = 0;
				if (strcmp(temp, "") == 0)
				{
					strcpy(temp, "0");
				}
				Node v;
				strcpy(v.digits, temp);
				v.len = strlen(temp);
				insert(v);
			}
			if (u.digits[i] == '7')
			{
				int p = 0;
				for (j = 0; j < i; j++)
				{
					temp[p++] = u.digits[j];
				}
				for (j = i + 1; j < u.len; j++)
				{
					temp[p++] = u.digits[j];
				}
				temp[p] = 0;
				Node v;
				if (strcmp(temp, "") == 0)
				{
					strcpy(temp, "0");
				}
				strcpy(v.digits, temp);
				v.len = strlen(temp);
				insert(v);
			}
			for (j = i + 1; u.digits[j] == u.digits[i]; j++)
				;
			if (j - i >= 7)
			{
				int p = 0;
				for (k = 0; k < i; k++)
				{
					temp[p++] = u.digits[k];
				}
				for (k = i + 7; k < u.len; k++)
				{
					temp[p++] = u.digits[k];
				}
				temp[p] = 0;
				Node v;
				if (strcmp(temp, "") == 0)
				{
					strcpy(temp, "0");
				}
				strcpy(v.digits, temp);
				v.len = strlen(temp);
				insert(v);
			}
			if (j - i >= 3)
			{
				int p = 0;
				for (k = 0; k < i; k++)
				{
					temp[p++] = u.digits[k];
				}
				for (k = i + 3; k < u.len; k++)
				{
					temp[p++] = u.digits[k];
				}
				temp[p] = 0;
				Node v;
				if (strcmp(temp, "") == 0)
				{
					strcpy(temp, "0");
				}
				strcpy(v.digits, temp);
				v.len = strlen(temp);
				insert(v);
			}
		}
	}
}
int main()
{
	int times;
	char str[25];
	scanf("%d", &times);
	for (; times; times--)
	{
		scanf("%s", str);
		Node temp;
		strcpy(temp.digits, str);
		temp.len = strlen(str);
		BFS(temp);
	}
	return 0;
}
