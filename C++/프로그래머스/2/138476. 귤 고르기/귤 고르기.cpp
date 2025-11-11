#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    unordered_map<int, int> count_map;
    for (int t : tangerine) {
        count_map[t]++;
    }

    vector<int> counts;
    for (auto& p : count_map) {
        counts.push_back(p.second);
    }

    sort(counts.begin(), counts.end(), greater<int>());

    for (int c : counts) {
        k -= c;
        answer++;
        if (k <= 0) break;
    }

    return answer;
}
