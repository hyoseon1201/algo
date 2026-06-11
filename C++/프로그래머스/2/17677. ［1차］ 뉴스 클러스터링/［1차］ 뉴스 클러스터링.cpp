#include <string>
#include <vector>
#include <cctype>
#include <map>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    
    vector<string> arr1 = {};
    vector<string> arr2 = {};
    
    // 대,소문자 차이 무시 처리
    for (int i = 0; i < str1.length(); i++)
    {
        str1[i] = tolower(str1[i]);
    }
    
    for (int i = 0; i < str2.length(); i++)
    {
        str2[i] = tolower(str2[i]);
    }
    
    // 집합 A, B 만들기
    for (int i = 0; i < str1.length() - 1; i++)
    {
        if (isalpha(str1[i]) && isalpha(str1[i+1]))
        {
            arr1.push_back(str1.substr(i, 2));   
        }
    }
    
    for (int i = 0; i < str2.length() - 1; i++)
    {
        if (isalpha(str2[i]) && isalpha(str2[i+1]))
        {
            arr2.push_back(str2.substr(i, 2));   
        }
    }
    
    // 합집합, 교집합 만들기
    map<string, int> countA;
    map<string, int> countB;
    
    for (auto& cur : arr1)
    {
        countA[cur]++;
    }
    
    for (auto& cur : arr2)
    {
        countB[cur]++;
    }
    
    int inter = 0;
    int uni = 0;
    
    for (auto& pair : countA)
    {
        string key = pair.first;
        inter += min(countA[key], countB[key]);
        uni += max(countA[key], countB[key]);
    }
    
    for (auto& pair : countB)
    {
        string key = pair.first;
        if (countA[key] == 0 && countB[key] != 0)
        {
            uni += countB[key];
        }
    }
    
    if (uni == 0)
    {
        answer = 1;
        answer *= 65536;
        return answer;
    }
    
    float zakard = (float)inter / uni;
    zakard *= 65536;
    answer = zakard;
    
    return answer;
}