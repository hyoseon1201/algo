#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;
    string alpha = "AEIOU";
    int place[] = {781, 156, 31, 6, 1};
    
    for (int i = 0; i < word.size(); i++)
    {
        int idx = alpha.find(word[i]);
        answer += idx * place[i] + 1;
    }
    return answer;
}