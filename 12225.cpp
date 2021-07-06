#include <bits/stdc++.h>

using namespace std;

struct Catan
{
	struct Pos
	{
		int q, r;
		Pos operator+(const Pos &rhs) const
		{
			return {q + rhs.q, r + rhs.r};
		}
		void operator+=(const Pos &rhs)
		{
			q += rhs.q;
			r += rhs.r;
		}
		bool operator<(const Pos &rhs) const
		{
			return make_tuple(q, r) < make_tuple(rhs.q, rhs.r);
		}
	};
	enum Dir
	{
		N = 0,
		NW,
		SW,
		S,
		SE,
		NE,
		LENGTH
	};
	Catan(int N)
	{
		idx_kind_.reserve(N);
		add({0, 0}, 0);
		Pos pos = {0, 0};
		int side = 1;
		while (idx_kind_.size() < N)
		{
			pos += dirs_[NE];
			add(pos, get_kind(pos));
			for (const auto &dir : dirs_)
			{
				int c = &dir == &dirs_[0] ? side - 1 : side;
				for (int s = 0; s < c; ++s)
				{
					pos += dir;
					add(pos, get_kind(pos));
				}
			}
			side++;
		}
	}
	int get_kind_for_idx(int i)
	{
		return idx_kind_[i - 1] + 1;
	}
	void add(const Pos &p, int kind)
	{
		int i = idx_kind_.size();
		idx_kind_.push_back(kind);
		pos_idx_[p] = i;
		cnts_[kind]++;
	}
	int get_kind(const Pos &p)
	{
		bool kinds[5] = {true, true, true, true, true};
		for (const auto &dir : dirs_)
		{
			auto iter = pos_idx_.find(p + dir);
			if (iter != pos_idx_.end())
			{
				kinds[idx_kind_[iter->second]] = false;
			}
		}
		int kind = -1, cnt;
		for (int t = 0; t < 5; ++t)
		{
			if (!kinds[t])
			{
				continue;
			}
			if (kind == -1 || cnts_[t] < cnt)
			{
				kind = t;
				cnt = cnts_[t];
			}
		}
		return kind;
	}
	array<Pos, LENGTH> dirs_ = {{{0, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 0}, {1, -1}}};
	map<Pos, int> pos_idx_;
	vector<int> idx_kind_;
	int cnts_[5] = {0, 0, 0, 0, 0};
};

int main()
{
	Catan cat(10000);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int i;
		scanf("%d", &i);
		printf("%d\n", cat.get_kind_for_idx(i));
	}
	return 0;
}
