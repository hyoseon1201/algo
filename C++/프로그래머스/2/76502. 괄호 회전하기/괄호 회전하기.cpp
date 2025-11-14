#include <string>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

bool isValid(string& s)
{
    stack<char> st;
    map<char, char> mp = 
    {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'}
    };
    
    for (char c : s)
    {
        if (mp.count(c))
        {
            st.push(c);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            
            if (mp[st.top()] == c)
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    
    return st.empty();
}

int solution(string s) {
    int answer = 0;
    
    int n = s.length();
    
    for (int i = 0; i < n; i++)
    {
        string rotated = s;
        rotate(rotated.begin(), rotated.begin() + i, rotated.end());
        
        if (isValid(rotated))
        {
            answer++;
        }
    }
    
    return answer;
}