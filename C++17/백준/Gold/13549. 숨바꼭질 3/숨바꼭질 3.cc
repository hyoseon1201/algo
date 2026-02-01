#include <bits/stdc++.h>

using namespace std;

int n, k;
int dist[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(dist, dist + 100001, 1e9);

    cin >> n >> k;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[n] = 0;
    pq.push({ 0, n });

    while (!pq.empty())
    {
        int time = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < time) continue;

        if (cur == k)
        {
            cout << time << "\n";
            return 0;
        }

        // 순간이동시 범위 벗어나지도 않고, 도착했을때 최단거리라면 갱신
        if (cur * 2 < 100001 && dist[cur * 2] > time)
        {
            dist[cur * 2] = time;
            pq.push({ time, cur * 2 });
        }

        if (cur + 1 < 100001 && dist[cur + 1] > time + 1)
        {
            dist[cur + 1] = time + 1;
            pq.push({ time + 1, cur + 1 });
        }

        if (cur - 1 >= 0 && dist[cur - 1] > time + 1)
        {
            dist[cur - 1] = time + 1;
            pq.push({ time + 1, cur - 1 });
        }
    }

    return 0;
}