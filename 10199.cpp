#include <bits/stdc++.h>

using namespace std;

#define NAME_LEN 50
#define MAX_NODES 200
#define MAX_EDGES (MAX_NODES * MAX_NODES * 2)
#define HASHTABLE_SIZE 237
#define WHITE 0
#define GRAY 1
#define BLACK 2

struct Edge;
struct Node
{
	int num;
	char name[NAME_LEN + 1];
	Node *next;
	Edge *edges;
	Node *parent;
	int color, children, d;
	bool articulation;
};
struct Edge
{
	Node *node;
	Edge *next;
};

Node nodes[MAX_NODES], *tbl[HASHTABLE_SIZE], *sorted[MAX_NODES];
Edge edges[MAX_EDGES];

int n, free_edge, time_;

int hash_(char *s)
{
	unsigned h = 0;
	while (*s)
	{
		h = h * 31 + *s++;
	}
	return h % HASHTABLE_SIZE;
}

void put_to_hash_tbl(char *name, Node *node)
{
	int i = hash_(name);
	node->next = tbl[i];
	tbl[i] = node;
}

Node *find_node(char *name)
{
	Node *p = tbl[hash_(name)];
	while (p)
	{
		if (!strcmp(name, p->name))
		{
			return p;
		}
		p = p->next;
	}
	return p;
}

void read_names()
{
	for (int i = 0; i < HASHTABLE_SIZE; i++)
	{
		tbl[i] = NULL;
	}
	for (int i = 0; i < n; i++)
	{
		Node *node = &nodes[i];
		node->num = i;
		node->color = WHITE;
		node->articulation = false;
		node->edges = NULL;
		node->d = 0;
		node->children = 0;
		node->parent = NULL;
		scanf("%s", node->name);
		put_to_hash_tbl(node->name, node);
	}
}

void add_edge(Node *src, Node *dest)
{
	Edge *edge = &edges[free_edge++];
	edge->node = dest;
	edge->next = src->edges;
	src->edges = edge;
}

void read_roads()
{
	int r;
	char name1[NAME_LEN + 1], name2[NAME_LEN + 1];
	free_edge = 0;
	scanf("%d", &r);
	for (int i = 0; i < r; i++)
	{
		scanf("%s %s", name1, name2);
		Node *node1 = find_node(name1);
		Node *node2 = find_node(name2);
		add_edge(node1, node2);
		add_edge(node2, node1);
	}
}

int dfs_visit(Node *u)
{
	u->color = GRAY;
	u->d = ++time_;
	int ret = u->d;
	for (Edge *e = u->edges; e; e = e->next)
	{
		Node *v = e->node;
		if (v->color == WHITE)
		{
			v->parent = u;
			int r = dfs_visit(v);
			u->children++;
			if (r < ret)
			{
				ret = r;
			}
			if (u->d <= r)
			{
				u->articulation = true;
			}
		}
		else if (v->color == GRAY && u->parent != v)
		{
			if (v->d < ret)
			{
				ret = v->d;
			}
		}
	}
	u->color = BLACK;
	return ret;
}

void dfs()
{
	time_ = 0;
	for (int i = 0; i < n; i++)
	{
		Node *u = &nodes[i];
		if (u->color == WHITE)
		{
			dfs_visit(u);
			u->articulation = (u->children > 1);
		}
	}
}

int compare(Node **node1, Node **node2)
{
	return strcmp((*node1)->name, (*node2)->name);
}

void print_solution()
{
	int cameras = 0;
	for (int i = 0; i < n; i++)
	{
		Node *node = &nodes[i];
		if (!node->articulation)
		{
			continue;
		}
		sorted[cameras++] = node;
	}
	qsort(sorted, cameras, sizeof(Node *), (int (*)(const void *, const void *))compare);
	printf("%d camera(s) found\n", cameras);
	for (int i = 0; i < cameras; i++)
	{
		printf("%s\n", sorted[i]->name);
	}
}

int main()
{
	int count = 0;
	while (scanf("%d", &n) == 1)
	{
		if (n <= 0)
		{
			break;
		}
		read_names();
		read_roads();
		if (count > 0)
		{
			putchar('\n');
		}
		printf("City map #%d: ", ++count);
		dfs();
		print_solution();
	}
	return 0;
}
