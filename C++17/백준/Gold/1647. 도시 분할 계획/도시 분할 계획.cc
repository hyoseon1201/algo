#include <bits/stdc++.h>

using namespace std;

int n, m;

struct Edge
{
	int u, v;
	long long w;
	
	bool operator<(const Edge& other) const { return w < other.w; }
};

int parent[100001];

void initParent(int n)
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	vector<Edge> edges;

	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		edges.push_back({ u, v, w });
	}

	sort(edges.begin(), edges.end());

	initParent(n);

	int totalCost = 0;
	int maxCost = 0;

	for (const auto& edge : edges)
	{
		if (unite(edge.u, edge.v))
		{
			totalCost += edge.w;

			maxCost = edge.w;
		}
	}

	cout << totalCost - maxCost << "\n";

	return 0;
}