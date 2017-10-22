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
struct ci_char_traits : public std::char_traits<char>
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
	T result;
	if (!(interpreter << arg) || !(interpreter >> result) || !(interpreter >> std::ws).eof())
	{
		throw logic_error("bad lexical_cast");
	}
	return result;
}

typedef vector<string> vs;
typedef vector<int> vi;
typedef std::basic_string<char, ci_char_traits> ci_string;

struct coord
{
	int x_, y_;
	double angle_;
	coord(int x, int y) : x_(x), y_(y), angle_(atan2(static_cast<double>(y), static_cast<double>(x)))
	{
		if (angle_ < 0)
		{
			angle_ += M_PI + M_PI;
		}
	}
};

bool operator<(const coord &a, const coord &b)
{
	return a.angle_ < b.angle_;
}

int main()
{
	int n;
	while (cin >> n, n)
	{
		vector<coord> coords;
		while (n--)
		{
			int a, b, c;
			cin >> a >> b >> c;
			coords.push_back(coord(a - c, b - c));
		}
		sort(coords.begin(), coords.end());
		bool succ(true);
		for (vector<coord>::const_iterator i(coords.begin()), ie(coords.end()); succ && (i + 1) != ie; ++i)
			if (fmod((i + 1)->angle_ - i->angle_, M_PI + M_PI) > M_PI)
			{
				succ = false;
			}
		if (fmod(coords.begin()->angle_ + M_PI + M_PI - coords.rbegin()->angle_, M_PI + M_PI) > M_PI)
		{
			succ = false;
		}
		printf(succ ? "Yes\n" : "No\n");
	}
	return 0;
}
