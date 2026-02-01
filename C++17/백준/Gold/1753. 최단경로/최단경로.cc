#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct Edge
{
    int to;
    int weight;
};

int V, E, K;
int dist[20001];
vector<Edge> adj[20001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> K;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
    }

    fill(dist, dist + V + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[K] = 0;
    pq.push({ 0, K });

    while (!pq.empty())
    {
        int d = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < d) continue;

        for (auto& edge : adj[cur])
        {
            int next = edge.to;
            int nextDist = d + edge.weight;

            if (nextDist < dist[next])
            {
                dist[next] = nextDist;
                pq.push({ nextDist, next });
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INF)
        {
            cout << "INF\n";
        }
        else
        {
            cout << dist[i] << "\n";
        }
    }

    return 0;
}