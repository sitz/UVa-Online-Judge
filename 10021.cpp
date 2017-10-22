#include <bits/stdc++.h>

using namespace std;

/*
 *   +------+
 * / UP    /|
 * +------+ |
 * |FRONT |R+ -----------------
 * |      |/  board
 * +------+ -----------------
 */
#define FRONT 0
#define BACK 1
#define UP 2
#define DOWN 3
#define LEFT 4
#define RIGHT 5

__inline void roll_left(short *cube);
__inline void roll_right(short *cube);
__inline void roll_up(short *cube);
__inline void roll_down(short *cube);

short cube_start[6] = {1, 2, 3, 4, 5, 6};

struct Pos
{
	int x;
	int y;

	bool operator==(Pos &pos)
	{
		if (this->x == pos.x && this->y == pos.y)
		{
			return true;
		}
		return false;
	}
};

struct Node
{
	bool operator==(Node &node)
	{
		if (pos == node.pos && 0 == memcmp(node.cube, cube, 6 * sizeof(short)))
		{
			return true;
		}
		return false;
	}
	short cube[6];
	Pos pos;
	unsigned int prev_node;
};

struct Cell
{
	Cell();
	vector<unsigned int> used_node;

	//
	// 0: no wall
	// 1: down wall
	// 2: right wall
	// 3: down and right wall
	//
	short wall;
};

struct Case
{
	Case();
	int search_move_num();
	bool find_used_node(Node &node);
	void insert_used_node(Pos &pos, unsigned int index);
	void show_path(Node &node);

	vector<Node> node_list;
	int row;
	int col;
	Pos start;
	Pos end;
	vector<vector<Cell>> board;
	bool showflg;
};

int Case::search_move_num()
{
	vector<unsigned int> expand_list;
	int move_count = 0;
	Node first_node;
	first_node.pos = start;
	first_node.prev_node = 0xffffffff;
	memcpy(first_node.cube, cube_start, 6 * sizeof(short));
	node_list.push_back(first_node);
	insert_used_node(first_node.pos, 0);
	expand_list.push_back(node_list.size() - 1);
	while (expand_list.size() != 0)
	{
		vector<unsigned int> tmp_node_list;
		move_count++;
		for (int i = 0; i < expand_list.size(); i++)
		{
			Node cur_expand_node = node_list[expand_list[i]];
			bool expand = true;
			if (cur_expand_node.pos.x == 8 && cur_expand_node.pos.y == 0)
			{
				show_path(cur_expand_node);
			}
			// move left
			if (cur_expand_node.pos.y > 0 && !(board[cur_expand_node.pos.x][cur_expand_node.pos.y - 1].wall & 0x02))
			{
				if (cur_expand_node.prev_node != -1)
				{
					Node prev_node = node_list[cur_expand_node.prev_node];
					if (prev_node.pos.y == cur_expand_node.pos.y - 1 && prev_node.pos.x == cur_expand_node.pos.x)
					{
						expand = false;
					}
				}
				if (expand)
				{
					Node tmp_node = cur_expand_node;
					tmp_node.pos.y--;
					roll_left(tmp_node.cube);
					tmp_node.prev_node = expand_list[i];
					if (tmp_node.pos == end && tmp_node.cube[DOWN] == cube_start[DOWN])
					{
						cout << move_count << endl;
						return move_count;
					}
					if (!find_used_node(tmp_node))
					{
						node_list.push_back(tmp_node);
						tmp_node_list.push_back(node_list.size() - 1);
						insert_used_node(tmp_node.pos, node_list.size() - 1);
					}
				}
			}
			expand = true;
			// move right
			if (cur_expand_node.pos.y < col - 1 && !(board[cur_expand_node.pos.x][cur_expand_node.pos.y].wall & 0x02))
			{
				if (cur_expand_node.prev_node != -1)
				{
					Node prev_node = node_list[cur_expand_node.prev_node];
					if (prev_node.pos.y == cur_expand_node.pos.y + 1 && prev_node.pos.x == cur_expand_node.pos.x)
					{
						expand = false;
					}
				}
				if (expand)
				{
					Node tmp_node = cur_expand_node;
					tmp_node.pos.y++;
					roll_right(tmp_node.cube);
					tmp_node.prev_node = expand_list[i];
					if (tmp_node.pos == end && tmp_node.cube[DOWN] == cube_start[DOWN])
					{
						cout << move_count << endl;
						return move_count;
					}
					if (!find_used_node(tmp_node))
					{
						node_list.push_back(tmp_node);
						tmp_node_list.push_back(node_list.size() - 1);
						insert_used_node(tmp_node.pos, node_list.size() - 1);
					}
				}
			}
			// move up
			expand = true;
			if (cur_expand_node.pos.x > 0 && !(board[cur_expand_node.pos.x - 1][cur_expand_node.pos.y].wall & 0x01))
			{
				if (cur_expand_node.prev_node != -1)
				{
					Node prev_node = node_list[cur_expand_node.prev_node];
					if (prev_node.pos.y == cur_expand_node.pos.y && prev_node.pos.x == cur_expand_node.pos.x - 1)
					{
						expand = false;
					}
				}
				if (expand)
				{
					Node tmp_node = cur_expand_node;
					tmp_node.pos.x--;
					roll_up(tmp_node.cube);
					tmp_node.prev_node = expand_list[i];
					if (tmp_node.pos == end && tmp_node.cube[DOWN] == cube_start[DOWN])
					{
						cout << move_count << endl;
						return move_count;
					}
					if (!find_used_node(tmp_node))
					{
						node_list.push_back(tmp_node);
						tmp_node_list.push_back(node_list.size() - 1);
						insert_used_node(tmp_node.pos, node_list.size() - 1);
					}
				}
			}
			// move down
			expand = true;
			if (cur_expand_node.pos.x < row - 1 && !(board[cur_expand_node.pos.x][cur_expand_node.pos.y].wall & 0x01))
			{
				if (cur_expand_node.prev_node != -1)
				{
					Node prev_node = node_list[cur_expand_node.prev_node];
					if (prev_node.pos.y == cur_expand_node.pos.y && prev_node.pos.x == cur_expand_node.pos.x + 1)
					{
						expand = false;
					}
				}
				if (expand)
				{
					Node tmp_node = cur_expand_node;
					tmp_node.pos.x++;
					roll_down(tmp_node.cube);
					tmp_node.prev_node = expand_list[i];
					if (tmp_node.pos == end && tmp_node.cube[DOWN] == cube_start[DOWN])
					{
						cout << move_count << endl;
						return move_count;
					}
					if (!find_used_node(tmp_node))
					{
						node_list.push_back(tmp_node);
						tmp_node_list.push_back(node_list.size() - 1);
						insert_used_node(tmp_node.pos, node_list.size() - 1);
					}
				}
			}
		}
		expand_list = tmp_node_list;
	}
	cout << "No solution" << endl;
	return 0;
}

