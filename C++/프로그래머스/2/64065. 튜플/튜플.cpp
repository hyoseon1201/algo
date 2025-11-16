#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    vector<vector<int>> arr;
    vector<int> tempVec;
    string temp = "";
    bool isNumber = false;
    
    for (int i = 1; i < s.length() - 1; i++)
    {
        if (s[i] == '{') // 여는 괄호일때
        {
            tempVec.clear();
            temp = "";
            isNumber = false;
        }
        else if (s[i] == '}') // 닫는 괄호일때
        {
            if (!temp.empty()) // 마지막에 있던 숫자 마저 tempVec에 넣어줌
            {
                tempVec.push_back(stoi(temp));
                temp = "";
            }
            arr.push_back(tempVec); // 어레이에 tempVec 통째로 넣어주기
            isNumber = false;
        }
        else if (s[i] == ',')
        {
            if (isNumber)
            {
                tempVec.push_back(stoi(temp));
                temp = "";
                isNumber = false;
            }
        }
        else
        {
            temp += s[i];
            isNumber = true;
        }
    }
    
    sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b)
         {
            return a.size() < b.size(); 
         });
    
    for (auto& v : arr)
    {
        for (int n : v)
        {
            if (find(answer.begin(), answer.end(), n) == answer.end())
            {
                answer.push_back(n);
            }
        }
    }
    
    return answer;
}