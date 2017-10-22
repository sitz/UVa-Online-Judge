#include <bits/stdc++.h>

using namespace std;

struct DieType
{
	int face[6];
	void Up()
	{
		int temp = face[0];
		face[0] = face[1];
		face[1] = face[2];
		face[2] = face[3];
		face[3] = temp;
	}
	void Down()
	{
		int temp = face[0];
		face[0] = face[3];
		face[3] = face[2];
		face[2] = face[1];
		face[1] = temp;
	}
	void Left()
	{
		int temp = face[0];
		face[0] = face[5];
		face[5] = face[2];
		face[2] = face[4];
		face[4] = temp;
	}
	void Right()
	{
		int temp = face[0];
		face[0] = face[4];
		face[4] = face[2];
		face[2] = face[5];
		face[5] = temp;
	}
};

const DieType InitialDie[6][6] =
		{
				{{1, 1, 0, 0, 0, 0},
				 {1, 2, 6, 5, 4, 3},
				 {1, 3, 6, 4, 2, 5},
				 {1, 4, 6, 3, 5, 2},
				 {1, 5, 6, 2, 3, 4},
				 {1, 6, 0, 0, 0, 0}},
				{{2, 1, 5, 6, 3, 4},
				 {2, 2, 0, 0, 0, 0},
				 {2, 3, 5, 4, 6, 1},
				 {2, 4, 5, 3, 1, 6},
				 {2, 5, 0, 0, 0, 0},
				 {2, 6, 5, 1, 4, 3}},
				{{3, 1, 4, 6, 5, 2},
				 {3, 2, 4, 5, 1, 6},
				 {3, 3, 0, 0, 0, 0},
				 {3, 4, 0, 0, 0, 0},
				 {3, 5, 4, 2, 6, 1},
				 {3, 6, 4, 1, 2, 5}},
				{{4, 1, 3, 6, 2, 5},
				 {4, 2, 3, 5, 6, 1},
				 {4, 3, 0, 0, 0, 0},
				 {4, 4, 0, 0, 0, 0},
				 {4, 5, 3, 2, 1, 6},
				 {4, 6, 3, 1, 5, 2}},
				{{5, 1, 2, 6, 4, 3},
				 {5, 2, 0, 0, 0, 0},
				 {5, 3, 2, 4, 1, 6},
				 {5, 4, 2, 3, 6, 1},
				 {5, 5, 0, 0, 0, 0},
				 {5, 6, 2, 1, 3, 4}},
				{{6, 1, 0, 0, 0, 0},
				 {6, 2, 1, 5, 3, 4},
				 {6, 3, 1, 4, 5, 2},
				 {6, 4, 1, 3, 2, 5},
				 {6, 5, 1, 2, 4, 3},
				 {6, 6, 0, 0, 0, 0}}};

void (DieType::*Move[4])() = {&DieType::Up, &DieType::Down, &DieType::Left, &DieType::Right};

int Map[10][10];
bool Used_[10][10][6][6];
int H, W;
char MapName[21];

struct PointType
{
	int r, c;

	PointType operator+(const PointType &a) const
	{
		PointType out(a);
		out.r += r;
		out.c += c;
		return out;
	}

	bool Legal() const
	{
		return 0 <= r && r < H && 0 <= c && c < W;
	}
};

const PointType Directory[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

inline bool Used(const PointType &pos, const DieType &state)
{
	if (Used_[pos.r][pos.c][state.face[0] - 1][state.face[1] - 1])
	{
		return true;
	}
	Used_[pos.r][pos.c][state.face[0] - 1][state.face[1] - 1] = true;
	return false;
}

struct
{
	PointType pos;
	DieType state;
} Stack[3700];

bool DFS(int d)
{
	if (d != 0 && Stack[d].pos.r == Stack[0].pos.r && Stack[d].pos.c == Stack[0].pos.c)
	{
		for (int i = 0; i <= d; ++i)
		{
			if (i % 9 == 0)
			{
				cout << "  ";
			}
			else
			{
				cout << ',';
			}
			cout << '(' << Stack[i].pos.r + 1 << ',' << Stack[i].pos.c + 1 << ')';
			if (i % 9 == 8 && i != d)
			{
				cout << ',' << endl;
			}
		}
		cout << endl;
		return true;
	}
	for (int dir = 0; dir < 4; ++dir)
	{
		Stack[d + 1].pos = Stack[d].pos + Directory[dir];
		if (!Stack[d + 1].pos.Legal())
		{
			continue;
		}
		int &now_map = Map[Stack[d + 1].pos.r][Stack[d + 1].pos.c];
		if (now_map == -1 || now_map == Stack[d].state.face[0])
		{
			Stack[d + 1].state = Stack[d].state;
			(Stack[d + 1].state.*Move[dir])();
			if (Used(Stack[d + 1].pos, Stack[d + 1].state))
			{
				continue;
			}
			if (DFS(d + 1))
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	while (true)
	{
		cin >> MapName;
		if (strcmp(MapName, "END") == 0)
		{
			break;
		}
		int up, front;
		cin >> H >> W >> Stack[0].pos.r >> Stack[0].pos.c >> up >> front;
		for (int i = 0; i < H; ++i)
			for (int j = 0; j < W; ++j)
			{
				cin >> Map[i][j];
				for (int k = 0; k < 6; ++k)
					for (int l = 0; l < 6; ++l)
					{
						Used_[i][j][k][l] = false;
					}
			}
		--Stack[0].pos.r;
		--Stack[0].pos.c;
		Stack[0].state = InitialDie[up - 1][front - 1];
		cout << MapName << endl;
		if (!DFS(0))
		{
			cout << "  No Solution Possible" << endl;
		}
	}
}
