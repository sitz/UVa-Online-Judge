#include <bits/stdc++.h>

using namespace std;

int numOfCase;
char str[30];
int str_index;

class MyString
{
public:
	char buffer[30];
	int len;

public:
	MyString();
	MyString(char *p);
	void Insert(int k, char alpha);
	void Print()
	{
		cout << buffer << endl;
	}
};

MyString::MyString()
{
	memset(buffer, 0, sizeof(buffer));
	len = 0;
}

MyString::MyString(char *p)
{
	strcpy(buffer, p);
	len = strlen(p);
}

void MyString::Insert(int k, char alpha)
{
	if (k > len)
	{
		return;
	}
	int i;
	buffer[len + 1] = '\0';
	for (i = len; i > k; i--)
	{
		buffer[i] = buffer[i - 1];
	}
	buffer[k] = alpha;
	len++;
}

MyString Solve(int th, int num)
{
	if (th == 1)
	{
		char temp[3];
		temp[0] = str[0];
		temp[1] = '\0';
		MyString ms(temp);
		return ms;
	}
	int a, b;
	a = (int)ceil(num * 1.0 / th);
	b = num % th;
	if (!b)
	{
		b += th;
	}
	MyString ms = Solve(th - 1, a);
	ms.Insert(b - 1, str[th - 1]);
	return ms;
}

int main()
{
	cin >> numOfCase;
	while (numOfCase--)
	{
		cin >> str >> str_index;
		int len = strlen(str);
		MyString ms = Solve(len, str_index);
		ms.Print();
	}
	return 0;
}
