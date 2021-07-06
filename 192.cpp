#include <bits/stdc++.h>

using namespace std;

typedef struct
{
	bool isSynch;
	int delay;
	int incomingConnections;
	bool removed;
	int totalDelay;
} NODE;
typedef struct
{
	int from;
	int to;
} CONNECTION;
void read_circuit();
void delete_circuit();
void analyze_circuit();
void propagate_delay(int node);
NODE *sNodes;
int sNumNodes;
CONNECTION *sConnections;
int sNumConnections;
int sClockPeriod;
int sMaxDelay;

int main()
{
	int numCircuits;
	int i;
	scanf("%d", &numCircuits);
	for (i = 0; i < numCircuits; i++)
	{
		read_circuit();
		analyze_circuit();
		delete_circuit();
	}
	return 0;
}

void read_circuit()
{
	char type[20];
	int i;
	/* read the clock period */
	scanf("%d", &sClockPeriod);
	/* read the number of nodes */
	scanf("%d", &sNumNodes);
	/* allocate the nodes */
	sNodes = (NODE *)malloc(sNumNodes * sizeof(NODE));
	for (i = 0; i < sNumNodes; i++)
	{
		/* read the type and delay of the node */
		scanf("%s %d", type, &sNodes[i].delay);
		sNodes[i].isSynch = (type[0] != 'a');
		sNodes[i].totalDelay = 0;
		sNodes[i].incomingConnections = 0;
		sNodes[i].removed = false;
	}
	/* read the number of connections */
	scanf("%d", &sNumConnections);
	/* allocate the connections */
	sConnections = (CONNECTION *)malloc(sNumConnections * sizeof(CONNECTION));
	for (i = 0; i < sNumConnections; i++)
	{
		scanf("%d %d", &sConnections[i].from, &sConnections[i].to);
	}
}

void delete_circuit()
{
	free(sNodes);
	free(sConnections);
}

void analyze_circuit()
{
	/*  search for cycles in the circuits */
	/*  Strategy: We count the number of incomingConnections connections for every node.
	  Then we remove all nodes without incomingConnections connections together with their
	  outgoing connections until no nodes are left (no cycles in the circuit) or
	  no further nodes can be removed (cycle in the circuit).
	  Synchronously working nodes always break a cycle and therefore don't count. */
	bool nodeRemoved;
	int numRemovedNodes;
	int i, j;
	/* count number of incomingConnections connections */
	for (i = 0; i < sNumConnections; i++)
	{
		int to = sConnections[i].to;
		if (!sNodes[to].isSynch)
		{
			sNodes[to].incomingConnections++;
		}
	}
	nodeRemoved = true;
	numRemovedNodes = 0;
	while (nodeRemoved) /* while a further node has been removed do ... */
	{
		nodeRemoved = false;
		for (i = 0; i < sNumNodes; i++) /* loop over all nodes */
		{
			if (!sNodes[i].removed && sNodes[i].incomingConnections == 0)
			{
				/* node has no incomingConnections connections => remove it */
				nodeRemoved = true;
				numRemovedNodes++;
				/* remove nodes */
				sNodes[i].removed = true;
				/* remove outgoing connections */
				for (j = 0; j < sNumConnections; j++)
				{
					int to = sConnections[j].to;
					if (sConnections[j].from == i && !sNodes[to].isSynch)
					{
						sNodes[to].incomingConnections--;
					}
				}
			}
		}
	}
	/* if all nodes have been removed, there are no cycles */
	if (numRemovedNodes != sNumNodes)
	{
		printf("Circuit contains cycle.\n");
		return;
	}
	/*  calculate delays */
	/*  Strategy: We start at all inputs and propagate recursively the delays until
	  we reach an output or a synchronous node. The outputs of synchronous nodes
	  are also considered as inputs. This algorithm will terminate because we
	  know there are no cycles. */
	sMaxDelay = 0;
	for (i = 0; i < sNumNodes; i++)
		if (sNodes[i].isSynch) /* start propagating the delays */
		{
			propagate_delay(i);
		}
	if (sMaxDelay > sClockPeriod)
	{
		printf("Clock period exceeded.\n");
	}
	else
	{
		printf("Synchronous design. Maximum delay: %d.\n", sMaxDelay);
	}
}

void propagate_delay(int i)
{
	int j;
	/* for all connections that lead from the current node to another one do ... */
	for (j = 0; j < sNumConnections; j++)
		if (sConnections[j].from == i)
		{
			/* calculate new delay and take the maximum of the new and old value */
			int to = sConnections[j].to;
			int newDelay = sNodes[i].totalDelay + sNodes[to].delay;
			if (newDelay > sNodes[to].totalDelay)
			{
				sNodes[to].totalDelay = newDelay;
				if (newDelay > sMaxDelay)
				{
					sMaxDelay = newDelay;
				}
				/* recursively propagte the new delay */
				if (!sNodes[to].isSynch)
				{
					propagate_delay(to);
				}
			}
		}
}
