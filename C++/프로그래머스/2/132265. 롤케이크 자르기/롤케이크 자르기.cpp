#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    int n = topping.size();
    
    unordered_map<int, int> rightMap;
    for (int t : topping)
    {
        rightMap[t]++;
    }
    
    unordered_map<int, int> leftMap;
    
    for (int i = 0; i < n - 1; i++)
    {
        int currentTopping = topping[i];
        
        leftMap[currentTopping]++;
        
        rightMap[currentTopping]--;
        
        if (rightMap[currentTopping] == 0)
        {
            rightMap.erase(currentTopping);
        }
        
        if (leftMap.size() == rightMap.size())
        {
            answer++;
        }
    }
    
    return answer;
}