#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct Edge
{
    int to;
    int weight;
};

int n, m;
vector<Edge> adj[100001];
int dist[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int start, end, d;
        cin >> start >> end >> d;
        adj[start].push_back({ end, d });
    }

    int a, b;
    cin >> a >> b;

    fill(dist, dist + n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[a] = 0;
    pq.push({ 0, a });

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

    cout << dist[b] << "\n";

    return 0;
}