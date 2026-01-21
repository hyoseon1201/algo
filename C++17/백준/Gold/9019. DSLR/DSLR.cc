#include <bits/stdc++.h>

using namespace std;

int t;
bool visited[10000];
int parent[10000];
char cmd[10000];

void bfs(int start, int target)
{
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    memset(cmd, 0, sizeof(cmd));

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        if (current == target) break;

        int nextNum;

        nextNum = (current * 2) % 10000;
        if (!visited[nextNum])
        {
            visited[nextNum] = true;
            parent[nextNum] = current;
            cmd[nextNum] = 'D';
            q.push(nextNum);
        }

        nextNum = (current == 0) ? 9999 : current - 1;
        if (!visited[nextNum]) 
        {
            visited[nextNum] = true;
            parent[nextNum] = current;
            cmd[nextNum] = 'S';
            q.push(nextNum);
        }

        nextNum = (current % 1000) * 10 + (current / 1000);
        if (!visited[nextNum])
        {
            visited[nextNum] = true;
            parent[nextNum] = current;
            cmd[nextNum] = 'L';
            q.push(nextNum);
        }

        nextNum = (current % 10) * 1000 + (current / 10);
        if (!visited[nextNum])
        {
            visited[nextNum] = true;
            parent[nextNum] = current;
            cmd[nextNum] = 'R';
            q.push(nextNum);
        }
    }

    string result = "";
    int temp = target;

    while (temp != start)
    {
        result += cmd[temp];
        temp = parent[temp];
    }

    reverse(result.begin(), result.end());
    cout << result << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 테스트 케이스의 수 입력
    cin >> t;

    while (t--)
    {
        // 초기값과 최종값 입력
        int a, b;
        cin >> a >> b;
        bfs(a, b);
    }

    return 0;
}