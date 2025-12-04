#include <string>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    
    int x = 5;
    int y = 5;
    
    bool visited[11][11][4] = { false };
    
    for (char c : dirs)
    {
        int nx = x;
        int ny = y;
        int dir = 0;
        int r_dir = 0;
        
        if (c == 'U')
        {
            ny++;
            dir = 0;
            r_dir = 1;
        }
        else if (c == 'D')
        {
            ny--;
            dir = 1;
            r_dir = 0;
        }
        else if (c == 'R')
        {
            nx++;
            dir = 2;
            r_dir = 3;
        }
        else if (c == 'L')
        {
            nx--;
            dir = 3;
            r_dir = 2;
        }
        
        if (nx < 0 || nx > 10 || ny < 0 || ny > 10)
        {
            continue;
        }
        
        if (!visited[x][y][dir])
        {
            visited[x][y][dir] = true;
            visited[nx][ny][r_dir] = true;
            
            answer++;
        }
        
        x = nx;
        y = ny;
    }
    
    return answer;
}