#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {

    unordered_map<string, int> cnt;
    for (auto& cloth : clothes)
    {
        string type = cloth[1];
        cnt[type]++;
    }
    
    int answer = 1;
    for(auto& [type, count] : cnt)
    {
        answer *= (count + 1);
    }
    
    return answer - 1;
}