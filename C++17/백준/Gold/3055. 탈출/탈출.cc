#include <bits/stdc++.h>

using namespace std;

int R, C;
pair<int, int> startPos, endPos;
char arr[51][51];
queue<pair<int, int>> dotchi_q;
queue<pair<int, int>> water_q;
int dist[51][51];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    memset(dist, -1, sizeof(dist));

    for (int i = 0; i < R; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < C; j++)
        {
            arr[i][j] = line[j];
            if (arr[i][j] == 'S')
            {
                startPos = { i, j };
                dotchi_q.push({ i, j });
                dist[i][j] = 0;
            }
            else if (arr[i][j] == 'D') 
            {
                endPos = { i, j };
            }
            else if (arr[i][j] == '*') 
            {
                water_q.push({ i, j });
            }
        }
    }

    while (!dotchi_q.empty())
    {
        // 물 bfs
        int waterSize = water_q.size();
        while (waterSize--)
        {
            pair<int, int> cur = water_q.front();
            water_q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if (nx >= 0 && nx < R && ny < C && ny >= 0)
                {
                    if (arr[nx][ny] == '.')
                    {
                        arr[nx][ny] = '*';
                        water_q.push({ nx, ny });
                    }
                }
            }
        }

        // 도치 bfs
        int dotchiSize = dotchi_q.size();
        while (dotchiSize--)
        {
            pair<int, int> cur = dotchi_q.front();
            dotchi_q.pop();

            if (cur.first == endPos.first && cur.second == endPos.second)
            {
                cout << dist[cur.first][cur.second] << "\n";
                return 0;
            }

            for (int i = 0; i < 4; i++)
            {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if (nx >= 0 && nx < R && ny < C && ny >= 0 && dist[nx][ny] == -1)
                {
                    if (arr[nx][ny] == '.' || arr[nx][ny] == 'D')
                    {
                        dist[nx][ny] = dist[cur.first][cur.second] + 1;
                        dotchi_q.push({ nx, ny });
                    }
                }
            }
        }
    }

    cout << "KAKTUS" << "\n";

    return 0;
}