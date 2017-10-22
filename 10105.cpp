#include <bits/stdc++.h>

using namespace std;

// @ http://www.ddj.com/cpp/184403801
template <class T>
struct StringTok
{
	StringTok(const T &seq, typename T::size_type pos = 0) : seq_(seq), pos_(pos) {}
	T operator()(const T &delim);

	const T &seq_;
	typename T::size_type pos_;
};

template <class T>
T StringTok<T>::operator()(const T &delim)
{
	T token;
	if (pos_ != T::npos)
	{
		// start of found token
		typename T::size_type first(seq_.find_first_not_of(delim.c_str(), pos_));
		if (first != T::npos)
		{
			// length of found token
			typename T::size_type num(seq_.find_first_of(delim.c_str(), first) - first);
			// do all the work off to the side
			token = seq_.substr(first, num);
			// done; now commit using
			// nonthrowing operations only
			pos_ = first + num;
			if (pos_ != T::npos)
			{
				++pos_;
			}
			if (pos_ >= seq_.size())
			{
				pos_ = T::npos;
			}
		}
	}
	return token;
}

// @ http://www.gotw.ca/gotw/029.htm for case-insensitive lexicographic compares
struct ci_char_traits : public char_traits<char>
{
	static bool eq(char c1, char c2)
	{
		return toupper(c1) == toupper(c2);
	}
	static bool ne(char c1, char c2)
	{
		return toupper(c1) != toupper(c2);
	}
	static bool lt(char c1, char c2)
	{
		return toupper(c1) < toupper(c2);
	}
	static int compare(const char *s1, const char *s2, size_t n)
	{
		return strncasecmp(s1, s2, n);
	}
	static const char *find(const char *s, int n, char a)
	{
		while (n-- > 0 && toupper(*s) != toupper(a))
		{
			++s;
		}
		return s;
	}
};

// no boost makes c++ angry; lexical cast comes in handy for string <=> int conversion without expliucitly writing out the streams all the time.
template <typename T, typename S>
T lexical_cast(const S &arg)
{
	stringstream interpreter;
	T res;
	if (!(interpreter << arg) || !(interpreter >> res) || !(interpreter >> ws).eof())
	{
		throw logic_error("bad lexical_cast");
	}
	return res;
}

typedef vector<string> vs;
typedef vector<int> vi;
typedef basic_string<char, ci_char_traits> ci_string;

int fact(int n)
{
	int res(1);
	for (int i(1); i <= n; i++)
	{
		res *= i;
	}
	return res;
}

int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		int prod(1);
		for (int i(0); i < k; ++i)
		{
			int temp;
			cin >> temp;
			prod *= fact(temp);
		}
		cout << (fact(n) / prod) << endl;
	}
	return 0;
}
