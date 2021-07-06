#include <bits/stdc++.h>

using namespace std;

#define CLR() (state = 0, first = second = "")

const int MAX_LENGTH = 333;

struct Complex;
typedef Complex *ComplexPointer;
ComplexPointer ptr[26];

char buf[MAX_LENGTH];
int total_nodes;
set<int> visited, stk;

struct Complex
{
	static const int STRING = 0;
	static const int DICT = 1;

	int data_type, id;
	string str;
	map<string, ComplexPointer> dict;

	Complex()
	{
		data_type = DICT;
		id = total_nodes++;
	}

	Complex(const string &s)
	{
		data_type = STRING;
		str = s;
		id = total_nodes++;
	}

	int length() const
	{
		return (int)dict.size();
	}

	ComplexPointer &operator[](const string &s)
	{
		if (!dict.count(s))
		{
			dict[s] = new Complex;
		}
		return dict[s];
	}

	void add_pair(const string &first, const ComplexPointer &second)
	{
		dict[first] = second;
	}
};

inline int id(char x)
{
	return x - 'a';
}

ComplexPointer new_dict(int s, int t)
{
	static vector<string> que_str;
	static vector<ComplexPointer> que_ptr;
	string first, second;
	int state = 0;
	que_str.clear();
	que_ptr.clear();
	for (; s < t; s++)
	{
		if (buf[s] == '{')
		{
			que_str.push_back(first);
			que_ptr.push_back(new Complex);
			CLR();
		}
		else if (buf[s] == '}')
		{
			if (state == 1)
			{
				que_ptr.back()->add_pair(first, new Complex(second));
				CLR();
			}
			ComplexPointer ptr = que_ptr.back();
			que_ptr.pop_back();
			if (que_ptr.empty())
			{
				return ptr;
			}
			que_ptr.back()->add_pair(que_str.back(), ptr);
			que_str.pop_back();
		}
		else if (buf[s] == ',')
		{
			if (state == 1)
			{
				que_ptr.back()->add_pair(first, new Complex(second));
				CLR();
			}
		}
		else if (buf[s] == ':')
		{
			state = 1;
		}
		else
		{
			state == 0 ? first += buf[s] : second += buf[s];
		}
	}
	return que_ptr.front();
}

ComplexPointer &parse_reference(int s, int t)
{
	if (s + 1 == t)
	{
		return ptr[id(buf[s])];
	}
	ComplexPointer now = ptr[id(buf[s++])];
	while (s < t)
	{
		int l = s + 1, r = s + 1;
		for (; buf[r] != ']'; r++)
			;
		if (r + 1 == t)
		{
			return (*now)[string(buf + l, buf + r)];
		}
		else
		{
			now = (*now)[string(buf + l, buf + r)];
			s = r + 1;
		}
	}
}

ComplexPointer parse(int s, int t)
{
	if (buf[s] == '{')
	{
		return new_dict(s, t);
	}
	else if (buf[s] == '\'' || isdigit(buf[s]) || buf[s] == '-')
	{
		return new Complex(string(buf + s, buf + t));
	}
	else
	{
		return parse_reference(s, t);
	}
}

bool dfs(ComplexPointer ptr)
{
	visited.insert(ptr->id);
	stk.insert(ptr->id);
	for (__typeof(ptr->dict.begin()) itr = ptr->dict.begin(); itr != ptr->dict.end(); itr++)
	{
		if (!visited.count(itr->second->id) && dfs(itr->second))
		{
			return true;
		}
		else if (stk.count(itr->second->id))
		{
			return true;
		}
	}
	stk.erase(ptr->id);
	return false;
}

int test(ComplexPointer ptr)
{
	visited.clear();
	stk.clear();
	return dfs(ptr);
}

int main()
{
	for (int i = 0; i < 26; i++)
	{
		ptr[i] = new Complex;
	}

	while (gets(buf))
	{
		int l = strlen(buf), m = 0;
		for (int i = 0; i < l; i++)
		{
			if (buf[i] != ' ')
			{
				buf[m++] = buf[i];
			}
		}
		l = m;
		if (l >= 4 && string(buf, buf + 4) == "test")
		{
			printf("%d\n", test(parse(5, l - 1)));
		}
		else if (l >= 6 && string(buf, buf + 6) == "length")
		{
			printf("%d\n", parse(7, l - 1)->length());
		}
		else
		{
			for (int i = 0; i < l; i++)
			{
				if (buf[i] == '=')
				{
					parse_reference(0, i) = parse(i + 1, l);
					break;
				}
			}
		}
	}
	return 0;
}
