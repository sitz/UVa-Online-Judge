#include <bits/stdc++.h>

using namespace std;

typedef set<pair<int, int>> Cities;
typedef map<int, Cities> Routes;

struct Node
{
	int _remPlanes;
	int _city;
	int _accCost;

	Node(int city, int planes, int cost) : _city(city), _remPlanes(planes), _accCost(cost)
	{
	}
};

struct NodeCmp
{
	bool operator()(const Node &lhs, const Node &rhs) const
	{
		return lhs._accCost < rhs._accCost;
	}
};

int findCost(int oCity, int dCity, Routes &trainRoutes, Routes &planeRoutes, int maxPlanes)
{
	Node startNode(oCity, maxPlanes, 0);

	multiset<Node, NodeCmp> openedNodes;
	openedNodes.insert(startNode);

	set<pair<int, int>> visitedStates;

	while (!openedNodes.empty())
	{
		const Node n = *openedNodes.begin();
		openedNodes.erase(openedNodes.begin());

		if (n._city == dCity)
		{
			return n._accCost;
		}

		pair<int, int> s(n._city, n._remPlanes);

		if (visitedStates.find(s) == visitedStates.end())
		{
			visitedStates.insert(s);

			if (n._remPlanes > 0)
			{
				const Cities &cities = planeRoutes[n._city];

				for (auto it = cities.begin(); it != cities.end(); ++it)
				{
					Node n2(it->first, n._remPlanes - 1, it->second + n._accCost);
					openedNodes.insert(n2);
				}
			}

			const Cities &cities = trainRoutes[n._city];

			for (auto it = cities.begin(); it != cities.end(); ++it)
			{
				Node n2(it->first, n._remPlanes, it->second + n._accCost);
				openedNodes.insert(n2);
			}
		}
	}

	return -1;
}

int main()
{
	int cases = 0;
	cin >> cases;

	int numCities = 0;
	int oCity = 0;
	int dCity = 0;
	int maxPlanes = 0;
	int numTrainRoutes = 0;
	int numPlaneRoutes = 0;

	Routes trainRoutes;
	Routes planeRoutes;

	while (cases--)
	{
		trainRoutes.clear();
		planeRoutes.clear();

		cin >> numCities;
		cin >> oCity >> dCity;
		cin >> maxPlanes;
		cin >> numTrainRoutes;

		for (int i = 0; i < numTrainRoutes; ++i)
		{
			int c1, c2, time;
			cin >> c1 >> c2 >> time;
			trainRoutes[c1].insert(make_pair(c2, time));
			trainRoutes[c2].insert(make_pair(c1, time));
		}

		cin >> numPlaneRoutes;

		for (int i = 0; i < numPlaneRoutes; ++i)
		{
			int c1, c2, time;
			cin >> c1 >> c2 >> time;
			planeRoutes[c1].insert(make_pair(c2, time));
			planeRoutes[c2].insert(make_pair(c1, time));
		}

		cout << findCost(oCity, dCity, trainRoutes, planeRoutes, maxPlanes) << endl;
	}

	return 0;
}
