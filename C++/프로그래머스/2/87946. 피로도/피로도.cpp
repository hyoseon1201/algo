#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int k, vector<vector<int>>& dungeons, vector<bool>& visited, int count)
{
    answer = max(answer, count);
    
    for (int i = 0; i < dungeons.size(); i++)
    {
        if (!visited[i] && k >= dungeons[i][0]) // 가지 않은 던전이고, 현재 k값이 입장요구 충족할때
        {
            visited[i] = true;
            dfs(k - dungeons[i][1], dungeons, visited, count + 1); // 소모 피로도 빼주고, 방문던전횟수 늘려주면서 재귀
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> visited(dungeons.size(), false);
    dfs(k, dungeons, visited, 0);
    return answer;
}