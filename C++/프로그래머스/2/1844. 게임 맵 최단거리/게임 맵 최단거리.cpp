#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int solution(vector<vector<int>> maps)
{
    int n = maps.size();
    int m = maps[0].size();
    queue<tuple<int, int, int>> q;
    vector<vector<int>> visited(n, vector<int>(m, -1));
    
    q.push({0, 0, 0});
    visited[0][0] = 0;
    
    while (!q.empty())
    {
        auto [y, x, d] = q.front();
        q.pop();
        
        if (x == m - 1 && y == n - 1)
        {
            return d + 1;
        }
        
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nd = d + 1;
            
            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
            {
                continue;
            }
            
            if (maps[ny][nx] == 0)
            {
                continue;
            }
            
            if (visited[ny][nx] == -1)
            {
                visited[ny][nx] = nd;
                q.push({ny, nx, nd});
            }
        }
    }
    
    return -1;
}