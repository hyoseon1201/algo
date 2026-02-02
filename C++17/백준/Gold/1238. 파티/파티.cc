#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int N, M, X;

vector<int> dijkstra(int start, const vector<vector<pair<int, int>>>& adj) {
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int d = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < d) continue;

        for (auto& edge : adj[cur]) {
            int next = edge.first;
            int nextDist = d + edge.second;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({ nextDist, next });
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> X;

    vector<vector<pair<int, int>>> adj(N + 1);
    vector<vector<pair<int, int>>> rev_adj(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({ v, t });
        rev_adj[v].push_back({ u, t }); // 방향을 뒤집어서 저장
    }

    // 1. X번 마을에서 각 마을로 돌아오는 최단 거리 (정방향 그래프)
    vector<int> dist_back = dijkstra(X, adj);

    // 2. 각 마을에서 X번 마을로 가는 최단 거리 (역방향 그래프에서 X부터 시작)
    vector<int> dist_go = dijkstra(X, rev_adj);

    int max_time = 0;
    for (int i = 1; i <= N; i++) {
        if (dist_go[i] != INF && dist_back[i] != INF) {
            max_time = max(max_time, dist_go[i] + dist_back[i]);
        }
    }

    cout << max_time << endl;

    return 0;
}