int main()
{
	int case_num = 0;
	Case cs;
	char line_buffer[10] = "";
	cin >> case_num;
	for (; case_num > 0; case_num--)
	{
		// input board size
		cs.node_list.clear();
		cin >> cs.row >> cs.col;
		cs.board = vector<vector<Cell>>(cs.row, vector<Cell>(cs.col, Cell()));
		cin >> cs.start.x >> cs.start.y;
		cin >> cs.end.x >> cs.end.y;
		cs.start.x--;
		cs.start.y--;
		cs.end.x--;
		cs.end.y--;
		char wall_type = ' ';
		Pos wall_pos;
		cin.getline(line_buffer, 10);
		while (1)
		{
			cin.getline(line_buffer, 10);
			if (cin.eof() || line_buffer[0] == '\0')
			{
				break;
			}
			if (line_buffer[0] == 'v' || line_buffer[0] == 'h')
			{
				wall_type = line_buffer[0];
				continue;
			}
			else
			{
				stringstream ss;
				ss << line_buffer;
				ss >> wall_pos.x >> wall_pos.y;
				wall_pos.x--;
				wall_pos.y--;
				switch (wall_type)
				{
				case 'v':
					cs.board[wall_pos.x][wall_pos.y].wall |= 0x01;
					break;
				case 'h':
					cs.board[wall_pos.x][wall_pos.y].wall |= 0x02;
					break;
				default:
					cout << "Wrong input" << endl;
					exit(1);
				}
			}
		}
		cs.search_move_num();
		if (case_num != 1)
		{
			cout << endl;
		}
	}
	return 0;
}

__inline void roll_left(short *cube)
{
	short old_left = cube[LEFT];
	cube[LEFT] = cube[UP];
	cube[UP] = cube[RIGHT];
	cube[RIGHT] = cube[DOWN];
	cube[DOWN] = old_left;
}

__inline void roll_right(short *cube)
{
	short old_left = cube[LEFT];
	cube[LEFT] = cube[DOWN];
	cube[DOWN] = cube[RIGHT];
	cube[RIGHT] = cube[UP];
	cube[UP] = old_left;
}

__inline void roll_up(short *cube)
{
	short old_up = cube[UP];
	cube[UP] = cube[FRONT];
	cube[FRONT] = cube[DOWN];
	cube[DOWN] = cube[BACK];
	cube[BACK] = old_up;
}

__inline void roll_down(short *cube)
{
	short old_up = cube[UP];
	cube[UP] = cube[BACK];
	cube[BACK] = cube[DOWN];
	cube[DOWN] = cube[FRONT];
	cube[FRONT] = old_up;
}

Case::Case()
{
	row = 0;
	col = 0;
	showflg = false;
}

Cell::Cell()
{
	wall = 0;
}

bool Case::find_used_node(Node &node)
{
	Cell cell = board[node.pos.x][node.pos.y];
	for (int i = 0; i < cell.used_node.size(); i++)
	{
		if (node == node_list[cell.used_node[i]])
		{
			return true;
		}
	}
	return false;
}

void Case::insert_used_node(Pos &pos, unsigned int index)
{
	board[pos.x][pos.y].used_node.push_back(index);
}

void Case::show_path(Node &node)
{
	if (showflg)
	{
		cout << '(' << node.pos.x << ',' << node.pos.y << ')' << '\t';
		for (int i = 0; i < 6; i++)
		{
			cout << node.cube[i];
		}
		cout << endl;
		unsigned int prev = node.prev_node;
		cout << '(' << node.pos.x << ',' << node.pos.y << ')' << endl;
		while (prev != 0xffffffff)
		{
			Node prev_node = node_list[prev];
			cout << '(' << prev_node.pos.x << ',' << prev_node.pos.y << ')' << '\t';
			for (int i = 0; i < 6; i++)
			{
				cout << prev_node.cube[i];
			}
			cout << endl;
			prev = prev_node.prev_node;
		}
		cout << endl;
	}
}
