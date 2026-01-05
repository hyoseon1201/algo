#include <bits/stdc++.h>

using namespace std;

struct Edge
{
	int u, v;
	long long w;

	bool operator<(const Edge& other) const { return w < other.w; }
};

struct Point
{
	int x, y;
};

int parent[2001];

void initUnionFind(int n)
{
	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
	}
}

int find(int x)
{
	if (parent[x] == x)
	{
		return x;
	}

	return parent[x] = find(parent[x]);
}

bool unite(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
	{
		parent[b] = a;
		return true;
	}
	return false;
}

long long getDistSQ(Point a, Point b)
{
	long long dx = a.x - b.x;
	long long dy = a.y - b.y;
	return dx * dx + dy * dy;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	long long c;
	
	cin >> n >> c;

	vector<Point> fields(n);

	for (int i = 0; i < n; i++)
	{
		cin >> fields[i].x >> fields[i].y;
	}

	vector<Edge> edges;
	edges.reserve(n * n / 2);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			long long dist = getDistSQ(fields[i], fields[j]);

			if (dist >= c)
			{
				edges.push_back({ i, j, dist });
			}
		}
	}

	sort(edges.begin(), edges.end());

	initUnionFind(n);
	long long totalCost = 0;
	int edgeCount = 0;

	for (const auto& edge : edges)
	{
		if (unite(edge.u, edge.v))
		{
			totalCost += edge.w;
			edgeCount++;

			if (edgeCount == n)
			{
				break;
			}
		}
	}

	if (edgeCount == n - 1)
	{
		cout << totalCost << "\n";
	}
	else
	{
		cout << -1 << "\n";
	}

	return 0;
}