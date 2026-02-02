#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int from, to, cost;
};

bool solve()
{
    int n, m, w;
    cin >> n >> m >> w;

    vector<Edge> edges;

    for (int i = 0; i < m; i++)
    {
        int s, e, t;
        cin >> s >> e >> t;
        edges.push_back({ s, e, t });
        edges.push_back({ e, s, t });
    }

    for (int i = 0; i < w; i++)
    {
        int s, e, t;
        cin >> s >> e >> t;
        edges.push_back({ s, e, -t });
    }

    vector<int> dist(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        for (auto& e : edges)
        {
            if (dist[e.to] > dist[e.from] + e.cost)
            {
                dist[e.to] = dist[e.from] + e.cost;
                if (i == n) return true;
            }
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    while (tc--)
    {
        if (solve())
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }

    return 0;
}