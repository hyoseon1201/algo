#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    for (int i = 0; i < progresses.size(); i++)
    {
        int remain = 100 - progresses[i];
        int days = remain / speeds[i];
        if (remain % speeds[i] != 0) days++;
        q.push(days);
    }
    
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        int count = 1;
        
        while (!q.empty() && q.front() <= current)
        {
            count++;
            q.pop();
        }
        
        answer.push_back(count);
    }
    
    return answer;
}