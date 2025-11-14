#include <string>
#include <vector>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    
    int vecSize = 0;
    for (int i = 0; i < elements.size(); i++)
    {
        vecSize += elements[i];
    }
    
    vector<int> checkVec(vecSize, 0);
    
    for (int i = 0; i < elements.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < elements.size(); j++)
        {
            int idx = (i + j) % elements.size();
            sum += elements[idx];
            checkVec[sum]++;
        }
    }
    
    for (int i = 0; i < checkVec.size(); i++)
    {
        if (checkVec[i] != 0)
        {
            answer++;
        }
    }
    
    answer++;
    
    return answer;
}