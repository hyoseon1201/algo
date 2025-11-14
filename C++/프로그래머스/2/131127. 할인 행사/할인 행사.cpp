#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    int n = discount.size();

    for (int startIndex = 0; startIndex <= n - 10; ++startIndex) 
    {
        vector<int> tempNumber = number;

        for (int i = startIndex; i < startIndex + 10; ++i) 
        {
            auto it = find(want.begin(), want.end(), discount[i]);
            if (it != want.end()) 
            {
                int idx = distance(want.begin(), it);
                tempNumber[idx]--;
            }
        }

        bool canBuyAll = all_of(tempNumber.begin(), tempNumber.end(), [](int x) { return x <= 0; });
        if (canBuyAll) 
        {
            answer++;
        }
    }
    return answer;
}