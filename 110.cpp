#include <bits/stdc++.h>

using namespace std;

class ArrayList
{
public:
	int data[32], size;
	ArrayList();
	void push_back(int);
	int pop_head();
	void clear();
	void print();
	void swap(int, int);
};
ArrayList::ArrayList()
{
	size = 0;
}
void ArrayList::clear()
{
	size = 0;
}
void ArrayList::print()
{
	for (int i = 0; i < size - 1; ++i)
	{
		printf("%c,", data[i]);
	}
	printf("%c", data[size - 1]);
}
void ArrayList::swap(int x, int y)
{
	int tmp = data[x];
	data[x] = data[y];
	data[y] = tmp;
}
void ArrayList::push_back(int input)
{
	data[size++] = input;
}
int ArrayList::pop_head()
{
	int head = data[0];
	for (int i = 0; i < size; ++i)
	{
		data[i] = data[i + 1];
	}
	size--;
	return head;
}
void printSeq(char c, int length)
{
	for (int i = 0; i < length - 1; ++i)
	{
		printf("%c,", c + i);
	}
	printf("%c", c + length - 1);
}
void indent(int num)
{
	for (int i = 0; i < num; ++i)
		printf("  ");
}
void metaSort(ArrayList &ls, int insertChar, int bound)
{
	// termination condition
	if (insertChar == bound)
	{
		indent(insertChar - 'a');
		printf("writeln(");
		ls.print();
		printf(")\n");
		return;
	}
	ls.push_back(insertChar);// insert to tail
	indent(insertChar - 'a');
	printf("if %c < %c then\n", ls.data[ls.size - 2], ls.data[ls.size - 1]);
	metaSort(ls, insertChar + 1, bound);
	// next insert to every place
	for (int i = ls.size - 1; i > 0; --i)
	{
		ls.swap(i, i - 1);
		// -------------------------
		indent(insertChar - 'a');
		if (i == 1)
		{
			printf("else\n");
		}
		else
		{
			printf("else if %c < %c then\n", ls.data[i - 2], ls.data[i - 1]);
		}
		// -------------------------
		metaSort(ls, insertChar + 1, bound);
	}
	ls.pop_head();// delete head
}

int main()
{
	ArrayList ls;
	int times, max;
	scanf("%d", &times);
	for (int i = 0; i < times; ++i)
	{
		scanf("%d", &max);
		// --------------------
		printf("program sort(input,output);\nvar\n");
		printSeq('a', max);
		printf(" : integer;\nbegin\n  readln(");
		printSeq('a', max);
		printf(");\n");
		// --------------------
		ls.push_back('a');
		metaSort(ls, 'b', 'a' + max);
		ls.clear();
		// --------------------
		printf("end.\n");
		if (i != times - 1)
		{
			printf("\n");
		}
		// --------------------
	}
	return 0;
}
