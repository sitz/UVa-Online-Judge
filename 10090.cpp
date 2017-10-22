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

typedef unsigned long ul;
typedef long long ll;
typedef vector<string> vs;
typedef vector<int> vi;
typedef std::basic_string<char, ci_char_traits> ci_string;

pair<ll, ll> extended_gcd(ll a, ll b)
{
	if (a % b == 0)
	{
		return make_pair(0, 1);
	}
	else
	{
		pair<ll, ll> temp(extended_gcd(b, a % b));
		return make_pair(temp.second, temp.first - temp.second * (a / b));
	}
}

pair<ll, ll> extended_gcd_2(ll a, ll b)
{
	ll x(0), y(1), lastx(1), lasty(0);
	while (b != 0)
	{
		ll temp(b);
		ll quotient(a / b);
		b = a % b;
		a = temp;
		temp = x;
		x = lastx - quotient * x;
		lastx = temp;
		temp = y;
		y = lasty - quotient * y;
		lasty = temp;
	}
	return make_pair(lastx, lasty);
}

int main()
{
	ll n;
	while (scanf("%lld", &n) == 1, n)
	{
		ll c1, n1, c2, n2;
		cin >> c1 >> n1 >> c2 >> n2;
		pair<ll, ll> res(extended_gcd(n1, n2));
		ll gcd(res.first * n1 + res.second * n2);
		ll lcm((n1 * n2) / gcd);
		if (0 == n % gcd)
		{
			n /= gcd;
			lcm /= gcd;
			n1 /= gcd;
			n2 /= gcd;
		}
		else
		{
			cout << "failed" << endl;
			continue;
		}
		ll n1_delta(lcm / n1);
		ll n2_delta(lcm / n2);
		ll t_n1(res.first), t_n2(res.second);
		// overflow the UL to chk `extended_gcd`
		t_n1 *= n;
		t_n2 *= n;
		if (t_n1 < 0)
		{
			ll steps((0 - t_n1) / n1_delta);
			t_n1 += steps * n1_delta;
			t_n2 -= steps * n2_delta;
			if (t_n1 < 0)
			{
				t_n1 += n1_delta;
				t_n2 -= n2_delta;
			}
			ll cand_cost(t_n1 * c1 + t_n2 * c2);
			ll t_t_n1(t_n1 + n1_delta);
			ll t_t_n2(t_n2 - n2_delta);
			ll t_cand_cost(t_t_n1 * c1 + t_t_n2 * c2);
			if (t_cand_cost < cand_cost && t_t_n2 >= 0)
			{
				ll more_steps(t_n2 / n2_delta);
				t_n2 -= more_steps * n2_delta;
				t_n1 += more_steps * n1_delta;
			}
		}
		else if (t_n2 < 0)
		{
			ll steps((0 - t_n2) / n2_delta);
			t_n1 -= steps * n1_delta;
			t_n2 += steps * n2_delta;
			if (t_n2 < 0)
			{
				t_n1 -= n1_delta;
				t_n2 += n2_delta;
			}
			ll cand_cost(t_n1 * c1 + t_n2 * c2);
			ll t_t_n1(t_n1 - n1_delta);
			ll t_t_n2(t_n2 + n2_delta);
			ll t_cand_cost(t_t_n1 * c1 + t_t_n2 * c2);
			if (t_cand_cost < cand_cost && t_t_n1 >= 0)
			{
				ll more_steps(t_n1 / n1_delta);
				t_n1 -= more_steps * n1_delta;
				t_n2 += more_steps * n2_delta;
			}
		}
		else
		{
			{
				ll cand_cost(t_n1 * c1 + t_n2 * c2);
				ll t_t_n1(t_n1 + n1_delta);
				ll t_t_n2(t_n2 - n2_delta);
				ll t_cand_cost(t_t_n1 * c1 + t_t_n2 * c2);
				if (t_cand_cost < cand_cost && t_t_n2 >= 0)
				{
					ll more_steps(t_n2 / n2_delta);
					t_n2 -= more_steps * n2_delta;
					t_n1 += more_steps * n1_delta;
				}
			}
			{
				ll cand_cost(t_n1 * c1 + t_n2 * c2);
				ll t_t_n1(t_n1 - n1_delta);
				ll t_t_n2(t_n2 + n2_delta);
				ll t_cand_cost(t_t_n1 * c1 + t_t_n2 * c2);
				if (t_cand_cost < cand_cost && t_t_n1 >= 0)
				{
					ll more_steps(t_n1 / n1_delta);
					t_n1 -= more_steps * n1_delta;
					t_n2 += more_steps * n2_delta;
				}
			}
		}
		if (t_n1 < 0 || t_n2 < 0)
		{
			printf("failed\n");
			continue;
		}
		else
		{
			cout << t_n1 << " " << t_n2 << endl;
		}
	}
	return 0;
}
